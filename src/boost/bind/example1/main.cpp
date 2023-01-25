#include <iostream>
#include <boost/bind/bind.hpp>

using namespace boost::placeholders;

int f(int a, int b)
{
    return a + b;
}

int g(int a, int b, int c)
{
    return a + b + c;
}

int main(int argc, char** argv)
{
	std::cout << boost::bind(&f, 1, 2)() << std::endl;
	std::cout << boost::bind(f, 1, _1)(2) << std::endl;
	std::cout << boost::bind(g, 1, 2, 3)() << std::endl;
	std::cout << boost::bind(g, _1, _2, 3)(1, 2) << std::endl;

	return 0;
}
