

#include <iostream>

int main( int argc, char** argv )
{
	std::cout << " Maximum for long long: " << std::numeric_limits< long long >::max() << std::endl;
	std::cout << " Maximum for double: " << std::numeric_limits< double >::max() << std::endl;
	std::cout << " Maximum for long: " << std::numeric_limits< long >::max() << std::endl;
	std::cout << " Maximum for float: " << std::numeric_limits< float >::max() << std::endl;
	return 0;
}
