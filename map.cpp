#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<int,string>::const_iterator Iterador;

ostream& operator << (ostream& fs, const map<int,string>& m)
{
  for(Iterador i = m.begin(); i != m.end(); i++) {
    fs << i->first << " ***** " << i->second << endl;
  }
  return fs;
}

int main (int argc, char *argv[])
{
  map<int,string> m;
  pair<int,string> p = make_pair(4, "cuatro");

  m.insert(p);
  m.insert(make_pair(8, "ocho"));
  m.insert(make_pair(1, "uno"));
  m[9] = "nueve";
  m[1] = "UNO";

  cout << "Print using brackets: " << m[4] << endl;

  for(Iterador i = m.begin(); i != m.end(); i++) {
    cout << (*i).first << " : " << i->second << endl;
  }

  cout << m << endl;

  cout << "Map size: " << m.size() << endl;
}
