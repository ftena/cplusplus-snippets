#include <iostream>
#include <string_view>

bool has_prefix(std::string_view str, std::string_view prefix)
{
  return str.substr(0, prefix.size()) == prefix;
}

int main()
{
    std::string text = "Godzilla";
    
    if (has_prefix(text, "God")) 
    {
        std::cout << "Ok! "
            << text 
            << ".\n";
    }
    char char_array[3] = {'G', 'o', 'd'};
    std::string_view string_view_array(char_array); //, std::size(array));

    std::cout << "What?! "
        << string_view_array
        << ".\n";
    
    string_view_array = std::string_view(char_array, std::size(char_array));

    std::cout << "OK! "
        << string_view_array
        << ".\n";
}
