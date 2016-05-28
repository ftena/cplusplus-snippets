#include <iostream>
#include <memory>
#include "publisher.h"
#include "subscriber.h"

int main()
{
    std::unique_ptr<Subscriber> s(new Subscriber(.5));
    Publisher p(s.get());

    p.sendMessage("your message!", &Subscriber::receiveData);
    p.sendMessage("your message!", &Subscriber::receiveObj, s.get());

    return 0;
}

