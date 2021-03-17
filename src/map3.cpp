#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<int,int>::const_iterator IteradorSub;
typedef map<int,map<int, int> >::const_iterator Iterador;

int main (int argc, char *argv[])
{
	map<int,map<int, int> > m;
	pair<int, map<int, int> > p;
	map<int, int> q;

	q[0] = 10;
	p = make_pair (11, q);
	m.insert(p);

	q[1] = 20;
	p = make_pair (21, q);
	m.insert(p);


	q[2] = 30;
	p = make_pair (31, q);
	m.insert(p);


	q[3] = 40;
	p = make_pair (32, q);
	m.insert(p);

	q[4] = 50;
	p = make_pair (33, q);
	m.insert(p);

	for(Iterador i = m.begin(); i != m.end(); i++) {
		cout << i->first << " : "  << endl;

		for(IteradorSub j = i->second.begin(); j != i->second.end(); j++) {
			cout << j->first << " : " << j->second << endl;
		}
	}

}
