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

    s.f(3.5);

    // store a call to a member function and object ptr
    auto bound_member_fn = std::bind(&Subscriber::receiveData, &s, _1);
    bound_member_fn("I'm free!");

    // the same...
    std::function<void(std::string)> bound_member_fn2 = std::bind(&Subscriber::receiveData, &s, _1);
    bound_member_fn2("I am also free!");

    return 0;
}

