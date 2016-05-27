// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream

int main () {
	char str[256];

	//std::cout << "Enter the name of an existing text file: ";
	//std::cin.get (str,256);    // get c-string

	std::ifstream is("/tmp/file.txt");     // open file

	if (is.good())
		std::cout << "file ok" << std::endl;
	else
		std::cout << "file no-ok" << std::endl;


	std::cout << "Init counter: " << is.gcount() << std::endl;

	std::cout << "INFO: Start reading using get()" << std::endl;

	while (is.good())          // loop while extraction from file is possible
	{
		char c = is.get();       // get character from file
		if (is.good()) {
			std::cout << "char: " << c;
			std::cout << " - counter: " << is.gcount() << std::endl;
		}
	}

	is.close();                // close file

	is.open("/tmp/file.txt");

	std::cout << "INFO: Start reading using getline()" << std::endl;
	std::string output;

	// get length of file:
	is.seekg (0, is.end);
	int length = is.tellg();
	is.seekg (0, is.beg); // set the position to the beginning

	char * buffer = NULL;

	if ( length < 0 )
		std::cout << "ERROR: Length = " << length << std::endl;
	else 
		buffer = new char [length];

	while (is.good())          // loop while extraction from file is possible
	{
		is.read(buffer, length);       // get character from file

		std::cout << "file: [" << buffer << "]";

		std::cout << " - counter: " << is.gcount() << std::endl;
	}

	if ( buffer )
		delete buffer;

	return 0;
} 
