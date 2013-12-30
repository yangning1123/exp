#include <iostream>
#include "Process.h"
using std::cin;
using std::endl;
using std::ostream;

Process::Process(int real_m):m(real_m)
{
  initial_Max();
  initial_Need();
  initial_Allocation();
}

ostream& operator<<(ostream& out, const Process& pro)
{
  int size = pro.Max.size();
  for(int i = 0; i != size; ++i)
    out << pro.Max[i] << ' ';
  out << '\t';
  for(int j = 0; j != size; ++j)
    out << pro.Allocation[j] << ' ';
  out << '\t';
  for(int k = 0; k != size; ++k)
    out << pro.Need[k] << ' ';
  out << endl;

  return out;
}



void Process::initial_Max()
{
  int number;
  for(int i = 0; i != m; ++i)
    {
      cin >> number;
      Max.push_back(number);
    }
}

void Process::initial_Need()
{
  int number;
  for(int j = 0; j != m; ++j)
    {
      cin >> number;
      Need.push_back(number);
    }
}

void Process::initial_Allocation()
{
  int al;
  for(int k = 0; k != m; ++k)
    {
      al = Max[k] - Need[k];
      Allocation.push_back(al);
    }
}
