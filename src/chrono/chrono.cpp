#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
 
// the function f() does some time-consuming work
void f()
{
    volatile double d;
    for(int n=0; n<10000; ++n)
       for(int m=0; m<10000; ++m)
           d += d*n*m;
}
 
int main()
{
    // using std::clock
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    std::thread t1(f); 
    std::thread t2(f); // f() is called on two threads
    t1.join();
    t2.join();
    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();
 
    std::cout << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC
              << " ms\n";
    std::cout << "Wall clock time passed: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count()
              << " ms\n";

    // using std::literals::chrono_literals
    using namespace std::literals::chrono_literals;
    std::chrono::seconds halfmin = 30s;
    std::cout << "Half a minute is " << halfmin.count() << " seconds\n"
        "A minute and a second is " << (1min + 1s).count() << " seconds\n";

    auto day = 24h;
    auto min = 60min;

    std::cout << "A day is " << day.count() << " hours\n"
        "A day and a day is " << (day + 24h).count() << " hours\n"
        "A day and a min is " << (day + min).count() << " min\n";

    std::chrono::nanoseconds cpuCycleAt500MHz = 2ns;

    std::cout << "A cpuCycleAt500MHz is " << cpuCycleAt500MHz.count() << " ns\n"
        "Plus 5ns is " << (cpuCycleAt500MHz + 5ns).count() << " ns\n"
        "Plus 5us is " << (cpuCycleAt500MHz + 5ns + 5us).count() << " ns\n"
        "Plus 5ms is " << (cpuCycleAt500MHz + 5ns + 5us + 5ms).count() << " ns\n"
        "Plus 5s is " << (cpuCycleAt500MHz + 5ns + 5us + 5ms + 5s).count() << " ns\n";
}
