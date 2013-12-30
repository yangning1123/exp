#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include "Procedure.h"
using std::cout;
using std::endl;
using std::abs;			// 求绝对值

void Procedure::FCFS()
{     
    vector<int> copy_vec;
    copy_vec.push_back(number);	
    for(int i = 0; i != vec.size(); ++i)
	copy_vec.push_back(vec[i]);  

    for(int i = 1; i != copy_vec.size(); ++i)
    {
	int temp = abs(copy_vec[i] - copy_vec[i - 1]);
	dist_vec.push_back(temp);
    }

    // 输出结果
    cout << "被访问的下一个磁道号" << '\t' << "移动距离" << endl;
    for(int i = 0; i != dist_vec.size(); ++i)
	cout << '\t' << copy_vec[i + 1] << '\t' 
	     << '\t' << dist_vec[i] << endl;
    cout << "平均寻道长度: " << average() << endl;
	
    dist_vec.clear();	// 清空dist_vec向量
}


void Procedure::SSTF()
{
    vector<disk_number_flag> number_flag_vec;
    number_flag_vec.push_back(disk_number_flag(number, true));    

    // 存放后续的磁道号及访问状态
    for(int i = 0; i != vec.size(); ++i)
	number_flag_vec.push_back(disk_number_flag(vec[i], false));

    // 主要思路:待访问的磁盘号与其访问状态成对出现，遍历整个待访问磁盘号序列，
    // 一旦找出符合规则的盘号则将其状态位置为true,并将其作为下一个磁盘号的参考对象
    // 若状态全为true,则证明访问完毕,退出循环
    vector<int> temp_vec;	// 存放磁道号
    bool flag = true;
    int temp = number;
    while(flag){
	int OVER = INT_MAX, num = 0;
	for(int i = 0; i != number_flag_vec.size(); ++i)
	{
	    if(number_flag_vec[i].flag == false)
	    {
		int temp_2 = abs(temp - number_flag_vec[i].disk_number);
		if(temp_2 < OVER)
		{
		    OVER = temp_2;
		    num = i;
		}
	    }
	}
	temp = number_flag_vec[num].disk_number;
	number_flag_vec[num].flag = true; // 访问标记置为true
	temp_vec.push_back(temp);	  // 下一个访问磁盘号
	dist_vec.push_back(OVER);	  // 访问距离
	
	// 终止循环
	bool flag_2 = true;
	for(int i = 0; i != number_flag_vec.size(); ++i)
	    if(number_flag_vec[i].flag == false)
		flag_2 = false;
	if (flag_2)
	    flag = false;
    }
    
    // 输出结果
    cout << "被访问的下一个磁道号" << '\t' << "移动距离" << endl;
    for(int i = 0; i != temp_vec.size(); ++i)
	cout << '\t' << temp_vec[i] << '\t'
	     << '\t' << dist_vec[i] << endl;
    cout << "平均寻道长度: " << average() << endl;	    

    dist_vec.clear();	
}


void Procedure::SCAN()
{
    vector<int> copy_vec;
    copy_vec.push_back(number);	
    for(int i = 0; i != vec.size(); ++i)
	copy_vec.push_back(vec[i]);  
    
    sort(copy_vec.begin(), copy_vec.end()); // 从小到大进行排序
    
    vector<int>::iterator iter;
    vector<int> temp_vec;				   // 存放访问的磁道号序列
    iter = find(copy_vec.begin(), copy_vec.end(), number); // 找到当前磁道号
    for(vector<int>::iterator it = iter; it != copy_vec.end(); ++it)
	temp_vec.push_back(*it);
    for(vector<int>::iterator it = iter  - 1; it != copy_vec.begin() - 1; --it )
	temp_vec.push_back(*it);
    
    // 计算移动距离
    for(int i = 1; i != temp_vec.size(); ++i)
	dist_vec.push_back(abs(temp_vec[i] - temp_vec[i - 1]));
    
    // 输出结果
    cout << "被访问的下一个磁道号" << '\t' << "移动距离" << endl;
    for(int i = 0; i != dist_vec.size(); ++i)
	cout << '\t' << temp_vec[i + 1] << '\t'
	     << '\t' << dist_vec[i] << endl;
    cout << "平均寻道长度: " << average() << endl;

    dist_vec.clear();
}


double Procedure::average() const
{
    double sum = 0; 
    for(int i = 0; i != dist_vec.size(); ++i)
	sum += dist_vec[i];
	
    return sum / dist_vec.size();
}
