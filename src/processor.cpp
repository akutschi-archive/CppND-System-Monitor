#include "processor.h"
#include "linux_parser.h"

// Return the aggregate CPU utilization
float Processor::Utilization() {
    long activeJiffy = LinuxParser::ActiveJiffies();
    long idleJiffy = LinuxParser::IdleJiffies();

    long activeDuration = activeJiffy - preActiveJiffy;
    long idleDuration   = idleJiffy - preIdleJiffy;
    long totalDuration = activeDuration + idleDuration;

    float processorUtilization = static_cast<float>(activeDuration) / totalDuration;

    preActiveJiffy = activeJiffy;
    preIdleJiffy = idleJiffy;

    return processorUtilization;
}