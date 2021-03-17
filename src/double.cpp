#include <iostream>

using namespace std;

double function () {
   int a, b;
   a = 10;
   b = 3;

   cout << a/b << endl;

   return a/b;
}

int main() {

  double x = 9;
  double y = function();

  cout << x << endl;

  cout << y << endl;

	double z = 1000000000;//000;

	cout << z << endl;
}
