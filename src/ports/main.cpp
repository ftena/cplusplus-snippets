#include <iostream>
#include "system_coordinator.h"
#include "hmi.h"
//#include "Process.h"

int main() {
    SystemCoordinator sc;
    HMI theHMI(sc.p1);				// bind to ICommand i/f
    //Process theProcess(sc.p2);	// bind to IController i/f

    theHMI.startRequested();		// ICommand::operational (p1)
    //theProcess.doWork();			// IController::operational (p2)
}
