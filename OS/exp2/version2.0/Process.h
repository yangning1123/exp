/**
 * 存放单个Process进程向量
 */

#ifndef PROCESS_H
#define PROCESS_H
#include <vector>
#include <iostream>
using std::ostream;
using std::vector;

class Process
{
 public:
  Process(int); //初始化Process向量
  friend ostream& operator<<(ostream&, const Process&); //输出单个Process向量

 private:
  void initial_Max(); //初始化Max向量
  void initial_Need(); //初始化Need向量
  void initial_Allocation(); 
  int m; //资源数
 public:
  vector<int> Max;
  vector<int> Allocation;
  vector<int> Need;
};

#endif //PROCESS_H
