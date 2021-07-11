#ifndef SYSTEM_COORDINATOR_H_
#define SYSTEM_COORDINATOR_H_

#include "icommand.h"
#include "icontroller.h"

// It coordinates the command (Port#1) and controller (Port#2)
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

	Port1 p1; // command
	Port2 p2; // controller
};

#endif // SYSTEM_COORDINATOR_H_
