#include <iostream>
#include <stdexcept>

int main()
{
 try {
	double zero = 0.0;

	if (!zero)
		throw zero;

	double a = 1/zero;

 } catch (double zero) {
        std::cout << "[FTR] division 0" << std::endl; 
 }
}
