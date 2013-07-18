/**
 * 优先权算法、轮转法
 * Author: yangning1123@gmail.com
 */

#include <iostream>
#include "PCB.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
  void priority(int); 
  void cycle(int);

  int N; char ch;
  cout << "请输入进程数N:";
  cin >> N;
  cout << "选择调度的方法（1、优先权法 2、轮转法）:";
  cin >> ch;
  cout << endl;
  if(ch == '1')
    priority(N);
  else if(ch == '2')
    cycle(N);

  cout << endl;
  return 0;
}
