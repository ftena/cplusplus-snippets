#include <iostream>
#include <memory>
#include "publisher.h"
#include "subscriber.h"

using namespace std::placeholders; // for `_1`

int main()
{
    std::unique_ptr<Subscriber> r(new Subscriber(.5));
    Subscriber s(2.5);
    Publisher p;


    p.sendMessage("your message!", std::bind(&Subscriber::receiveData, r.get(), _1));
    p.sendMessage("your message!", std::bind(&Subscriber::receiveData, &s, _1));

    auto bound_member_fn = std::bind(&Subscriber::receiveData, &s, _1);
    bound_member_fn("I'm free!");

    return 0;
}

