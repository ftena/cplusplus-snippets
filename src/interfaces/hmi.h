#ifndef HMI_H_
#define HMI_H_

#include "icommand.h"

class HMI
{
public:
   explicit HMI(ICommand& cmdRef):cmd(cmdRef){}
   void startRequested() { cmd.operational(); }
private:
   ICommand& cmd; // association to ICommand Interface
};

#endif // HMI_H_
