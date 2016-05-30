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
private:
    float f();
    float f_;
};

#endif // SUBSCRIBER_H
