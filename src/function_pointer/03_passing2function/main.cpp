#include <iostream>

int passingPointer(int (*pointerToFunction) (int))
{
    return (*pointerToFunction)(5);
}

int doSomething(int i) {
    std::cout << "value in doSomething(int i) = " << i << std::endl;

    return i*2;
}

int main()
{
    std::cout << "main() = " << passingPointer(&doSomething) << std::endl;

    return 0;
}
