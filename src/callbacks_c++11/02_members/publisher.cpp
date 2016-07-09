#include "publisher.h"

Publisher::Publisher()
{

}

void Publisher::sendMessage(std::string message, std::function<void(std::string)> cb)
{
    cb(message);
}

void Publisher::sendMessageWithValue(std::string message, int v, std::function<void(std::string, int)> cb)
{
    cb(message, v);
}
