#include <iostream>


class IDemo
{
    public:
        virtual ~IDemo() {}
        virtual void OverrideMe() = 0;
};

class Parent
{
    public:
        virtual ~Parent();
};

class Child : public IDemo
{
/*    public:
        virtual void OverrideMe()
        {
            //do stuff
        }*/
};

int main (int argc, char* argv[])
{
	IDemo *pIDemo;

	Child *pChild;// = new Child();

	//pChild->OverrideMe();	

	return 0;
}
