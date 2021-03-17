#include <iostream>

int main(int argc, char** argv)
{
	for (int i = 0; i < 5; i++)
		std::cout << "i: " << i << std::endl;

	for (int i = 0; i < 5; ++i)
		std::cout << "i: " << i << std::endl;
}
