#include <iostream>

struct C
{
    int y;
    int foo(int x) { return x+y; }
};

/* Declaring a function taking a pointer to member function callback as one of its arguments: */
// C_foobar having an argument named moo of type pointer to member function of C
// where the callback returns int taking int as its argument also needs an object of type c
int C_foobar (int x, C &c, int (C::*moo)(int))
{
    return x + (c.*moo)(x); // function pointer moo called for object c using argument x
}

/* Note: If a pointer to C is available the syntax is equivalent (where the pointer to C must be dereferenced as well): */
int C_foobar_2 (int x, C *c, int (C::*meow)(int))
{
    if (!c) return x;
    // function pointer meow called for object *c using argument x
    return x + ((*c).*meow)(x);
    // or:
    // return x + (c->*meow)(x);
}


int main()
{
    C my_c;
    my_c.y = 2;

    int a = 5;
    int b = C_foobar(a, my_c, &C::foo); // call C_foobar with pointer to foo as its callback
    std::cout << b << '\n'; // b = 12

    C *my_pointer_to_c = new C();
    my_pointer_to_c->y = 2;
    int c = C_foobar_2(a, my_pointer_to_c, &C::foo);
    std::cout << c << '\n'; // c = 12

    return 0;
}

