#ifndef PROCESS_H_
#define PROCESS_H_

#include "icontroller.h"

// In this example, Process works as a controller
class Process
{
public:
   explicit Process(IController& controllerRef): controller(controllerRef) {}
   void doWork() { controller.operational(); }
private:
   IController& controller; // association to IController Interface
};

#endif // PROCESS_H_
