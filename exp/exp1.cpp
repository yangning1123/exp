#include <iostream>
#include <vector>
using namespace std;


// 蛮力法，返回符合条件的下标或者-1
template <typename T>
int brute_force(const vector<T> &vec)
{
    for (decltype(vec.size()) i = 0; i != vec.size(); ++i)
	if (vec[i] == T(i))
	    return i;
    return -1;    
}


// 分治法，递归遍历此vector
template <typename T>
int divide_conquer(const vector<T> &vec, int beg, int end)
{
    // 元素为一个的情况
    if (beg == end)
    {
	if (vec[beg] == beg)
	    return beg;
	else return -1;
    }
    // 元素为多个的情况
    else 
    {
	int index = (beg + end) / 2;	
	if (vec[index] == T(index))
	    return index;

	// 递归遍历vector，若左右子序列均未找到符合条件的元素则返回-1
	if (divide_conquer(vec, beg, index) == -1 && 	// 递归处理前半部分
	    divide_conquer(vec, index + 1 , end) == -1) // 递归处理后半部分
	    return -1;
    }
}


int main(int argc, char *argv[])
{
    cout << "1、蛮力法\t2、分治法" << endl
	 << "选择算法: ";
    int choice = 1;		// 默认选择蛮力法
    cin >> choice;
    cout << "请输入数组内容: ";
    vector<int> vec; int num;
    while (cin >> num)
	vec.push_back(num);
    
    int t = 0;
    if (choice == 2)
	t = divide_conquer(vec, 0, vec.size() - 1);
    else 
	t = brute_force(vec);

    // 输出结果
    cout << "\n-----------------"
	 << "计算结果"
	 << "-----------------\n";
    if (t >= 0)
	cout << "vec[" << t << "] == " 
	     << t << endl;
    else
	cout << "符合条件的元素不存在" << endl;

    return 0;    
}
