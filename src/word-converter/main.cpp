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

    // check if the input file exists
    if(!std::filesystem::exists(inputFile))
    {
        std::cerr << usage << std::endl;
        throw std::runtime_error(inputFile + ": " + std::strerror(errno));
    }

    std::fstream inputFileStream(inputFile, std::ios::in);

    // if provided, check if the ouput file can be created
    std::fstream outputFileStream;
    if(!outputFile.empty())
    {
        outputFileStream.open(outputFile, std::ios::out);
        
        if(!std::filesystem::exists(outputFile))
        {
            throw std::runtime_error("Cannot create: " + outputFile); 
        }
    }

    // process lines
    std::string fileLine;
    while(getline(inputFileStream, fileLine))
    {
        std::cout << "input : " << fileLine << std::endl;

        WordConverter wordConverter(fileLine);
        std::string result = wordConverter.process();
        std::cout << "output : " << result << std::endl;

        // add text to the output file
        if(!outputFile.empty())
        {
            outputFileStream << result << '\n'; 
        }
    }

    inputFileStream.close();
    outputFileStream.close();

    return 0;
}
