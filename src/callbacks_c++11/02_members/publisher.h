#include <memory>
#include <string>

#ifndef PUBLISHER_H
#define PUBLISHER_H

class Publisher
{
public:
    Publisher();

    void sendMessage(std::string message, std::function<void(std::string)> cb);    
    void sendMessageWithValue(std::string message, int v, std::function<void(std::string, int)> cb);
};

#endif // PUBLISHER_H
