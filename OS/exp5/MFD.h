/*
 * MFD,存放用户目录文件名及指针
 *  */

#ifndef MFD_H
#define MFD_H

#include <string>
#include <map>
#include "UFD.h"
using std::string;
using std::map;

class MFD
{
public:
MFD(string str):root(str){    }
    
    void adduser(string);
    void print() const;      // 打印用户目录

private:
    map<string, UFD*> mfd_map;
    string root;             // 根目录
};

#endif // MFD_H

















