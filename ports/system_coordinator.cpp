#include "system_coordinator.h"
#include <iostream>

void SystemCoordinator::Port1::operational() {
    std::cout << "ICommand::operational\n";
}

void SystemCoordinator::Port1::start() {
    std::cout << "ICommand::start\n";
}

void SystemCoordinator::Port1::stop() {
    std::cout << "ICommand::stop\n";
}

void SystemCoordinator::Port2::operational() {
    std::cout << "IController::operational\n";
}

void SystemCoordinator::Port2::idle() {
    std::cout << "IController::idle\n";
}
