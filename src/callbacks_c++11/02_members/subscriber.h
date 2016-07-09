#include <iostream>
#include <string>

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber
{
public:
    Subscriber(float f);

    //callback
    void receiveData(std::string data);
    void receiveDataWithValue(std::string data, int v);
    float f();
    void f(float f);

private:
    float f_;
};

#endif // SUBSCRIBER_H
