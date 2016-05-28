#include "subscriber.h"
#include <iostream>

Subscriber::Subscriber(float f): f_(f)
{

}

void Subscriber::receiveData(std::string data)
{
    std::cout << "Subscriber::receiveData : " << data << std::endl;
}

float Subscriber::f()
{
    return f_;
}

void Subscriber::receiveObj(std::string data, void* obj)
{
    Subscriber* self = static_cast<Subscriber*> (obj);

    std::cout << "Subscriber::receiveObj :"
              << " data : " << data
              << " f_ : " << self->f()
              << std::endl;
}
