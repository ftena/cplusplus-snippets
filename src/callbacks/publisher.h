#include <memory>
#include <string>

#ifndef PUBLISHER_H
#define PUBLISHER_H

class Publisher
{
public:
    Publisher();

    void sendMessage(std::string message, void (*cb)(std::string));
    void sendMessage(std::string message, void (*cb)(void*, std::string), void* obj);
};

#endif // PUBLISHER_H
