#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <clocale>

#include "WordConverter.h"

void splitString(std::string const &inputString, std::vector<std::string> &out)
{
    // construct a stream from the string
    std::stringstream stream(inputString);
 
    std::string str;
    while (std::getline(stream, str, ' ')) {
        out.push_back(str);
    }
}

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
        std::cout << "Contents:" << fileLine << std::endl; 

        std::vector<std::string> out;
        splitString(fileLine, out);
 
        for (auto &s: out) {
            std::cout << s << '\n';
        }
    }

    fileStream.close();

    return 0;
}
