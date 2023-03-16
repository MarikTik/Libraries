#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <functional>

struct Application{
   
   typedef std::function<bool()> condition;
   void initialize();
   void execute();
   void sleep(condition sleepReason,
              condition wakeUpReason);
   void terminate(condition terminationReason);      
  

   Application& instance(){
      static Application application;
      return application;
   }      

};

#endif