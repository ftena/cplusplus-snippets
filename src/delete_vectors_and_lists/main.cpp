#include <iostream>
#include <list>
#include <vector>

class foo_class
{
	public:
		foo_class(int i): i(i) {}; 
		~foo_class() { std::cout << "deleting " << i << std::endl; }
	private:
		int i;
};

static bool delete_all ( foo_class * element ) { delete element; return true; }

int main ( int argc, char** argv )
{
	std::list<foo_class*> foo_list;
	std::vector<foo_class*> foo_vector;

	foo_class *foo1 = new foo_class(1);
	foo_class *foo2 = new foo_class(2);
	foo_class *foo3 = new foo_class(3);
	foo_class *foo4 = new foo_class(4);

	foo_list.push_back(foo1);
	foo_list.push_back(foo2);

	foo_vector.push_back(foo3);
	foo_vector.push_back(foo4);

	foo_list.remove_if(delete_all);

	std::remove_if(foo_vector.begin(), foo_vector.end(), delete_all);

	return 0;
}
