#ifndef INSTANT_TASK_H
#define INSTANT_TASK_H_
#include "Task.h"

class TaskScheduler;

class InstantTask : public Task{
friend class TaskScheduler;
private:
   void execute() override final{}
   void end(bool) override final{};
   bool isFinished() const override final{ return true;}
};


#endif