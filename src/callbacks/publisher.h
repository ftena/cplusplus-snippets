#include <memory>
#include <string>

#ifndef PUBLISHER_H
#define PUBLISHER_H

class Subscriber;

class Publisher
{
public:
    Publisher(Subscriber* sub);

    void sendMessage(std::string message, void (*cb)(std::string));
    void sendMessage(std::string message, void (*cb)(std::string, void*), void* obj);

private:
    std::unique_ptr<Subscriber> sub_;
};

#endif // PUBLISHER_H
