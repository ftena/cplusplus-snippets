#include "subscriber.h"
#include <iostream>

Subscriber::Subscriber(float f): f_(f)
{

}

void Subscriber::receiveData(std::string data)
{
    std::cout << "Subscriber::receiveObj ---"
              << " data : " << data
              << " f_ : " << f()
              << std::endl;
}

void Subscriber::receiveDataWithValue(std::string data, int v)
{
    std::cout << "Subscriber::receiveObj ---"
              << " data : " << data
              << " f_ : " << f()
              << " value : " << v
              << std::endl;
}

float Subscriber::f()
{
    return f_;
}

void Subscriber::f(float f)
{
    f_ = f;
}
