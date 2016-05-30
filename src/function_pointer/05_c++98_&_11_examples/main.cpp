#include <iostream>
#include <functional>

using std::placeholders::_1; // to be used in std::bind example

void tranform_every_int(int * v, unsigned n, int (*fp)(int))
{
  for (unsigned i = 0; i < n; ++i)
  {
    v[i] = fp(v[i]);
  }
}

// using std::function
void stdf_tranform_every_int(int * v, unsigned n, std::function<int(int)> fp)
{
  for (unsigned i = 0; i < n; ++i)
  {
    v[i] = fp(v[i]);
  }
}

int double_int(int x) { return 2*x; }
int square_int(int x) { return x*x; }

int nine_x_and_y (int x, int y) { return 9*x + y; }

int main()
{
    /* ******************** */
    /* C++98 */
    /* ******************** */
    int a[5] = {1, 2, 3, 4, 5};

    tranform_every_int(&a[0], 5, double_int);
    for(const int &i : a) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    tranform_every_int(&a[0], 5, square_int);
    for(const int &i : a) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    /* ******************** */
    /* C++11 */
    /* ******************** */

    // using function pointer still possible
    int b[5] = {1, 2, 3, 4, 5};
    stdf_tranform_every_int(&b[0], 5, double_int);
    for(const int &i : b) // access by const reference
        std::cout << i << ' ';
    // now a == {2, 4, 6, 8, 10};
    std::cout << '\n';

    // use it without having to write another function by using a lambda
    stdf_tranform_every_int(&b[0], 5, [](int x) -> int { return x/2; });
    for(const int &i : b) // access by const reference
        std::cout << i << ' ';
    // now a == {1, 2, 3, 4, 5}; again
    std::cout << '\n';

    // use std::bind :
    // calls nine_x_and_y for every int in a with y being 4 every time
    stdf_tranform_every_int(&b[0], 5, std::bind(nine_x_and_y, _1, 4));
    for(const int &i : b) // access by const reference
        std::cout << i << ' ';
    // now a == {13, 22, 31, 40, 49};
    std::cout << '\n';

    return 0;
}
