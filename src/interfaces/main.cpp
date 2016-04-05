#include <iostream>
#include "system_coordinator.h"
#include "hmi.h"
#include "process.h"

int main() {
    SystemCoordinator sc;
    HMI theHMI(sc);            // create binding to ICommand
    Process theProcess(sc);        // create binding to IController

    theHMI.startRequested();          // SystemCoordinator::operational()
    theProcess.doWork();            // SystemCoordinator::operational()
}

