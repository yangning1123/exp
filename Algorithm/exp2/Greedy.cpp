#include <climits>   		// INT_MAX定义在此文件中
#include "Greedy.h"
using std::istream; using std::ostream;

namespace exp2 {
    template <typename T>
    void Greedy<T>::read(istream& is)
    {
	Base<T>::read(is);
    }

    template <typename T>
    void Greedy<T>::func()
    {
	int i = 0;
	while (i != this->N - 1)
	{
	    int min = INT_MAX;
	    int index = 0;      // 记录记录选择的节点
	    for (int j = 0; j != this->N; ++j)
	    {
		int temp = this->vec[i][j];
		if (temp != 0 && min > temp)
		{
		    min = temp;
		    index = j;
		}
	
	    }
	    cost.push_back(min);
	    path.push_back(index);
	    i = index;
	}
    }

    template <typename T>
    ostream& Greedy<T>::print(ostream& os) const
    {
	// 最短路径长度
	auto sum = 0;
	for (auto c : cost)
	    sum += c;
	os << "最短路径长度: " << sum << endl;
	// 经过的节点
	os << "最短路径为: ";
	os << "0";		// 起点
	for (auto c : path)
	    os << "->" << c;
	return os;
    }
}
