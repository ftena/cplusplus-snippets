#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstring> // for errno
#include <unistd.h> // for getopt funtion

#include "WordConverter.h"

int main(int argc, char* argv[])
{
    std::string const& usage = "Usage: word_converter -i <input_file> [-o <output_file>]";
    std::string inputFile;
    std::string outputFile;
    int option;

    while((option = getopt(argc, argv, "i:o:")) != -1) // get option and its value
    {   
        switch(option)
        {
            case 'i': // input file 
                inputFile = optarg;
                break;
            case 'o': // output file
                outputFile = optarg;
                break;
            default:
                std::cerr << usage << std::endl;
                exit(EXIT_FAILURE);
                break;
        }
    }

    std::fstream fileStream(inputFile, std::ios::in);
    std::string fileLine;

    // check if the file exists
    if(!fileStream)
    {
        std::cerr << usage << std::endl;
        throw std::runtime_error(inputFile + ": " + std::strerror(errno));
    }

    // process lines
    while(getline(fileStream, fileLine))
    {
        std::cout << "input : " << fileLine << std::endl;

        WordConverter wordConverter(fileLine);
        std::cout << "output : " << wordConverter.process() << std::endl;

    }

    fileStream.close();

    return 0;
}
