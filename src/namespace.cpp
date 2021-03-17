#include <iostream>

namespace One {
	void print () { std::cout << "print - One" << std::endl; }
};

namespace Two {
	void print () { std::cout << "print - Two" << std::endl; }
};

int main () {
	Two::print();

	return 0;
}
