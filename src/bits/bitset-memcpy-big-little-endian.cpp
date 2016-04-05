#include <iostream>
#include <bitset>
#include <cstring>

int main(int argc, char** argv)
{
	// Working with bitsets
	{
		std::bitset<32> foo_bitset;
		float result;

		/*
			01000000 10110110 01100110 01100110
			01000000101101100110011001100110
		*/

		foo_bitset.set(0,0);
		foo_bitset.set(1,1);
		foo_bitset.set(2,1);
		foo_bitset.set(3,0);
		foo_bitset.set(4,0);
		foo_bitset.set(5,1);
		foo_bitset.set(6,1);
		foo_bitset.set(7,0);

		foo_bitset.set(8,0);
		foo_bitset.set(9,1);
		foo_bitset.set(10,1);
		foo_bitset.set(11,0);
		foo_bitset.set(12,0);
		foo_bitset.set(13,1);
		foo_bitset.set(14,1);
		foo_bitset.set(15,0);

		foo_bitset.set(16,0);
		foo_bitset.set(17,1);
		foo_bitset.set(18,1);
		foo_bitset.set(19,0);
		foo_bitset.set(20,1);
		foo_bitset.set(21,1);
		foo_bitset.set(22,0);
		foo_bitset.set(23,1);

		foo_bitset.set(24,0);
		foo_bitset.set(25,0);
		foo_bitset.set(26,0);
		foo_bitset.set(27,0);
		foo_bitset.set(28,0);
		foo_bitset.set(29,0);
		foo_bitset.set(30,1);
		foo_bitset.set(31,0);

		// Copy bits from reference foo_bitset to reference result
		memcpy(&result, &foo_bitset, sizeof(float));

		std::cout << "std::bitset<32> = " << foo_bitset.to_string() << " = " << result << std::endl;

		std::cout << std::endl;
	}

	{
		/*
			[0] = 00010010 -  [1] = 00010100 -  [2] = 00001110 -  [3] = 10000000
		*/

		std::bitset<32> foo_bitset;
		float result;

        foo_bitset.set(0,0);
        foo_bitset.set(1,0);
        foo_bitset.set(2,0);
        foo_bitset.set(3,0);
        foo_bitset.set(4,0);
        foo_bitset.set(5,0);
        foo_bitset.set(6,0);
        foo_bitset.set(7,1);

        foo_bitset.set(8,0);
        foo_bitset.set(9,1);
        foo_bitset.set(10,1);
        foo_bitset.set(11,1);
        foo_bitset.set(12,0);
        foo_bitset.set(13,0);
        foo_bitset.set(14,0);
        foo_bitset.set(15,0);

        foo_bitset.set(16,0);
        foo_bitset.set(17,0);
        foo_bitset.set(18,1);
        foo_bitset.set(19,0);
        foo_bitset.set(20,1);
        foo_bitset.set(21,0);
        foo_bitset.set(22,0);
        foo_bitset.set(23,0);

        foo_bitset.set(24,0);
        foo_bitset.set(25,1);
        foo_bitset.set(26,0);
        foo_bitset.set(27,0);
        foo_bitset.set(28,1);
        foo_bitset.set(29,0);
        foo_bitset.set(30,0);
        foo_bitset.set(31,0);

        // Copy bits from reference foo_bitset to reference result
        memcpy(&result, &foo_bitset, sizeof(float));

        std::cout << "std::bitset<32> = " << foo_bitset.to_string() << " = " << result << std::endl;

        unsigned char buffer[4];

        // little-endian
        buffer[0] = ((unsigned char*)&result)[0];
        buffer[1] = ((unsigned char*)&result)[1];
        buffer[2] = ((unsigned char*)&result)[2];
        buffer[3] = ((unsigned char*)&result)[3];

        std::cout << "buffer as float = " << *reinterpret_cast<float*>(&buffer) << std::endl;

        // big-endian
        buffer[0] = ((unsigned char*)&result)[3];
        buffer[1] = ((unsigned char*)&result)[2];
        buffer[2] = ((unsigned char*)&result)[1];
        buffer[3] = ((unsigned char*)&result)[0];

        std::cout << "buffer as float = " << *reinterpret_cast<float*>(&buffer) << std::endl;

	}

	return 0;
}
