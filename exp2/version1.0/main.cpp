/**
 * 采用动态数组方式，输入数据时假设为系统安全
 * Author: yangning1123@gmail.com
 */


#include <iostream>
#include "function.h"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  unsigned m;
  cout << "请输入资源数m:";
  cin >> m;
  unsigned *Resource = new unsigned [m]; //各类资源总数
  unsigned *Available = new unsigned [m]; //Available向量
  unsigned *Request = new unsigned[m]; //Request向量
  initial_Resource(Resource, m); //输入各类资源总数
  //  initial_Available(Available, Resource, m); 
  unsigned N;
  cout << "输入进程数n:";
  cin >> N;
 
  unsigned *(*Process)[2] = new unsigned* [N][2]; //Process矩阵
  initial_Process(Process, Resource, N, m); //输入并保存进程信息
  initial_Available(Available, m);

  unsigned PID;
  cout << "选择一个进程为当前进程(0~n-1):";
  while(cin >> PID) {
   
    input_Request(Request, m);
    banker(Request, Process, Available,
	   PID, m, N);
    cout << '\t' << "Max" << '\t' << '\t' << '\t' << '\t'
	 << "Need" << endl;
  // ====================================
  // 作为调试所用
  for(int i = 0; i != N; ++i) {
    for(int j = 0; j != m; ++j)
      cout << Process[i][0][j] << '\t';
    cout << '\t';
    for(int k = 0; k != m; ++k)
      cout << Process[i][1][k] << '\t';
    cout << endl;
    
  }
  // =====================================
  cout << "Available:";
  for(int l = 0; l != m; ++l)
    cout << Available[l] << '\t';
  cout << endl;
  cout << "选择一个进程为当前进程(0~n-1):";
  }
  
  /* 程序末尾，自动释放内存,不必手动
  delete [] Available;
  for(int i = 0; i != m; ++i){
    delete Process[i][0];
    delete Process[i][1];
  }
  delete [] Resource;
  delete [] Process;
  delete [] Request;
  */

  return 0;  
}
