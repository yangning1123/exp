#include <iostream>
#include <fstream>
#include "Dynamic.h"
using std::cout; using std::cerr; using std::endl;
using std::ifstream;
using std::runtime_error;
using namespace exp2;

int main(int argc, char *argv[])
{
    Dynamic<int> dy(10);
    ifstream ifs("data.txt");

    try {
    dy.read(ifs);
    dy.Dynamic_fun();
    dy.print(cout);
    } catch (runtime_error &e)
    {
	cerr << e.what();
    }
    cout << endl;
    
    return 0;
}
