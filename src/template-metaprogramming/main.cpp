#include <iostream>
using namespace std;

template< int n >
struct factorial { enum { ret = factorial< n - 1 >::ret * n }; };

template<>
struct factorial< 0 > { enum { ret = 1 }; };

int main() {
	// cout << "-1! = " << factorial< -1 >::ret << endl; // INFERNO!
	cout << "0! = " << factorial< 0 >::ret << endl; // 1
	cout << "1! = " << factorial< 1 >::ret << endl; // 1
	cout << "2! = " << factorial< 2 >::ret << endl; // 2
	cout << "3! = " << factorial< 3 >::ret << endl; // 6
	/*
	 * Ex. f(4) -> f(3)*4 -> f(2)*3*4 -> f(1)*2*3*4 -> f(0)*1*2*3*4 -> 1*1*2*3*4 = 24
	 */
	cout << "4! = " << factorial< 4 >::ret << endl; // 24
	cout << "7! = " << factorial< 7 >::ret << endl; // 5040
	return 0;
}
