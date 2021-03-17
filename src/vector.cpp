#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int>::const_iterator Iterador;

ostream& operator << (ostream& fs, const vector<int>& v)
{
  for(Iterador i = v.begin(); i != v.end(); i++) {
    fs << *i << endl;
  }
  return fs;
}

int main (int argc, char *argv[])
{
  vector<int> v(2);
  vector<int> w;

  v.resize(5);

  v[0] = 3;
  v[1] = 4;
  v[2] = 5;
  v[3] = 6;
  
  w.push_back(4);
  w.insert(w.begin(),9);

  for(Iterador i = v.begin(); i != v.end(); i++) {
    cout << *i << endl;
  }
  
  cout << "W: " << w << endl;

}
