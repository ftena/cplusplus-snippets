#include <iostream>

void print() {
    std::cout << std::endl;
}

template <typename T> void print(const T& t) {
    std::cout << t << std::endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
    std::cout << first << ", ";
    print(rest...); // recursive call using pack expansion syntax
}

/*
 * Variadic templates are written just the way you'd write recursive code
 * - you need a base case (the adder(T v) declaration in this example) and a general case
 * which "recurses". The recursion itself happens in the call adder(args...)
 * Note how the general adder is defined - the first argument is peeled off
 * the template parameter pack into type T (and accordingly, argument first).
 * So with each call, the parameter pack gets shorter by one parameter.
 * Eventually, the base case is encountered.
 */

template<typename T>
T adder(T v) {
    return v;
}

template<typename T, typename... Args> // typename... Args is called a template parameter pack
T adder(T first, Args... args) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return first + adder(args...); // will compile properly as long as it can apply the + operator to them
}

int main()
{
    // First example - print
    print(); // calls first overload, outputting only a newline
    print(1); // calls second overload

    // these call the third overload, the variadic template,
    // which uses recursion as needed.
    print(10, 20);
    print(100, 200, 300);
    print("first", 2, "third", 3.14159);

    // Second example - adder
    long sum = adder(1, 2, 3, 8, 7);
    std::cout << sum << '\n';

    std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
    std::string ssum = adder(s1, s2, s3, s4);
    std::cout << ssum << '\n';

}
