#include <iostream>
#include <string>

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber
{
public:
    Subscriber(float f);

    //callback #1
    static void receiveData(std::string data);
    //callback #2
    static void receiveObj(void* obj, std::string data);
private:
    float f();
    float f_;
};

#endif // SUBSCRIBER_H
