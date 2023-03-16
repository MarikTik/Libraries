#ifndef TASK_H_
#define TASK_H_

struct Task{
   virtual void initialize() = 0;
   virtual void execute() = 0;
   virtual void end(bool interrupted) = 0;
   virtual bool isFinished() const = 0;
};

#endif