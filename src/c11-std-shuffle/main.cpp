// more info @ https://compiler-explorer.com/z/5ncMTxb9E

#include <random>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::shuffle(
        data.begin(), data.end(), // all elements
        std::default_random_engine(42) // source of randomness with a specified seed
    );
    // data == {2, 7, 4, 0, 6, 1, 8, 3, 5, 9} libstdc++
    // data == {6, 8, 7, 0, 1, 4, 9, 3, 2, 5} libc++

    for (auto v : data) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    // Ranges variant with a random seed:
    //std::random_device rd;
    //std::ranges::shuffle(data, std::default_random_engine(rd()));
    // data now re-shuffled

    //for (auto v : data) {
    //    std::cout << v << " ";
    //}
    //std::cout << "\n";
}
