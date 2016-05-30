#include "publisher.h"

Publisher::Publisher()
{

}

void Publisher::sendMessage(std::string message, std::function<void(std::string)> cb)
{
    cb(message);
}

void Publisher::sendMessage(std::string message, std::function<void(void*, std::string)> cb, void* obj)
{
    cb(obj, message);
}
