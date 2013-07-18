/**
 * 页面置换算法
 * Author: yangning1123@gmail.com
 */

#include <iostream>
#include "Procedure.h"
using std::cin;
using std::cout;
using std::endl;


int main()
{
    const int size = 20;
    int array[size] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    Procedure pro(array, size);  
  
    cout << "Start memory management." << endl
	 << "Producing address flow, wait for while, please." << endl;
    cout << "--------------------------------------------------" << endl << endl
	 << "--------------------------------------------------" << endl;

    cout << "There are algorithms in the program" << endl
	 << "      1、 First in first out algorithm " << endl
	 << "      2、 Least recently used algorithm " << endl
	 << "      3、 Optimization algorithm " << endl
	 << "      4、 Least frequently used algorithm " << endl;
      

    char option, ch;
 
    do {
	cout  << "Select an algorithm number, please: ";
	cin >> option;
	switch(option) {
	case '1':
	    for(int i = 2; i <= size; ++i)
		cout << i << ':' << ' ' << pro.FIFO(i) << endl;
	    break;
	case '2':
	    for(int i = 2; i <= size; ++i)
		cout << i << ':' << ' ' << pro.LRU(i) << endl;
	    break;
	default:
	    cout << "here is not the algorithm in the program" << endl;
	    return 0;
	}
	cout << "do you try again with anther algorithm(y/n): ";
	cin >> ch;
    }
    while(ch == 'y');
   

    return 0;
}
















