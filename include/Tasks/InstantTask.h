#ifndef INSTANT_TASK_H
#define INSTANT_TASK_H_
#include "Task.h"

class InstantTask : Task{
   void execute() override final{}
   void end() override final{};
};


#endif