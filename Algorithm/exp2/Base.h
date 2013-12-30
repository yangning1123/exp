/*
  求解多段图最短路径问题
  定义基类，存储各节点之间的距离
  定义namespace exp2，实验代码均在此namespace中有效
*/

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>

// 定义命名空间exp
namespace exp2 {
    template <typename T> class Base
    {
    public:
	Base() = default;
	explicit Base(int m_N) : N(m_N) { }
	~Base() { } 
	
	void setN(uint m_N) { N = m_N; }
		
    	typedef unsigned int uint;    // uint，便于继承类应用

    protected:
	// 读取各节点之间的距离 
	// 可从标准输入或文件中读取
	inline void read(std::istream &is);

	uint N = 0;    // 节点个数
	std::vector<std::vector<T>> vec;
    };
}

namespace exp2 {
    template <typename T>
	void Base<T>::read(std::istream &is)
    {
	T distance;
	for (auto i = 0; i != N; ++i)
	{
	    std::vector<T> temp_vec;
	    for (auto j = 0; j != N; ++j)
	    {
		is >> distance;
		temp_vec.push_back(distance);
	    }
	    vec.push_back(temp_vec);
	}
    } 
}

#endif // BASE_H
