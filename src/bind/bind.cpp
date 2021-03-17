// bind example
#include <iostream>     // std::cout
#include <functional>   // std::bind
#include <memory>       // std::make_shared
#include <random>

/* EXAMPLE SET #1 */

double my_divide (double x, double y) {return x/y;}

struct MyPair {
    double a,b;
    double multiply() {return a*b;}
};

void example_set_1()
{
    std::cout << " --- example_set_1() --- " << std::endl;

    using namespace std::placeholders; // adds visibility of _1, _2, _3,...

    // binding functions:
    auto fn_five = std::bind (my_divide, 10, 2);               // returns 10/2
    std::cout << fn_five() << '\n';                            // 5

    // the same...
    std::cout << std::bind (my_divide, 10, 2)()  << '\n';

    auto fn_half = std::bind (my_divide, _1, 2);               // returns x/2
    std::cout << fn_half(10) << '\n';                          // 5

    auto fn_invert = std::bind (my_divide, _2, _1);            // returns y/x
    std::cout << fn_invert(10,2) << '\n';                      // 0.2

    auto fn_rounding = std::bind<int> (my_divide, _1, _2);     // returns int(x/y)
    std::cout << fn_rounding(10,3) << '\n';                    // 3

    MyPair ten_two {10,2};

    /*
     * Return value
     *   If fn is a pointer to member (in the next example: &MyPair::multiply),
     *   the first argument expected by the returned function is an object of the class *fn.
     */

    // binding members:
    auto bound_member_fn = std::bind (&MyPair::multiply, _1); // returns x.multiply()
    std::cout << bound_member_fn(ten_two) << '\n';           // 20

    // the same...
    std::cout << std::bind (&MyPair::multiply, &ten_two)() << '\n'; // returns ten_two.multiply()

    auto bound_member_data = std::bind (&MyPair::a, &ten_two); // returns ten_two.a
    std::cout << bound_member_data() << '\n';                // 10
}

/* EXAMPLE SET #2 */

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
    return n1;
}

struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data = 11;
};

void example_set_2()
{
    std::cout << " --- example_set_2() --- " << std::endl;

    using namespace std::placeholders;  // for _1, _2, _3...

    // demonstrates argument reordering and pass-by-reference
    int n = 7;
    // (_1 and _2 are from std::placeholders, and represent future
    // arguments that will be passed to f1)
    auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n); // std::cref -> Constructs an object to hold a const T reference.
    n = 10;
    f1(1, 2, 1001); // 1 is bound by _2, 2 is bound by _1, 1001 is unused

    // nested bind subexpressions share the placeholders
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
    f2(10, 11, 12); // 12 is bound by _3

    // bind to a pointer to member function
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);

    // bind to a pointer to data member
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << '\n';

    // smart pointers can be used to call members of the referenced objects, too
    std::cout << f4(std::make_shared<Foo>(foo)) << '\n';
}

int main () {
    example_set_1();
    example_set_2();

    return 0;
}
