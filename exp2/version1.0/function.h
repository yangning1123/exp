/**
 * 保存函数声明
 */

#ifndef INITIAL_H
#define INITIAL_H

void initial_Resource(unsigned*, unsigned);
void initial_Available(unsigned*, unsigned*, unsigned);
void initial_Available(unsigned*, unsigned);
void initial_Process(unsigned*(*)[2], unsigned*,
		     unsigned, unsigned);
void input_Request(unsigned*, unsigned);
void banker(unsigned*, unsigned*(*)[2], unsigned*, 
	    unsigned, unsigned, unsigned);


#endif //INITIAL_H
