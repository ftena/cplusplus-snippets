#include <iostream>

using namespace std;

char* f () {
   char* c = NULL;
   return c;
}

int main() {

  cout << "before" << endl;

  printf("%s \n",f());

  cout << (int)f() << endl;

  cout << "after" << endl;
}
