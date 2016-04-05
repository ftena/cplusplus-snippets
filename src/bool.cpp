#include <iostream>

int main()
{

	for (double d = -2.0; d < 2.0; d += 0.1)
	{
		if ( static_cast<bool>(d) )
		{
			std::cout << d << " is true" << std::endl;
		} else {
			std::cout << " ATTENTION!!! " << d << " is false" << std::endl;
		}
	}

	for (double d = -2; d < 2; d++)
	{
		if ( static_cast<bool>(d) )
		{
			std::cout << d << " is true" << std::endl;
		} else {
			std::cout << " ATTENTION!!! " << d << " is false" << std::endl;
		}
	}


}
