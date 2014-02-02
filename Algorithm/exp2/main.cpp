#include <iostream>
#include <fstream>
#include <thread>
#include "Dynamic.h"
#include "Greedy.h"
using std::cout; using std::cerr; using std::endl;
using std::ifstream;
using std::runtime_error;
using std::thread;
using namespace exp2;

void dynamic()
{
    Dynamic<int> dy(10);
    ifstream ifs("data.txt");
    
    cout << "1、动态规划法:" << endl;    
    try {
	dy.read(ifs);
	dy.func();
	dy.print(cout);
    } catch (runtime_error &e)
    {
    	cerr << e.what();
    }
    cout << endl << endl;
    ifs.close();
}

void greedy()
{
    Greedy<int> gr(10);
    ifstream ifs("data.txt");
    
    cout << "2、贪心法:" << endl;
    try {
	gr.read(ifs);
	gr.func();
	gr.print(cout);
    } catch (runtime_error &e)
    {
	cerr << e.what();
    }
    cout << endl;
    ifs.close();
}

int main(int argc, char *argv[])
{
    thread t1(dynamic);
    t1.join();

    thread t2(greedy);
    t2.join();  
    
    return 0;
}
