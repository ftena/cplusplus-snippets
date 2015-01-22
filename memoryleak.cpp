#include <iostream>
#include <vector>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
struct MyStruct {
	int x;
	int y;
};


int main (int argc, char **argv)
{
	if ( argc != 2)
	{
		std::cout << "Usage: ./memoryleak time" << std::endl;
		return -1;
	} 

	int _exit;
	int _sleeptime = 10000;

	std::cout << "--- Playing with memory leaks... ---" << std::endl;

	char * a;

	if (system(NULL)) puts ("Ok");
	else exit (EXIT_FAILURE);	

	/*
	* If command is a null pointer, the function only checks whether a
	* command processor is available through this function, without
	* invoking any command.
	*/


	/*while (true)
	{
		char * c = new char[2048 * 1000];

		_exit = system("ps aux | grep 'memoryleak'");
		std::cout << "The system call returned " << _exit << std::endl;
		usleep(_sleeptime);	
	}*/

	/* ... */

	MyStruct XY;
	std::vector <MyStruct> myVector;

	for(int i = 0; i < 10;++i)
	{
		XY.x = i;
		XY.y = i*2;
		myVector.push_back(XY);
	}

	std::cout << "Size of myVector:" << sizeof(myVector) << std::endl;

	myVector.clear();
	std::cout << "Size of myVector after clear:" << sizeof(myVector) << std::endl;

	std::vector<MyStruct>(myVector).swap(myVector);	
	std::cout << "Size of after Padawan idea myVector:" << sizeof(myVector) << std::endl;

	int j=0;
	std::cout << "Size of j:" << sizeof(j) << std::endl;
	return 0;
}
