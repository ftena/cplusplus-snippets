#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <clocale>

int main()
{
    const auto myfile {"myfile"};
    if (std::filesystem::exists(myfile)) {
        const auto bigFileSize {std::filesystem::file_size(myfile)};
        std::filesystem::path tmpPath {"/tmp"};
        if (std::filesystem::space(tmpPath).available > bigFileSize) {
            std::filesystem::create_directory(tmpPath.append("example"));
            std::filesystem::copy_file(myfile, tmpPath.append("newFile"));
        }
    }

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
    }

    fileStream.close();

    return 0;
}
