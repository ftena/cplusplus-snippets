/*
 * Using templates, the code calling the callback can be even more
 * general than using std::function objects.
 */

#include <iostream>
#include <memory>

template<class R, class T>
void stdf_transform_every_int_templ(int * v,
  unsigned const n, std::function<R(T)> fp)
{
  for (unsigned i = 0; i < n; ++i)
  {
    v[i] = fp(v[i]);
    std::cout << v[i] << " ";
  }

  std::cout << "\n";
}

int foo (int x) { return 2+x; }
int muh (int const &x) { return 3+x; }
int & woof (int &x) { x *= 4; return x; }

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    stdf_transform_every_int_templ<int,int>(&a[0], 5, &foo);

    stdf_transform_every_int_templ<int, int const &>(&a[0], 5, &muh);

    stdf_transform_every_int_templ<int, int &>(&a[0], 5, &woof);

    return 0;
}

