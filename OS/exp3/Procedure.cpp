#include <deque>
#include <map>
#include "Procedure.h"
using std::deque;
using std::map;

// 先进先出算法(FIFO)
// 采用队列实现，first in first out
double Procedure::FIFO(const int blocks) const
{
    deque<int> deq(blocks, -1);        	// FIFO队列
    int numbers = 0;		// 命中次数
    for(int i = 0; i != size; ++i)
    {
	bool flag = false;
	for(int j = 0; j != blocks; ++j)
	    if(array[i] == deq[j])  // 命中
		flag = true;
	if(flag)			
	    ++numbers;
	else  			// 未命中
	{
	    deq.push_back(array[i]); 
	    deq.pop_front();	// 移除队首元素，即最先调入内存的元素
	}
    }
  
    return (double) numbers / size;
}

// 最近最少使用算法(LFR)
// 也是采用队列实现，参见p152栈的描述(此处描述为栈不合适，因为栈是LIFO,故改为队列实现,原理不变)
double Procedure::LRU(const int blocks) const
{
    deque<int> deq(blocks, -1);
    int numbers = 0;
    for(int i = 0; i != size; ++i)
    {
	bool flag = false;
	deque<int>::iterator iter = deq.begin();
	for(; iter != deq.end(); ++iter)
	    if(array[i] == *iter)
	    {
		flag = true;
		break;
	    }
	if(flag)
	{
	    ++numbers;
	    // 把最近访问的页面调到队尾
	    deq.push_back(*iter);
	    deq.erase(iter);
	}
	else 
	{
	    deq.push_back(array[i]);
	    deq.pop_front();
	}
    }

    return (double) numbers / size;
}

// 最佳淘汰算法(OPT)
// 用map实现,存放(页面号， 再次用到此页面的位置)
// double Procedure::OPT(const int blocks) const
// {
//     map<int, int> opt_map;
//     for(int i = 0; i != blocks; ++i)
// 	opt_map[-i] = -i;		// 初始化opt_map各值为负

//     int numbers = 0; 		// 命中次数初始化为0

//     for(int i = 0; i != size; ++i)
//     {
// 	bool flag = false;
      
// 	for(map<int, int>::iterator map_iter = opt_map.begin();
// 	    map_iter != opt_map.end(); ++map_iter)
// 	    if(map_iter->first == array[i])
// 	    {
// 		flag = true;
// 		break;
// 	    }
// 	if(flag)			// 命中
// 	    ++numbers;
// 	else 			// 未命中
// 	{
// 	    if(opt_map.begin()->first < 0)
// 		opt_map.erase(opt_map.begin());
	  
	  
// 	}
      
      
//     }
    
//     }
