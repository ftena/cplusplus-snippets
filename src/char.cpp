#include <iostream>
#include <string>
#include "stdlib.h"

using namespace std;

int function (int id, int p, char t[5])
{
   //char tmp[5];
   
   //strcpy(tmp,t);

   cout << id << " " << p << " " << t << endl;
}

int function2 (string s)
{   
   cout << s << endl;
}

int main (int argc, char *argv[])
{
  char c[40] = "peperi ww yy xxxxx";

  string s = "hello";

  cout << c << endl;
  cout << s << endl;  

  function(10,20,c);
  function2(s);

  char t = '0';

  cout << "char: " << t << endl;

  bool b = t;

  cout << "bool: " << b << endl;
}
