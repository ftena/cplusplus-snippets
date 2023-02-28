// more info @ https://www.cppstories.com/2023/fun-print-tables-format/
#include <string>
#include <map>
#include <vector>
#include <ranges>
#include <format>
#include <iostream>

// handy view that returns only keys
template <typename T>
size_t MaxKeyLength(const std::map<std::string, T>& m) {
    auto res = std::ranges::max_element(std::views::keys(m), 
        [](const auto& a, const auto& b) {
            return a.length() < b.length();
        });
    return (*res).length();
}

int main()
{
	// a map of data
	constexpr size_t ROWS = 5;
	const std::map<std::string, std::array<double, ROWS>> productToOrders{
		{"apples", {100, 200, 50.5, 30, 10}},
		{"bananas", {80, 10, 100, 120, 70}},
		{"carrots", {130, 75, 25, 64.5, 128}},
		{"tomatoes", {70, 100, 170, 80, 90}}};

	const auto ColLength = MaxKeyLength(productsToOrders) + 2;

	// headers:
	for (const auto &name : std::views::keys(productsToOrders)) {
		std::cout << std::format("{:*>{}}", name, ColLength);
	}
	std::cout << '\n';

	// print values:
	for (size_t i = 0; i < NumRows; ++i) {
		for (const auto &values : std::views::values(productsToOrders)) {
			std::cout << std::format("{:>{}.2f}", values[i], ColLength);
		}
		std::cout << '\n';
	}
}
