#include <iostream>
#include <vector>
#include <string>
#include <boost/circular_buffer.hpp>

int main(int argc, char** argv)
{
    // Create a circular buffer with a capacity for 3 integers.
    boost::circular_buffer<int> cb(3);

    std::cout << "Insert threee elements into the buffer." << std::endl;
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);

    int a = cb[0];  // a == 1
    int b = cb[1];  // b == 2
    int c = cb[2];  // c == 3

    for (const int& i : cb)
    {
        std::cout << i << std::endl;
    }

    std::cout << "The buffer is full now, so pushing subsequent"
        << "elements will overwrite the front-most elements." << std::endl;

    cb.push_back(4);  // Overwrite 1 with 4.
    cb.push_back(5);  // Overwrite 2 with 5.

    for (const int& i : cb)
    {
        std::cout << i << std::endl;
    }

    // The buffer now contains 3, 4 and 5.
    a = cb[0];  // a == 3
    b = cb[1];  // b == 4
    c = cb[2];  // c == 5

    // Elements can be popped from either the front or the back.
    cb.pop_back();  // 5 is removed.
    cb.pop_front(); // 3 is removed.

    // Leaving only one element with value = 4.
    int d = cb[0];  // d == 4
}
