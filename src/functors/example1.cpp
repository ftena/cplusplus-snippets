#include <iostream>
 
class MyFunctorClass
{
    public:
        MyFunctorClass (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
    private:
        int _x;
};
 
int main()
{
    MyFunctorClass addFive( 5 );
    std::cout << addFive( 3 ) << std::endl;
    std::cout << addFive( 1 ) << std::endl;
 
    return 0;
}
