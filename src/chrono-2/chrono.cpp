#include <chrono>
#include <iostream>
#include <thread> // sleep_for

int main() {
    using namespace std::literals;  

    auto tp1 = std::chrono::steady_clock::now(); // obtain a time point
    std::this_thread::sleep_for(1ms); // millisecond literal
    auto tp2 = std::chrono::steady_clock::now();
    // base type and precision depend on the type of clock

    auto duration = tp2 - tp1; // difference of time points is a duration
    std::cout << duration.count() << "\n";
    // example output: 1115389ns

    // explicit type of duration, base type double, with micro precision
    std::chrono::duration<double, std::micro> fpdur = tp2 - tp1;
    std::cout << fpdur.count() << "\n";
    // example output: 1115.39µs

    // duractions can be converted between each other using duration_cast
    auto micro = std::chrono::duration_cast<
            std::chrono::microseconds>(tp2 - tp1);
    std::cout << micro.count() << "\n";
    // example output: 1115µs
}