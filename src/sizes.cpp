#include <iostream>
#include <limits>

using namespace std;

enum X {
   TEST,
   TEST2,
   TEST3
};

int main() {
  unsigned int ui;
  int i;
  char c;
  long l;
  float f;
  double d;
  long long ll;

  cout << "unsigned int: " << sizeof(ui) << endl;
  cout << "int: " << sizeof(i) << endl;
  cout << "char: " << sizeof(c) << endl;
  cout << "long: " << sizeof(l) << endl;
  cout << "float: " << sizeof(f) << endl;
  cout << "double: " << sizeof(d) << endl;
  cout << "long long: " << sizeof(ll) << endl;

  cout << "enum X: " << sizeof(X) << endl;
}
