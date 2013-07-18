#include <iostream>
#include <stdexcept>
#include "Process_Block.h"
using std::cin;
using std::runtime_error;

Process_Block::
Process_Block(int real_N, int real_m):N(real_N), m(real_m)
{
  for(int i = 0; i != N; ++i)
    {
      Process proc(m);
      vec.push_back(proc);
    }
}

ostream& operator<<(ostream& os, const Process_Block& pro_blk)
{
  for(int i = 0; i != pro_blk.vec.size(); ++i)
    os << pro_blk.vec[i];

  return os;
}

bool operator<=(VECTOR &vec_1, VECTOR &vec_2)
{
  bool flag = true;
  for(int i = 0; i != vec_1.size(); ++i)
    if(vec_1[i] > vec_2[i])
      flag = false;
  if(flag) return true;
  else return false;
}

VECTOR& operator-=(VECTOR& vec_1, VECTOR& vec_2)
{
  for(int i = 0; i != vec_1.size(); ++i)
    vec_1[i] -= vec_2[i];

  return vec_1;
}

VECTOR& operator+=(VECTOR& vec_1, VECTOR& vec_2)
{
  for(int i = 0; i != vec_1.size(); ++i)       
    vec_1[i] += vec_2[i];
  
  return vec_1;
}

void Process_Block::initial_Available()
{
  int number;
  for(int i = 0; i != m; ++i)
    {
      cin >> number;
      Available.push_back(number);
    }
}

/*
 * Request向量比较特殊，因为每次输入完毕下一次输入时不能直接push_back,必须初始化为空向量才行
 */
void Process_Block::initial_Request(int num)
{
  VECTOR request;
  PID = num;
  int number;
  for(int i = 0; i != m; ++i)
    {
      cin >> number;
      request.push_back(number);
    }
  Request  = request;
}

// 银行家算法实现
void Process_Block::banker()
{
  
  if(Request <= vec[PID].Need)
    {
      if(Request <= Available) 
	// 正式分配资源
	{
	  Available -= Request;
	  vec[PID].Allocation += Request;
	  vec[PID].Need -= Request;
	}
      // 无足够资源，进程等待
      else		
	throw runtime_error("尚无足够资源，进程必须等待");
    }
  // 系统出错，因为所需要的资源数超过它所宣布的最大值
  else
    throw runtime_error("系统出错，因为它所需要的资源数超过它所宣布的最大值");
}

// 安全性算法实现
bool security(const Process_Block& pro_blk)
{
  // 复制一个Process_Block进程块，所有操作全部在此对象中进行，来检验系统是否安全
  Process_Block pbk(pro_blk);
  int N = pbk.N;
  bool Finish[N];
  for(int i = 0; i != N; ++i)
    Finish[i] = false;
  for(int j = 0; j != N; ++j)
    if(Finish[j] == false && pbk.vec[j].Need <= pbk.Available)
      {
	pbk.Available += pbk.vec[j].Allocation;
	Finish[j] = true;
	std::cout << pbk.vec[j]; 
	j = -1;
      }
  bool flag = true;
  for(int k = 0; k != N; ++k)
    if(Finish[k] == false)
      flag = false;
  // 返回True，安全
  if(flag) return true;
  return false;

}









