#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

typedef map<int,list<int> >::iterator IteratorM;
typedef list<int>::iterator IteratorL;

int main (int argc, char *argv[])
{
  map<int,list<int> > m;
  list<int> l1, l2;

  l1.push_back(1);
  l1.push_back(0);
  l1.push_back(3);
  l1.push_back(7);
  
  m[0] = l1; 

  l2.push_back(10);
  l2.push_back(20);
  l2.push_back(30);
  l2.push_back(70);
  
  m[1] = l2; 
  
  for(IteratorM i = m.begin();i != m.end(); i++) {
    cout << i->first << endl;
    for(IteratorL j = i->second.begin(); j != i->second.end(); j++) {
      cout << (*j) << " DISTANCE: " << distance(i->second.begin(),j) << endl;
    }
    cout << "-----------------" << endl;  
  }  
}
