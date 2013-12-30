/**
 * 存放类声明及四种算法声明
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H

class Procedure
{
public:
Procedure(int r_array[], int r_size):
    array(r_array), size(r_size) { }
    double FIFO(const int) const; // FIFO算法
    double LRU(const int) const;  // LRU算法
    double OPT(const int) const;  // OPT算法
    double LFR(const int) const;  // LFR算法

private:
    // 求指定页号在数组中loca后第一次出现的位置
    int get_location(int num, int loca) const 
    {
	for(int i = ++loca; i != size; ++i)
	    if(array[i] == num)
		return i;
	return size; // 只用到一次
    }
    int *array; // 引用页面号数组
    int size;   // 数组长度

};

#endif // PROCEDURE_H

















