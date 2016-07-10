#include <iostream>     // std::cout
#include <functional>   // std::bind
#include <vector>
#include <string>
#include <algorithm>

struct Accountant {
public:
    salary() const { return salary_; }

    std::string name_;
    double salary_;
};

int main () {
    std::vector <Accountant> emps {{"Josh", 2100.0}, {"Kate", 2900.0}, {"Rose",1700.0}};

    const auto min_wage = 1600.0;

    const auto upper_limit = 1.5*min_wage;

    //report which accountant has a salary that is within a specific range

    std::find_if(emps.begin(), emps.end(),

    [=](const Accountant& a) {return a.salary() >= min_wage
                                    && a.salary() < upper_limit;});

    // find_if() call. It includes a lambda expression that takes const
    // accountant&. Where did this parameter come from? Recall that find_if() calls
    // its predicate function with an argument of type *InputIterator. In our example,
    // *InputIterator is accountant. Hence, the lambda’s parameter is const
    // accountant&. The find_if() algorithm invokes the lambda expression for every
    // accountant.

    return 0;
}
