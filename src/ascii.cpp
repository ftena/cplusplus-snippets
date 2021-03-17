#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	char c = 'c';

	switch(c)
	{
		case 'a': std::cout << c << std::endl; break;
		case 'b': std::cout << c << std::endl; break;
		case 'c': std::cout << c << std::endl; break;
		default: std::cout << c << std::endl; break;
	};	

	std::string input = "manhattanz";
	const char* input_as_char = input.c_str();
	std::cout << "char_array: " << input_as_char << std::endl;

	for (int i = 0; i < input.size(); i++)
	{
		std::cout << "input_as_char[" << i << "]" << input_as_char[i] <<
		" & ASCII code = " << (int)input_as_char[i] << std::endl;
		
	}

	int i = 97;
	char value = i;
	std::cout << "The value " << i << " has an ASCII code of " << value << std::endl;
	value = i = 98;
	std::cout << "The value " << i << " has an ASCII code of " << value << std::endl;
	value = i = 100;
	std::cout << "The value " << i << " has an ASCII code of " << value << std::endl;		
}
