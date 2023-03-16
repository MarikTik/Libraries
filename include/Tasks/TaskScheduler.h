#ifndef TASK_SCHEDULER_H_
#define TASK_SCHEDULER_H_
#include <vector>
#include <queue>
#include <initializer_list>
#include "Task.h"

using namespace std;

#ifndef USE_VECTOR
using container_t = queue<Task*>;
#else
using container_t = vector<Task*>;
#endif

class _DefaultFriend;

template<typename Friend = _DefaultFriend>
class TaskScheduler
{
   
   TaskScheduler() = default;
   ~TaskScheduler() = default;
   TaskScheduler(const TaskScheduler&) = delete;
   void operator = (TaskScheduler&) = delete;
   friend typename Friend;

public:
   void Schedule(Task* task);
   void Schedule(initializer_list<Task*> tasks);

   void run();
   
private:
   vector<Task*> m_tasks;
   vector<bool> m_tasks_initialized;
  
};
 

template<typename T>
void TaskScheduler<T>::Schedule(Task* task){
   m_tasks.push_back(task);
   m_tasks_initialized.push_back(false);
}
template<typename T>
void TaskScheduler<T>::Schedule(initializer_list<Task*> tasks){
   for(auto task : tasks)
      Schedule(task);
}

template<typename T>
void TaskScheduler<T>::run(){
   for(auto i = 0; i < m_tasks.size(); i ++){
      auto task = m_tasks[i];
      bool initialized = m_tasks_initialized[i];

      if (initialized)
         task->execute();
      else {
         task->initialize();
         m_tasks_initialized[i] = true;
      }
      if (task->isFinished()){
         task->end();
         m_tasks.erase(m_tasks.begin() + i);
         delete task;
      }
     
   }
}





#endif   