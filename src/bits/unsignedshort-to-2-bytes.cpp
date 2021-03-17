// bitset::to_ulong
#include <iostream> // std::cout
#include <bitset> // std::bitset
#include <stdlib.h>
#include <string.h>
#include <climits>

int main (int argc, char** argv)
{
	bool error;

	//for (unsigned short us = 1; us < USHRT_MAX; us++) {
	for (unsigned short us = 1; us < 5; us++) {
		//unsigned short us = 258;
		std::cout << "--- us = " << us << std::endl;

		char* buffer = new char[2];

		buffer[0] = us >> 8 & 0xff;
		buffer[1] = us & 0xff;

		std::bitset<8> b1(buffer[0]);
		std::bitset<8> b2(buffer[1]);

		std::cout << "std::bitset<8> b1(buffer[0]): " << b1.to_string() << std::endl;
		std::cout << "std::bitset<8> b1(buffer[1]): " << b2.to_string() << std::endl;

		std::cout << "buffer[0]: " << buffer[0] << std::endl;
		std::cout << "buffer[1]: " << buffer[1] << std::endl;
		std::cout << "(int)buffer[0]: " << (int)buffer[0] << std::endl;
		std::cout << "(int)buffer[1]: " << (int)buffer[1] << std::endl;

		// WRONG: unsigned short p = ( (buffer[0] && 0xff) << 8 ) | buffer[1];
		unsigned short p = (  ( buffer[0] & 0xff ) << 8 ) | ( buffer[1] & 0xff );
		// WRONG: unsigned short p = (  ( buffer[0] ) << 16 ) | ( buffer[1] );

		if ( us != p ) {
			error = true;

			std::cout << "ERROR FOUND! p = " << p << std::endl;

			exit (-1);
		}
	}

	return 0;
}
