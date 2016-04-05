#include <iostream>
#include <cstdlib>

using namespace std;

void function (int *);
void function2 (int &);

int main() {
  int *a;
  int *b;

  a = new int(); // C++
  b = (int*)std::malloc(sizeof(int)); // C

  *a = 6;
  *b = 8;

  cout << *a << endl;
  cout << *b << endl;

  function(a);
  cout << "After calling function 1, a = " << *a << endl;

  function2(*a);
  cout << "After calling function 2, a = " << *a << endl;

  int c = 0;
  cout << "Before calling function 2, c = " << c << endl;
  function2(c);
  cout << "After calling function 2, c = " << c << endl;

  int &d = c;
  cout << "d = " << d << endl;
  c = 0;
  cout << "d = " << d << endl;
  d = 500;
  cout << "d = " << d << " c = " << c << endl;
  
}

void function (int* a) // C (by reference)
{
  cout << "In function 1, a = " << *a << endl;
  *a = 200;
  
}

void function2 (int& a) // C++ (by reference)
{
  cout << "In function 2, a = " << a << endl;  
  a = 100;
}
