#include <iostream>

int passingPointer(int (*pointerToFunction) (int))
{
    (*pointerToFunction)(5);
}

int doSomething(int i) {
    std::cout << "value in doSomething(int i) = " << i << std::endl;

    return i*2;
}

int main()
{
    std::cout << "value in main() = " << passingPointer(&doSomething) << std::endl;

    return 0;
}
