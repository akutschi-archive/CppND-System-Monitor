#include <string>
#include <iomanip>

#include "format.h"

using std::string;

// Helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
    string result;
    long hour = seconds / (60 * 60);
    long minute = (seconds / 60) % 60;
    long sec = seconds % 60;

    std::stringstream output;
    output << std::setfill('0') << std::setw(2) << hour << ":"
           << std::setfill('0') << std::setw(2) << minute << ":"
           << std::setfill('0') << std::setw(2) << sec;

    output >> result;

  return result;
}