#include <iostream>
#include "MFD.h"
using namespace std;


void MFD::adduser(string str)
{
    UFD ufd(str);
    mfd_map[str] = &ufd;
}


void MFD::print() const 
{
    map<string, UFD*>::const_iterator map_iter = mfd_map.begin();
    for(; map_iter != mfd_map.end(); ++map_iter)
	cout << map_iter->first << '\t';
    cout << endl;
}











