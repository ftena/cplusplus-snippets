#include <memory>
#include <string>

#ifndef PUBLISHER_H
#define PUBLISHER_H

class Publisher
{
public:
    Publisher();

    void sendMessage(std::string message, std::function<void(std::string)> cb);    
};

#endif // PUBLISHER_H
