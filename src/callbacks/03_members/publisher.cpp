#include "publisher.h"

Publisher::Publisher()
{

}

void Publisher::sendMessage(std::string message, void (*cb)(std::string))
{
    cb(message);
}

void Publisher::sendMessage(std::string message, void (*cb)(void*, std::string), void* obj)
{
    cb(obj, message);
}
