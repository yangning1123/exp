/**
 * 初始化一些必要的向量信息
  */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//各类资源总数
void initial_Resource(unsigned *Resource, unsigned m) 
{
  unsigned number;
  cout << "请输入各类资源总数Resource:" << endl;
  for(unsigned i = 0; i != m; ++i)
    {
      cin >> number;
      Resource[i] = number;
    }
}


//Available矩阵
void initial_Available(unsigned *Available, unsigned *Resource, unsigned m)
{
  for(unsigned j = 0; j != m; ++j)
    {
      Available[j] = Resource[j]; //初始化时Available = Resource
    }
}

// Available矩阵的手动输入
void initial_Available(unsigned *Available, unsigned m)
{
  unsigned number;
  cout << "请输入Available矩阵" << endl;
  for(int i = 0; i != m; ++i)
    {
      cin >> number;
      Available[i] = number;
    }
}

//各进程的(Max, Need)矩阵
void initial_Process(unsigned*(*Process)[2] , unsigned *Resource,
		     unsigned N, unsigned m)
{
  //初始化Max矩阵
  cout << "请输入各进程的最大需求向量Max:" << endl;
  unsigned number; 
  for(int i = 0; i != N; ++i)
    {
      //unsigned *Max = new unsigned [m];
      Process[i][0] = new unsigned [m];
      for(int j = 0; j != m; ++j)
	{
	  cin >> number;
	  //假如进程的Max > Resource,报错，返回
	  //若检查出任意一组Max有问题，则需全部重新输入
	  if(number > Resource[j])                                  
	    {
	      cout << "最大需求量超过资源总数，请重新输入:" << endl;
	      i = -1; 
	      continue;  
	    }
	  //	  else Max[j] = number; 
	  Process[i][0][j] = number;
	}
    }

  //初始化Need矩阵
  cout << "请输入各进程还需资源需求向量Need:" << endl;
  for(int i = 0; i != N; ++i)
    {
      // unsigned *Need = new unsigned[m];
      //Process[i][1] = Need;
      Process[i][1] = new unsigned [m];
      for(int j = 0; j != m; ++j)
	{
	  cin >> number;
	  //	  Need[j] = number;
	  Process[i][1][j] = number;
	}
    }
}


//选择进程，输入该进程的资源请求量Request
void input_Request(unsigned *Request,unsigned m)
{
  cout <<"请输入该进程的资源请求向量Request:" << endl;
  unsigned number;
  for(int i = 0; i != m; ++i)
    {
      cin >> number;
      Request[i] = number;
    }
}
