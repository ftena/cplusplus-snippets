#ifndef SYSTEM_COORDINATOR_H_
#define SYSTEM_COORDINATOR_H_

#include "icommand.h"
#include "icontroller.h"

class SystemCoordinator
{
	public:
		class Port1 : public ICommand {
			protected:
				virtual void operational();    // override ICommand
				virtual void start();
				virtual void stop();
		};
		class Port2 : public IController {
			protected:
				virtual void operational();    // override IController
				virtual void idle();
		};

	Port1 p1;
	Port2 p2;
};

#endif // SYSTEM_COORDINATOR_H_
