#include <stdio.h>

/*
A function pointer type has the notation

return_type (*)(paramter_type_1, paramter_type_2, paramter_type_3)
// i.e. a pointer to foo has the type:
int (*)(int)
*/

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
