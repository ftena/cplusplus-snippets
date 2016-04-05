#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string s1;  
	s1 = "5";

	cout << s1 << endl;
	cout << atoi(s1.c_str()) << endl;


	float f = 45.12;

	double d = 10.10;

	stringstream flujo;
	string s2;
	flujo << f;
	s2 = flujo.str();
	cout << s2 << endl;

	flujo.str("");
	
	flujo << f;
	s2 = flujo.str();
	cout << s2 << endl;

	flujo << f;
	s2 = flujo.str();
	cout << s2 << endl;

	flujo.str("");
	flujo << "5";
	flujo >> f;

	cout << "SHOWING F: " << f << endl;

	flujo.clear();
	flujo.str("");
	flujo << "10";
	flujo >> d;

	cout << "SHOWING D: " << d << endl;
}
