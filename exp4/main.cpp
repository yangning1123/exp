/*
 * 磁盘调度算法,FCFS, SSTF, SCAN
 * Author:
 *      yangning1123@gmail.com
 *
 * * */


#include <iostream>
#include "Procedure.h"

int main()
{
    vector<int> my_vec;
    my_vec.push_back(55);
    my_vec.push_back(58);
    my_vec.push_back(39);
    my_vec.push_back(18);
    my_vec.push_back(90);
    my_vec.push_back(160);
    my_vec.push_back(150);
    my_vec.push_back(38);
    my_vec.push_back(184);

    const int my_number = 100;
    
    Procedure pro(my_vec, my_number);

    std::cout << "FCFS算法:\n";
    pro.FCFS();
    std::cout << '\n' << '\n';

    std::cout << "SSTF算法:\n";
    pro.SSTF();
    std::cout << '\n' << '\n';

    std::cout << "SCAN算法:\n";
    pro.SCAN();
    std::cout << '\n' << '\n';

    return 0;
}


















