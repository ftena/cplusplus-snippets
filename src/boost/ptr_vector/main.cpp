#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

class foo_class
{
	public:
		foo_class(int i): i(i) {}; 
		~foo_class() { std::cout << "deleting " << i << std::endl; }
	private:
		int i;
};

int main ( int argc, char** argv )
{
	boost::ptr_vector<foo_class> foo_vector;

	foo_class *foo3 = new foo_class(3);
	foo_class *foo4 = new foo_class(4);

	foo_vector.push_back(foo3);
	foo_vector.push_back(foo4);

	return 0;
}
