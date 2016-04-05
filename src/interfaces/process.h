#ifndef PROCESS_H_
#define PROCESS_H_

#include "icontroller.h"

class Process
{
public:
   explicit Process(IController& ctRef):ct(ctRef){}
   void doWork() { ct.operational(); }
private:
   IController& ct; // association to IController Interface
};

#endif // HMI_H_
