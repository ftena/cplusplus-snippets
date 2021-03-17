#include <iostream>
#include <bitset>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {

    int N = 100;

    std::bitset<16> input(N);

    std::bitset<16> complement(~input);

    std::string input_str = input.to_string();
    std::string complement_str = complement.to_string();

    input_str = input_str.substr(input_str.find('1'));
    complement_str = complement_str.substr( complement_str.length() -input_str.length()  );

    std::cout << "input: " << input_str << std::endl;
    std::cout << "complement: " << complement_str << std::endl;

    std::bitset<16> output(complement_str);

    std::cout << "ouput: " << output.to_ulong() << std::endl;

}


