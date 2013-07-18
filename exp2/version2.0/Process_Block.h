/**
 * 存放N个进程向量
 */

#ifndef PROCESS_BLOCK_H
#define PROCESS_BLOCK_H

#include <vector>
#include <iostream>
#include "Process.h"
using std::vector;
using std::ostream;

typedef vector<int> VECTOR; 	/* typedef ，下面要用到的比较多 */
class Process_Block
{
 public:
  Process_Block(int, int); //初始化进程块
  friend ostream& operator<<(ostream&, const Process_Block&);
  friend bool operator<=(VECTOR&, VECTOR&); //比较向量大小
  friend VECTOR& operator-=(VECTOR&, VECTOR&); //向量赋值
  friend VECTOR& operator+=(VECTOR&, VECTOR&);
  void initial_Available(); //初始化Available向量
  void initial_Request(int); //Request向量初始化
  //银行家算法,实现单一的分配向量功能
  void banker();
  //安全性算法，实现单一的安全性检测功能
  friend bool security(const Process_Block&); 

 private:
  int N; //进程数
  int m;
  int PID; //Request向量进程ID
  vector<Process> vec;
 public:
  VECTOR Available;
  VECTOR Request; //Request向量

};

#endif //PROCESS_BLOCK_H


