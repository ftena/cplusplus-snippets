#include <iostream>

int foobar (int x, int (*moo)(int))
{
    return x + moo(x); // function pointer moo called using argument x
}

int foo (int x) { return 2 + x; }

int main()
{
    std::cout << foobar(5, foo) << std::endl;

    return 0;
}

