// more info @ http://www.modernescpp.com/index.php/pipes-and-filters 

// The following program displays the first ten primes starting with 1000.

#include <iostream>
#include <ranges>
#include <vector>

bool isPrime(int i) {
    for (int j = 2; j * j <= i; ++j){
        if (i % j == 0) return false;
    }
    return true;
}

int main() {

    std::cout << '\n';
    
    auto odd = [](int i){ return i % 2 == 1; };

    auto vec = std::views::iota(1'000) | std::views::filter(odd)           // (1)
                                       | std::views::filter(isPrime)       // (2)
                                       | std::views::take(10);             // (3)
                                       // | std::ranges::to<std::vector>();   // (4) - with C++23

    for (auto v: vec) std::cout << v << " ";
}
