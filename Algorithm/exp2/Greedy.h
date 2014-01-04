// 贪心法求解多段图最短路径

#ifndef GREEDY_H
#define GREEDY_H

#include  "Base.h" 

namespace exp2 {
    template <typename T> class Greedy : public Base<T>
    {
    public:
	Greedy() = default;
	explicit Greedy(uint m_N) : Base<T>(m_N)
	{		}
	void setN(uint m_N) 
	{
	    this->N = m_N;
	}
	~Greedy() { }
	
	void read(std::istream&);
	void func();
	std::ostream& print(std::ostream&) const;

    protected:
	/* 父类的uint N, vector<vector<T>> vec 
	   void read(istream&)
	*/

    private:
	std::vector<T> cost;  // 存储每次贪心所得的最短路径和
	std::vector<uint> path; // 每次贪心选择的节点
    };
}

#include "Greedy.cpp"

#endif // GREEDY_H
