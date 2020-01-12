#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);
  int Pid() const;
  std::string User();
  std::string Command();
  float CpuUtilization() const;
  void CpuUtilization(long activeJiffy, long sysJiffy);
  std::string Ram();
  long int UpTime();
  bool operator<(Process const& a) const;
  bool operator>(Process const& a) const;
 
 private:
  int pid_;
  float cpu_{0};
  long lastActiveJiffy{0};
  long lastIdleJiffy{0};
  long lastSystemJiffy{0};
};

#endif