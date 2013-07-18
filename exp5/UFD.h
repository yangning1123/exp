/*
 * UFD,存放此目录下的文件名及指针
 */

#ifndef UFD_H
#define UFD_H

#include <string>
#include <map>
#include "File.h"
using std::map;
using std::string;

class UFD
{
public:
UFD(string str):ufd_name(str){    }
    
    void mkfile(string);        // 建立文件
    void print() const;         // 遍历输出文件名
    
private:
    // 存放文件名及指向此文件名的指针
    map<string, File*> ufd_map;
    string ufd_name;            // 用户文件目录名   
};

#endif // UFD_H

















