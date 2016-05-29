#include <iostream>

void tranform_every_int(int * v, unsigned n, int (*fp)(int))
{
  for (unsigned i = 0; i < n; ++i)
  {
    v[i] = fp(v[i]);
  }
}

int double_int(int x) { return 2*x; }
int square_int(int x) { return x*x; }

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    tranform_every_int(&a[0], 5, double_int);
    for(const int &i : a) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    tranform_every_int(&a[0], 5, square_int);
    for(const int &i : a) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
