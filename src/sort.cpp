#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compareascending(string a, string b) {
	cout << "compare(" << a << "," << b << ")" << endl;
	return (a.compare(b) < 0);
}

int main ()
{
	string mystrs[] = {"A","a","B","b", "C","c"};
	vector<string> myvector (mystrs, mystrs + 6);
	vector<string>::iterator it;

	//sort (myvector.begin(), myvector.end(), compareascending);
	sort (myvector.begin(), myvector.end());
	cout << "ascending: vector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
 
