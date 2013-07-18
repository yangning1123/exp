/**
 * 安全性算法
 */


bool security(unsigned *(*Process_temp)[2], unsigned *Available_temp,
	      unsigned m, unsigned N)
{
  bool *Finish = new bool [N]; 	
  for(int i = 0; i != N; ++i)
    Finish[i] = false;
  for(int i = 0; i != N; ++i)
    {
      bool flag = true;
      if(Finish[i] == false)
	{
	  for(int j = 0; j != m; ++j)
	    {
	   
	      if(Process_temp[i][1][j] > Available_temp[j])
		flag = false;
	      if(!flag) break;
	    }
       
	}
      if(flag && Finish[i] == false)
	{
	  for(int j = 0; j != m; ++j)
	    Available_temp[j] += (Process_temp[i][0][j] - Process_temp[i][1][j]);
	  Finish[i] = true;
	  i = -1;
	}
    }
  
  bool flag = true;
  for(int i = 0; i != N; ++i)
    if(Finish[i] == false)
      flag = false;
  delete [] Finish;
  if(flag) 
    return true;

  return false;
}





