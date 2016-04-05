#ifndef ICONTROLLER_H_
#define ICONTROLLER_H_

class IController
{
public:
    virtual void operational() = 0;
    virtual void idle() = 0;
    virtual ~IController(){}
};

#endif // ICONTROLLER_H_
