#ifndef PCB_H
#define PCB_H

using std::string;
class PCB
{
 public:
  PCB();
 PCB(int i):id(i) {}
  int get_id()
  {
    return id;
  }
 private:
 public:
  int id;
  string cpu_status;
  string proc_attem_info;
  string proc_ctrl_info;
};

#endif //PCB_H
