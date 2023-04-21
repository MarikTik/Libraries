#ifndef APPLICATION_REQUISIT_H_
#define APPLICATION_REQUISIT_H_
#include "Application.h"

struct ApplicationRequisite : public Application {
   ApplicationRequisite(uint16_t priority) : _priority(priority) 
   {
   }
   protected:
      uint16_t _priority; // highest = 0 <= priority <= 65535 = lowest 
};

#endif