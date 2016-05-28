#include "publisher.h"
#include "subscriber.h"

Publisher::Publisher(Subscriber *sub): sub_(sub)
{

}

void Publisher::sendMessage(std::string message, void (*cb)(std::string))
{
    cb(message);
}

void Publisher::sendMessage(std::string message, void (*cb)(std::string, void*), void* obj)
{
    cb(message, obj);
}
