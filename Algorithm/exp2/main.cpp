#include <iostream>
#include <fstream>
#include "Dynamic.h"
using std::cout; using std::endl;
using std::ifstream;
using namespace exp2;

int main(int argc, char *argv[])
{
    Dynamic<int> dy(10);
    ifstream ifs("data.txt");

    dy.read(ifs);
    dy.Dynamic_fun();
    dy.print(cout);
    cout << endl;
    
    return 0;
}
