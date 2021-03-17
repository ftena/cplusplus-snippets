#include <stdlib.h>
#include <stdio.h>

int int_sorter( const void *first_arg, const void *second_arg )
{
	int first = *(int*)first_arg;
	int second = *(int*)second_arg;
	if ( first < second )
	{
		return -1;
	}
	else if ( first == second )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int array[10];
	int i;
	/* fill array */
	for ( i = 0; i < 10; ++i )
	{
		array[ i ] = 10 - i;
	}

	/*
		qsort receives as last argument "int(*compar)(const void *, const void *)"

		It's a function pointer that takes two void *s and returns an int.
	*/
	qsort( array, 10 , sizeof( int ), int_sorter );
	for ( i = 0; i < 10; ++i )
	{
		printf ( "%d\n" ,array[ i ] );
	}

}
