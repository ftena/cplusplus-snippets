#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

class ClassTypeA {
public:
    ClassTypeA (int v): v_(v) {}
    int getValue() { return v_; }
private:
    int v_;
}; 

class ClassTypeB {
public:
    ClassTypeB (double v): v_(v) {}
    double getValue() { return v_; }
private:
    double v_;
};

template <class T, class V>
class MyClass: public T {
public:
    MyClass (V v): T(v) {}

    V getValue() {
        return T::getValue();
    }
};


int main() 
{ 
    MyClass<ClassTypeA, int> i (5);
    std::cout << i.getValue() << std::endl;

    MyClass<ClassTypeB, double> d (7.9);
    std::cout << d.getValue() << std::endl;

    return 0;
} 
