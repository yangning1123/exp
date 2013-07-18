/*
 * 单个文件的属性：文件名，所有权等
 *  */

#ifndef FILE_H
#define FILE_H

#include <string>
using std::string;

class File 
{
public:
File(string str):filename(str) { }
    
private:
    // 为了简化程序，只提供文件名属性
    string filename;   // 文件名
    
};

#endif   // FILE_H










