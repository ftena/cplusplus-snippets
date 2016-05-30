#include "publisher.h"

Publisher::Publisher()
{

}

void Publisher::sendMessage(std::string message, std::function<void(std::string)> cb)
{
    cb(message);
}
