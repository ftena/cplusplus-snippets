#include <iostream>
#include <optional>

// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {};
}

int main()
{
    std::string text = "Godzilla";
    std::optional<std::string> opt = create(true);
    if (opt.has_value()) 
    {
        std::cout << "The value() is "
            << opt.value()
            << ".\n";
    }
}
