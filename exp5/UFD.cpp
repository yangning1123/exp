#include <iostream>
#include "UFD.h"
using namespace std;

void UFD::mkfile(string str)
{
    File myfile(str);
    File *pfile = &myfile;
    ufd_map[str] = pfile;
}


void UFD::print() const
{
    map<string, File*>::const_iterator map_iter = ufd_map.begin();
    for(; map_iter != ufd_map.end(); ++map_iter)
	cout << map_iter->first << '\t';
    cout << endl;
}



















