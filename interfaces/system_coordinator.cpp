#include "system_coordinator.h"
#include <iostream>

void SystemCoordinator::operational() {
    std::cout << "operational\n";
}

void SystemCoordinator::idle() {
    std::cout << "iddle\n";
}

void SystemCoordinator::stop() {
    std::cout << "stop\n";

}
