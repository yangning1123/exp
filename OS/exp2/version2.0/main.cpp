/**
 * 采用类來编写
 * Author:yangning1123@gmail.com
 */

#include <iostream>
#include <stdexcept>
#include "Process_Block.h"
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main(int argc, char* argv[])
{
  int N, m;
  cout << "请输入进程数N及资源数m:";
  cin >> N >> m;
  cout << "请输入各进程矩阵向量:" << endl;
  Process_Block proc(N, m);
  cout << "请输入Available向量:" << endl;
  proc.initial_Available();
  if(security(proc))
    cout << "系统安全" << endl;
  else 
    {
      cout <<"系统不安全,退出" << endl;
      return 0;
    }
  int pid;
  cout << "请输入请求资源的进程ID(0-"<< N - 1 <<"):";
 
  while (cin >> pid)
    {
      cout << "输入请求资源向量:" << endl;
      proc.initial_Request(pid);
      try {
	if(security(proc)) 
	  {
  	    cout << "系统安全" << endl;
	    proc.banker();	 
	  }
      }
      catch (runtime_error err) {
	cout << err.what() << endl;
      }
	
      cout << "Max" << '\t'
	   << "Allo" << '\t'
	   << "Need" << endl;
      cout << proc << endl;
      // cout << "Available向量:";
      
      cout << "请输入请求资源的进程ID(0-"<< N - 1 <<"):";
    }


  return 0;
}
