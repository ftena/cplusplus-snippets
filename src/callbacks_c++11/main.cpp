#include <iostream>
#include <memory>

int stdf_foobar (int x, std::function<int(int)> moo)
{
    return x + moo(x); // std::function moo called
}

int foo (int x) { return 2+x; }

int main()
{
    int value = 5;

    /* Function pointers */
    std::cout << stdf_foobar(value, &foo) << std::endl;
    // can also be: stdf_foobar(5, foo)

    /* Lambda expressions */
    int capture_value = 3;
    std::cout << stdf_foobar(value,
                             [capture_value](int x) -> int { std::cout << "lambda: " << x << std::endl;
                                                             return 7 + capture_value + x; })
              << std::endl;
    // result: 20 ==  value + (7 + capture_value + value) == 5 + (7 + 3 + 5)

    return 0;
}

