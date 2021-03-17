// bind1st example
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int f(int a, int b)
{
    return a + b;
}

int g(int a)
{
    return a;
}

int main () {
	int numbers[] = {10,20,30,40,50,10};
	int cx;

	cx = count_if ( numbers, numbers+6, bind1st(equal_to<int>(),10) );
	cout << "There are " << cx << " elements that are equal to 10.\n";

	cx = count_if ( numbers, numbers+5, bind2nd(less<int>(),40) );
	cout << "There are " << cx << " elements that are less than 40.\n";

	for (int x = 0; x < 3; x++)
	{
		/*
			ptr_fun: returns a function object that encapsulates function f.
		*/
        /*
         * The function object returned by bind1st has its operator() defined
         * such that it takes only one argument. This argument is used to
         * call binary function object op with x as the fixed value for
         * the first argument.
         */
		cout << "f(5," << x << ") = " << bind1st(ptr_fun(f), 5)(x) << endl; // f(5, x)
	}

	// int (*f_pointer) (int a, int b);
	int (*f_pointer) (int, int);
	f_pointer = f;
	cout << "f(13, 2) = " << bind1st(ptr_fun(f_pointer), 13)(2) << endl;

	return 0;
}
