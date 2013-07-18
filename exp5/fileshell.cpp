// 文件操作命令提示符

#include <iostream>
#include <sstream>
#include <string>
#include "MFD.h"
#include "UFD.h"
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::istringstream;

const string shell = "fileshell~:";
extern string str[];

void fileshell()
{
    MFD *pmfd = new MFD("/home");
    string word1;
    do {
	cout << shell << flush;
	string line, word2;
	getline(cin, line);
	istringstream ist(line);
	ist >> word1;
	    
	if(word1 == "adduser")
	{
	    ist >> word2;
	    pmfd->adduser(word2);
	}
	if(word1 == "print")
	{
	    pmfd->print();
	}
			
	 
	cout << flush;
	    
    
    } while (word1 != "quit");
	    
}



















