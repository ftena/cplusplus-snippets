#include <iostream>
#include <vector>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
using namespace std;

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& v)
{
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " ")); 
            return os;
}


int main(int argc, char** argv)
{
   // Declare the supported options.
    int opt;
    po::options_description desc("Allowed options");

    desc.add_options()
        ("help", "produce help message")
        ("optimization", po::value<int>(&opt)->default_value(10), 
         "optimization level")
        ("include-path,I", po::value< vector<string> >(), 
         "include path")
        ("input-file", po::value< vector<string> >(), "input file")
        ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    cout << "Optimization level is " << opt << "\n";         

    if (vm.count("include-path")) {
        cout << "Include paths are: " 
            << vm["include-path"].as< vector<string> >() << "\n";
    } else {
        cout << "Include paths were not set.\n";
    }

    if (vm.count("input-file")) {
        cout << "Input files are: " 
            << vm["input-file"].as< vector <string> >() << "\n";
    } else {
        cout << "Input files were not set.\n";
    }



}
