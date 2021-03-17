#include "foo.h"

int main (int argc, char** argv)
{
	Foo f(5);
	Foo b(f);

	return 0;	
}
