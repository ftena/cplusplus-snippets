
#include <map>
#include <iostream>

struct B
{
	int i;
};

struct A
{
	std::map< int, std::map< int, B* > > x;
};

int main( int argc, char** argv )
{
	A a, b;
	a = b;
	A c( a );

	for ( int i = 0; i < 10; ++i )
	{
		std::cout << a.x[i][i] << std::endl;
	}

	std::cout << "Size a( " << a.x.size() << " )" << std::endl;
	for ( std::map< int, std::map< int, B* > >::const_iterator it = a.x.begin(); it != a.x.end(); ++it )
	{
		std::cout << "length maps 'a': " << it->second.size() << std::endl;
	}

	b = a;

	std::cout << "Size b( " << b.x.size() << " )" << std::endl;
	for ( std::map< int, std::map< int, B* > >::const_iterator it = b.x.begin(); it != b.x.end(); ++it )
	{
		std::cout << "length maps 'b': " << it->second.size() << std::endl;
	}

	return 0;
}

