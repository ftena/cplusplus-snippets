#ifndef ICOMMAND_H_
#define ICOMMAND_H_

class ICommand
{
public:
    virtual void operational() = 0;
    virtual void stop() = 0;
    virtual ~ICommand(){}
};

#endif // ICOMMAND_H_
