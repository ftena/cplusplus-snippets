#include <iostream>

using namespace std;

class test {
public:
   test() {};
   int getInt() { return i; }
   float getFloat() { return f; }
   double getDouble() { return d; }
   int getSize() { return sizeof(*this); }
private:
   int i;
   double d;
   float f;
   float f2;
   string s;
   int int3[3];
};

int main(int argc, char* argv[]){

  test t;
  int int3[3];

  cout << "Size class test: " << sizeof(test) << endl;
  cout << "Size obj test: " << sizeof(t) << endl;
  cout << "Size getSize: " << sizeof(t.getSize()) << endl;

  cout << sizeof(int) << endl;
  cout << sizeof(double) << endl;
  cout << sizeof(float) << endl;
  cout << sizeof(string) << endl;
  cout << sizeof(int3) << endl;

  return 0;
}
