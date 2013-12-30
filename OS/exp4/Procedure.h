#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <vector>
using std::vector;

class Procedure
{
public:
    explicit Procedure(vector<int> real_vec, const int real_number):
    vec(real_vec), number(real_number) { }
    
    void FCFS(); // 先来先服务
    void SSTF(); // 最短寻道时间优先
    void SCAN(); // 电梯调度算法

private:
    // 平均寻道长度计算
    double average() const;

    // 结构体,(磁道号， 访问标记)
    struct disk_number_flag
    {
    disk_number_flag(int r_number, bool r_flag):
	disk_number(r_number), flag(r_flag){ }
	int disk_number;
	bool flag;
    };

    vector<int> vec; // 存储被访问的下一个磁道号
    vector<int> dist_vec; // 存储移动距离
    const int number; // 存储当前磁头所在磁道号
};


#endif // PROCEDURE_H










