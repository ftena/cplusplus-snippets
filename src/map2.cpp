#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<int,int>::const_iterator Iterador;

int main (int argc, char *argv[])
{
  map<int,int> m;
  m[0] = 1;
  m[1] = 0;
  m[2] = 2;
  m[3] = 7;

  for(Iterador i = m.begin(); i != m.end(); i++) {
    cout << i->first << " : " << i->second << endl;
  }

  cout << "----" << endl;

  m.erase(m.begin());

  for(Iterador i = m.begin(); i != m.end(); i++) {
    cout << i->first << " : " << i->second << endl;
  }

  cout << "----" << endl;

  m.erase(m.begin());

  for(Iterador i = m.begin(); i != m.end(); i++) {
    cout << i->first << " : " << i->second << endl;
  }

}
