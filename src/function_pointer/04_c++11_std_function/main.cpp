/*
 Instances of std::function can store, copy, and invoke any Callable target
 -- functions, lambda expressions, bind expressions, or other function objects,
 as well as pointers to member functions and pointers to data members.
*/

#include <functional>
#include <iostream>

struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};

void print_num(int i)
{
    std::cout << i << '\n';
}

struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
    // can also be: std::function<void(int)> f_display = &print_num;

    /* In C++98 */
    void (*f_display2) (int) = &print_num;
    f_display2(-9);
    // can also be: void (*f_display2) (int) = print_num;

    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();

    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();

    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(3);
    f_add_display(foo, 4); // 7

    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n'; // 3

    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2= std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2); // 5

    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3= std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3); // 6

    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18); // 18
}
