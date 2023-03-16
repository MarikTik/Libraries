#ifndef CYCLYC_TASK_H_
#define CYCLYC_TASK_H_
#include "Task.h"

class TaskScheduler;

class CyclycTask : public Task{
   friend class TaskScheduler;
   private:
      void initialize() override {}

};

#endif