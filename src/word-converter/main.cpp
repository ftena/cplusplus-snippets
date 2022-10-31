#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstring> // for errno

#include "WordConverter.h"

int main()
{
    WordConverter wordConverter;
    std::string const& inputFile = "../inputfile.txt";
    std::fstream fileStream(inputFile, std::ios::in);
    std::string fileLine;

    if(!fileStream)
    {
        throw std::runtime_error(inputFile + ": " + std::strerror(errno));
    }

    while(getline(fileStream, fileLine))
    {
        std::cout << "input : " << fileLine << '\n';

        std::vector<std::string> out;
        wordConverter.getNumbersFromString(fileLine, out);
        std::cout << "output : " << wordConverter.getValue(out) << '\n';

    }

    fileStream.close();

    return 0;
}
