// more info @ https://www.cppstories.com/2021/concepts-intro/
#include <numeric>
#include <vector>
#include <iostream>
#include <concepts>

template <typename T> 
requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const &vec) {
	const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);        
	return sum / vec.size();
}

int main() {
	std::vector ints { 1, 2, 3, 4, 5};
	std::cout << Average(ints) << '\n';                                      

	std::vector floats { 1.0, 3.0, 5.0};
	std::cout << Average(floats) << '\n';                                      

	// It will fail because of template parameter - const char* is not an integer or floating-point. 
	// std::vector strings { "a", "b", "c"};
	// std::cout << Average(strings) << '\n';                                      
}
