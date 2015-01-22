#ifndef SYSTEM_COORDINATOR_H_
#define SYSTEM_COORDINATOR_H_

#include "icommand.h"
#include "icontroller.h"

class SystemCoordinator : public ICommand, public IController
{
protected:
    virtual void stop();
    virtual void operational();
    virtual void idle();
};

#endif // SYSTEM_COORDINATOR_H_
