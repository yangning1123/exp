// 多段图动态规划算法

#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <map>     // multimap存储每个节点的邻接点
#include "Base.h"

namespace exp2 {
    template <typename T> class Dynamic : public Base<T>
    {
    public:
	Dynamic() = default;
	explicit Dynamic(uint m_N) : Base<T>(m_N)
	{
	    init();    // 定义对象时直接初始化
	}
	void setN(uint m_N) 
	{
	    this->N = m_N;
	    init();
	}
	~Dynamic() { }
	// 重写父类函数
	// 调用Base::read()并建立multimap映射
	void read(std::istream&);  
	// 动态规划处理函数
	void Dynamic_fun();
	// 输出函数
	std::ostream& print(std::ostream&) const;
	
    protected:
	/* 父类的uint N, vector<vector<T>> vec 
	   void read(istream&)
	 */
    
    private:
	void init();            // 初始化函数
	void make_map();        // 建立邻接点映射
	// 输出最短路径经过的顶点
	std::ostream& print_path(std::ostream&) const;  
    private:
	std::vector<T> cost;    // (i<=j<=N且顶点j是顶点i的邻接点)
	std::vector<uint> path; // path[i]=使c[i][j]+cost[j]最小的j
	std::multimap<uint, uint> my_map;
    };
}

#include "Dynamic.cpp"

#endif // DYNAMIC_H

