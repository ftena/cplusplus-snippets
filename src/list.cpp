#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

typedef list<int>::iterator Iterador;

int main (int argc, char *argv[])
{
  list<int> l;

  l.push_back(1);
  l.push_back(0);
  l.push_back(3);
  l.push_back(7);

  for(Iterador i = l.begin(); i != l.end(); i++) {
    cout << (*i) << endl;    
  }

  Iterador i = find(l.begin(),l.end(),1);
  cout << "Element #1: " << *i << " DISTANCE:" << distance(l.begin(),i) << endl; 
  i = find(l.begin(),l.end(),3);
  cout << "Element #3: " << *i << " DISTANCE:" << distance(l.begin(),i) << endl; 
  i = find(l.begin(),l.end(),7);
  cout << "Element #7: " << *i << " DISTANCE:" << distance(l.begin(),i) << endl; 

  cout << "----" << endl;

  if(i == l.end())
    cout << "i = l.end with value: " << *i << endl;
  else
    cout << "i != l.end with value: " << *i << endl;

  i++;

  if(i == l.end())
    cout << "i = l.end with value: " << *i << endl;
  else
    cout << "i != l.end y value: " << *i << endl;

  cout << "----" << endl;

  i = l.begin();
  cout << "First element: " << *i << " DISTANCE: " << distance(l.begin(),i) << endl; 

  
  
}
