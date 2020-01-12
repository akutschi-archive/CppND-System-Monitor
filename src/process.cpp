#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {};

// Return this process's ID
int Process::Pid() const { return pid_; }

// Return this process's CPU utilization
// "Realtime" CPU utilization
void Process::CpuUtilization(long activeJiffy, long sysJiffy) {
 	long activeDuration = activeJiffy - lastActiveJiffy;
    long totalDuration = sysJiffy - lastSystemJiffy;

  	cpu_ = static_cast<float>(activeDuration) / totalDuration;

  	lastActiveJiffy = activeJiffy;
  	lastSystemJiffy = sysJiffy;
}

// Return this process's CPU utilization
float Process::CpuUtilization() const { return cpu_; }

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Pid()); }

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Pid()); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(Pid()); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(Pid()); }

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const & a) const {
  return CpuUtilization() < a.CpuUtilization();
}

bool Process::operator>(Process const & a) const {
  return CpuUtilization() > a.CpuUtilization();
}

