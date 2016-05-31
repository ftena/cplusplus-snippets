#include <stdio.h>

void my_int_func(int x) { printf( "%d\n", x ); }

int main()
{
	void (*foo)(int);
	/* the ampersand is actually optional */
	foo = &my_int_func;

	foo(2);

	/* Optionally, dereference the function pointer before calling the function it points to. */
	(*foo)(2);

	return 0;
}
