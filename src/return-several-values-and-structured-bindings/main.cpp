#include <iostream>

class Foo
{
    public:
        int foo;
};

class Bar
{
    public:
        char bar;
};

std::pair<Foo, Bar> f()
{
    std::pair<Foo, Bar> result;
    auto& foo = result.first;
    auto& bar = result.second;

    // fill foo and bar...

    foo.foo = 0xFF;
    bar.bar = 'x';

    return result;
}

int main(int argc, char** argv)
{
    /* Structured bindings
    * A proposal for de-structuring initialization, that would allow writing auto [ x, y, z ] = expr;
    * where the type of expr was a tuple-like object, whose elements
    * would be bound to the variables x, y, and z (which this construct declares).
    * Tuple-like objects include std::tuple, std::pair, std::array, and aggregate structures.
    */
    auto [foo, bar] = f();

    std::cout << foo.foo << std::endl;
    std::cout << bar.bar << std::endl;

    return 0;
}
