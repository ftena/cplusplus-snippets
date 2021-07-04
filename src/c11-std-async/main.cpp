#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex __m;

void foo()
{
    std::lock_guard<std::mutex> lk(__m);
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

void bar()
{
    std::lock_guard<std::mutex> lk(__m);
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

void waldo()
{
    std::lock_guard<std::mutex> lk(__m);
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

void qux()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

int main()
{
    auto f1 = std::async(std::launch::deferred, waldo);            // lazy evaluation
    std::future<void> f2 = std::async(std::launch::deferred, bar); // lazy evaluation
    f2.wait();

    auto f4 = std::async(qux);                     // default policy
    auto f3 = std::async(std::launch::async, foo); // async evaluation

    f3.get();
    f1.wait();
}
