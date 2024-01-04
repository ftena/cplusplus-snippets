#include <iostream>

int foo() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return 0;
}

template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}

int main() {    
    int a = 1;             // `a` is declared as type `int`
    int x = 101;

    decltype(a) b = a;     // `decltype(a)` is `int`
    const int &c = a;      // `c` is declared as type `const int&`
    decltype(c) d = a;     // `decltype(c)` is `const int&`
    decltype(123) e = 123; // `decltype(123)` is `int`
    int &&f = 1;           // `f` is declared as type `int&&`
    decltype(f) g = 1;     // `decltype(f) is `int&&`

    decltype((a)) h = a;            // h is an "int &"  because (a) is an lvalue
    
    decltype((std::move(a))) i = 5; // i is an "int &&" because 5 undergoes an implicit conversion to an rvalue reference (int&&) because i is declared as int&&
    std::cout << "a: " << a << std::endl;
    std::cout << "i: " << i << std::endl;
    
    decltype((std::move(a))) j = std::move(x); // j is an "int &&" because std::move(x)) is an xvalue
    std::cout << "a: " << a << std::endl;
    std::cout << "j: " << j << std::endl;
    
    decltype(foo()) k = foo();      // k is an "int" because (foo()) is a prvalue
    std::cout << "k: " << k << std::endl;

    decltype(foo()) && r1 = foo();  // int &&
    std::cout << "r1: " << r1 << std::endl;

    decltype((x)) && r2 = x;        // int & because & && collapses to &
    
    auto s = add(1, 2.0); // `decltype(x + y)` => `decltype(3.0)` => `double`
    std::cout << "s: " << s << std::endl;

    return 0;
}
