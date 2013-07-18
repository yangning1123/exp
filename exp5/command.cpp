// 一些基本的命令包括mkfile, adduser, cd, print, pwd, quit及出错处理

#include <iostream>
#include <string>
#include "MFD.h"
using std::cout;
using std::endl;
using std::string;

const int number = 5;
string str[] = { 
    "adduser",
    "mkfile",
    "cd",
    "print",
    "pwd",
    "quit"
};


// 出错处理
void command_not_found(string command)
{
    bool flag = true;
    for(int i = 0; i != number; ++i)
	if(command == str[i])
	    flag = false;
    if(flag)
	cout << "命令未找到，请重新输入:" << endl;
}


















