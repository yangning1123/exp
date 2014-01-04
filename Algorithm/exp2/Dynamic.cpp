#include <climits>   		// INT_MAX定义在此文件中
#include "Dynamic.h"

using std::istream; using std::ostream; using std::endl;
using std::make_pair;

namespace exp2 {
    template <typename T>
    void Dynamic<T>::read(istream &is)
    {
	Base<T>::read(is);		
	make_map();
    }

    template <typename T>
    void Dynamic<T>::func()
    {
        // 计算cost[i]的值
	for (int i = this->N - 2; i >= 0; --i)
	{
	    auto min  = INT_MAX;
	    // 找出顶点i的邻接点j
	    for (auto beg = my_map.lower_bound(i), 
		     end = my_map.upper_bound(i);
		 beg != end; ++beg)
	    {
		// 对顶点i的每个邻接点根据算式计算cost[i]和path[i]
		auto j = beg->second;			
		auto sum = this->vec[i][j] + cost[j];
		if (min > sum)
		{
		    min = sum;
		    path[i] = j;
		}
	    }
	    cost[i] = min; 
	}   
    }

    template <typename T>
    ostream& Dynamic<T>::print(ostream &os) const
    {
	// 最短路径长度
	os << "最短路径长度: " << cost[0] << endl;
	print_path(os);
	return os;
    }

    template <typename T>
    ostream& Dynamic<T>::print_path(ostream &os) const
    {
	os << "最短路径为: ";
	os << "0->";		// 起点
	for (auto i = 0; path[i] != this->N - 1; i = path[i])
	    os << path[i] << "->";
	os << this->N - 1;		// 终点
	return os;
    }

    template <typename T>
    void Dynamic<T>::make_map()
    {
	// 生成相应邻接点信息
	// 生成规则：用户输入二维数组，不为0则两点邻接
	// g++要调用this->或Base<T>::来指出继承自父类
	for (auto i = 0; i != this->N; ++i)
	    for (auto j = 0; j != this->N; ++j)
		if (this->vec[i][j] != 0)
		    my_map.insert(make_pair(i, j));
    }

    template <typename T>
    void Dynamic<T>::init()
    {
	// cost、path均初始化为0
	cost.assign(this->N, 0);
	path.assign(this->N, 0);
    }
}
