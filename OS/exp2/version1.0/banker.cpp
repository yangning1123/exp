/**
 * 银行家算法
 */

#include <iostream>
using std::cout;
using std::endl;

bool security(unsigned *(*)[2], unsigned *,
	      unsigned, unsigned);

void banker(unsigned *Request, unsigned*(*Process)[2], unsigned *Available,
	    unsigned PID, unsigned m, unsigned N)
{
  bool flag_1 = true, flag_2 = true;
  for(int i = 0; i != m; ++i)
    {				
      if(Request[i] > Process[PID][1][i])
	flag_1 = false;
      if(Request[i] > Available[i])
	flag_2 = false;
    }
  if(!flag_1) {
    cout << "系统出错，因为它所需要的资源超过它宣布的最大值" << endl;
    return;
  }

  //分配资源
  if(flag_2) 
    {
      //设置临时变量检查是否符合安全性算法
      //若符合，则正式分配请求，若不符合，系统不分配资源
      unsigned *Available_temp = new unsigned [m];
      unsigned *(*Process_temp)[2] = new unsigned* [N][2];
      for(int i = 0; i != m; ++i)
	Available_temp[i] = Available[i];
      for(int j = 0; j != m; ++j)
	Available_temp[j] -= Request[j];
      // 复制另一个Process矩阵做临时变量
      for(int i = 0; i != N; ++i)
	{
	  Process_temp[i][0] = new unsigned [m];
	  for(int j = 0; j != m; ++j)
	    Process_temp[i][0][j] = Process[i][0][j];
	}
      for(int i = 0; i != N; ++i)
	{
	  Process_temp[i][1] = new unsigned [m];
	  for(int j = 0; j != m; ++j)
	    Process_temp[i][1][j] = Process[i][1][j];
	}
      // 临时Need矩阵
      for(int k = 0; k != m; ++k)
	Process_temp[PID][1][k] -= Request[k];
      
      //执行安全性算法		
      if(security(Process_temp, Available_temp, m, N))
	{
	  cout << "系统安全" << endl;
	  for(int j = 0; j != m; ++j)
	    Available[j] -= Request[j];
	  for(int k = 0; k != m; ++k)
	    Process[PID][1][k] -= Request[k];
	}
      else cout << "系统不安全" << endl;

      delete [] Available_temp;
      for(int i = 0; i != N; ++i)
	{
	  delete Process_temp[i][0];
	  delete Process_temp[i][1];
	}
      delete [] Process_temp;
    }
  else
    {	
      cout << "尚无足够资源，进程"<<PID<<"必须等待" << endl;
    
    }

} 
