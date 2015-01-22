#include <iostream>
#include <map>
#include <string>

using namespace std;

float* myFun()
{
	float* f;

	f = new float[200000];

	for(int i = 0; i < 50; i++)
		f[i] = i;

	return f;
}

void myFun2() {

	float *f;

	f = myFun();	

	for(int i = 0; i < 50; i++)

		cout << f[i] << endl;
	
	delete f;
}

int main (int argc, char *argv[])
{

	while(true) {
		myFun2();
	}

	return 0;
}
