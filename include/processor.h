#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  

 private:
    long preActiveJiffy{0};
    long preIdleJiffy{0};
};

#endif