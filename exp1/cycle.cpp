#include <iostream>
#include <cstdlib>
#include <vector>
#include "PCB.h"
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

//创建结构体，存放（轮转时间片，所需时间片，已占用时间片, PCB)
//即(ask_time, need_time, use_time, PCB)
//时间片均为整数
struct block_1 {
  block_1(unsigned ask, unsigned need, unsigned use, PCB* p):
    ask_time(ask), need_time(need), used_time(use), pointer(p) { }
  friend ostream& operator<<(ostream&, block_1&);
  unsigned ask_time;
  unsigned need_time;
  unsigned used_time;
  PCB *pointer;
};

ostream& operator<<(ostream& os, block_1& b)
{
  os << b.pointer->get_id() << '\t' << '\t'
     << b.ask_time << '\t' << '\t'
     << b.need_time << '\t' << '\t'
     << b.used_time;
  return os;
}

typedef vector<block_1>::iterator iter_block_1;
void cycle(int N)
{
  srand((unsigned)time(NULL)); //随机数
  unsigned ask_time, use_time = 0;
  unsigned need_time;
  vector<block_1> vec;

  //生成N个进程并存入vec中
  for(int i = 0; i != N; ++i)
    {
      ask_time = rand() % 10; //优先权
      need_time = rand() % 10 + 1; //所需CPU时间
      struct block_1 cycle_block_1(ask_time, need_time, use_time, new PCB(i));
      vec.push_back(cycle_block_1);
    }
  cout << "Proc ID" << '\t' << '\t' 
       << "ask_time" << '\t' << '\t'
       << "need_time" << '\t' << '\t'
       << "used_time" << endl << endl;

  //初始化状态输出
  cout << "进程初始化时各个变量值" << endl;
  cout << "-----------------------------------------------" << endl;
  for(iter_block_1 it = vec.begin(); it != vec.end(); ++it) 
    cout << *it << endl;
  cout << "-----------------------------------------------" << endl;

  //主要比较代码
  bool flag = true;
  while(flag) {
    iter_block_1 iter = vec.begin();
    iter->need_time -= 1;
    iter->used_time += 1;
    //输出各进程的运行状态
    cout << endl;
    for(; iter != vec.end(); ++iter) 
      cout << *iter << endl;
    if(vec.begin()->need_time == 0) {
      cout << "************";
      cout << "Process " << vec.begin()->pointer->get_id()
	   << " finished!";
      cout << "************" << endl;
      delete vec.begin()->pointer;
      vec.erase(vec.begin()); //撤销链首进程
    }
    else {
      if(vec.begin()->ask_time == vec.begin()->used_time) {
	vec.begin()->used_time = 0; //占用时间片数置为0
	vec.push_back(*vec.begin()); //置入队尾
	vec.erase(vec.begin()); //弹出队首

      }
    }
    if(vec.begin() == vec.end()) //队列为空
      flag = false;
  }
}
