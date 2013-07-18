#include <iostream>
#include <cstdlib>
#include <vector>
#include "PCB.h"
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

//创建block存放（优先级，所需cpu时间，PCB）
struct block {
  block(int pri, int cpu, PCB* p):
    prior(pri), cputime(cpu), pointer(p) { }
  friend ostream& operator<<(ostream&, block&); //重载<<输出block内容
  int prior;
  int cputime;
  PCB* pointer;
};

ostream& operator<<(ostream& os, block& b)
{
  os << b.pointer->get_id() << '\t' << '\t' 
     << b.prior << '\t' << '\t'
     << b.cputime << '\t' << '\t';
  return os;
}

typedef vector<block>::iterator iter_block; //指向vector<block>的迭代器
void priority(int N)
{
  cout <<"Proc ID" << '\t' << '\t' << "Priority" 
       << '\t' << '\t' << "CPU TIME" << endl << endl;
  srand((unsigned)time(NULL)); //随机数
  int priority, cpu_time;
  vector<block> vec;

  //
  for(int i = 0; i != N; ++i)
    {
      priority = rand() % 10; //优先权
      cpu_time = 1 + rand() % 20; //所需CPU时间
      struct block queue_block(priority, cpu_time, new PCB(i));
      vec.push_back(queue_block);
    }

  //进程初始化输出
  iter_block iter;
  cout << "各进程的初始状态" << endl;
  cout << "-----------------------------------------------" << endl; 
  for(iter = vec.begin(); iter != vec.end(); ++iter)
    cout << *iter << endl;
 //    cout << iter->pointer->get_id() << '\t' << '\t' << *iter << endl << endl;
  cout << "-----------------------------------------------" << endl;
  //遍历vec，找出优先级最高的进程
  iter_block temp_iter;
  bool flag = true;
  while(flag) {
    temp_iter = vec.begin();
    for(iter = vec.begin(); iter != vec.end(); ++iter)
      {
	if(temp_iter->prior < iter->prior) //数值越大，优先级越高
	  temp_iter = iter;
      }
    temp_iter->prior -= 3; //优先级-3
    temp_iter->cputime -= 1; //时间-1
   
    cout << endl;
    for(iter = vec.begin(); iter != vec.end(); ++iter)
      cout << *iter << endl;
    //      cout << iter->pointer->get_id() << '\t' << '\t' << *iter << endl;
    if(temp_iter->cputime == 0)
      {
       	cout << "************";
	cout << " Process " << temp_iter->pointer->get_id() << " finished! " ;
	cout << "************" << endl;
       	delete temp_iter->pointer; //释放new的内存
	vec.erase(temp_iter); //移除已完成的进程
      }
    //移除完毕即进程全部执行完毕
    if(vec.begin() == vec.end())
      flag = false;
  }
}
