#include <memory>
#include <string>

#ifndef PUBLISHER_H
#define PUBLISHER_H

class Publisher
{
public:
    Publisher();

    void sendMessage(std::string message, std::function<void(std::string)> cb);
    void sendMessage(std::string message, std::function<void(void*, std::string)> cb, void* obj);
};

#endif // PUBLISHER_H
