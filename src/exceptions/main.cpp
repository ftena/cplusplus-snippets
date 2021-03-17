#include <iostream>
#include <exception>
using namespace std;

#include "myclass.h"
#include "myexception.h"
#include "myexception2.h"

class myclass;
class myexception;
class myexception2;

int main (int argc, char** argv) {

	myclass m;

	try
	{
		m.f();
	}
	catch (myexception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Here" << endl;
	}

	return 0;
}
