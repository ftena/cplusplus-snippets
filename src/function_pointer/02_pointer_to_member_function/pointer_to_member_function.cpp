#include <iostream>

/*

A pointer to member function type for some class T has the notation

// can have more or less parameters
return_type (T::*)(paramter_type_1, paramter_type_2, paramter_type_3)
// i.e. a pointer to C::foo has the type
int (C::*) (int)

Where a named pointer to member function will -in analogy to the function pointer- look like this:

return_type (T::* name) (paramter_type_1, paramter_type_2, paramter_type_3)

*/

class C {
public:
    int y;
    int foo(int x) const { return x+y; }
    int bar(int x) { return x+y; }
};

int main()
{
    // i.e. a type `f_C_int` representing a pointer to member function of `C`
    // taking int returning int is:
    typedef int (C::*f_C_int_t) (int x) const;

    // The type of C_foo_p is a pointer to member function of C taking int returning int
    // Its value is initialized by a pointer to foo of C
    int (C::*C_foo_p) (int) const = &C::foo;

    C *myPointerToC = new C();

    std::cout << (myPointerToC->*C_foo_p)(5) << std::endl; // 5

    // which can also be written using the typedef:
    f_C_int_t C_foo_p_v2 = &C::foo;

    C myC;
    myC.y = 0;

    std::cout << (myC.*C_foo_p_v2)(5) << std::endl; // 5

    // a last example (without const function)
    int (C::*C_bar_p) (int) = &C::bar;
    std::cout << (myPointerToC->*C_bar_p)(10) << std::endl; // 10


}
