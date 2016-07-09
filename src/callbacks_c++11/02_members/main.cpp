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

    p.sendMessage("first message", std::bind(&Subscriber::receiveData, r.get(), _1));
    p.sendMessage("second message", std::bind(&Subscriber::receiveData, &s, _1));
    p.sendMessageWithValue("third message & value", 47, std::bind(&Subscriber::receiveDataWithValue, &s, _1, _2));
    p.sendMessageWithValue("xxx", 0, std::bind(&Subscriber::receiveDataWithValue, &s, "fixed!", 999));

    // update float value
    s.f(3.5);

    // store a call to a member function and object ptr
    auto bound_member_fn = std::bind(&Subscriber::receiveData, &s, _1);
    bound_member_fn("I'm free!");

    // the same...
    std::function<void(std::string)> bound_member_fn2 = std::bind(&Subscriber::receiveData, &s, _1);
    bound_member_fn2("I am also free!");

    // store a call to a member function
    std::function<void(Subscriber&, std::string)> s_receive_data = &Subscriber::receiveData;
    s_receive_data(s, "Me too");

    return 0;
}

