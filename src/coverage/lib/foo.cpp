#include "foo.h"
#include <iostream>

Foo::Foo(int i): i_(i) {
}

Foo::~Foo() {
}

void Foo::dummy() {
	std::cout << "in dummy function" << std::endl;
}
