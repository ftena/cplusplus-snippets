#include <iostream>
#include <bitset>
#include <cstring>
#include <stdint.h>
#include <climits>

int main(int argc, char** argv)
{
	// Working with bitsets: setting 1's in some positions
	{
		std::bitset<32> foo_bitset;
		float result;
		float value;

		foo_bitset.set(25,1);
		foo_bitset.set(26,1);
		foo_bitset.set(27,1);
		foo_bitset.set(28,1);
		foo_bitset.set(29,1);

		foo_bitset.set(21,1);

		value = foo_bitset.to_ulong();

		// Copy bits from reference foo_bitset to reference result
		memcpy(&result, &foo_bitset, sizeof(float));

		std::cout << "std::bitset<32> = " << foo_bitset.to_string() << " = " << result << std::endl;

		std::cout << std::endl;
	}

	// Set a new bitset using a float
	{

		float f = 355.45;
		unsigned long ul = *reinterpret_cast<unsigned long*>(&f);
		std::bitset<sizeof(float)*CHAR_BIT> foo3(*reinterpret_cast<unsigned long*>(&f));
		std::cout << f << " as unsigned long = " << ul << std::endl;
		std::cout << "std::bitset<" << sizeof(float)*CHAR_BIT << "> = " << foo3.to_string() << std::endl;
		std::cout << "foo3.to_ulong() = " << foo3.to_ulong() << std::endl;

		std::cout << std::endl;
	}


	// Packing and unpacking a float	
	{

		float f = 355.45;
		float result;

		// Create a buffer of 4 bytes
		unsigned char *_byteBuffer = new unsigned char[4];
		memset(_byteBuffer, 0, 4);
		const int length = sizeof(float);
		unsigned int uInt = 0;

		memcpy (&uInt, &f, length);

		std::cout << f << " as uInt using memcpy = " << uInt << std::endl;

		// Using uInt, we need to shift right bytes to split them into 8 bits.

		/*
			0xff = 11111111
			or... under 32-bit integer, 0xff = 00000000000000000000000011111111 

			In a nutshell, “& 0xff” effectively masks the variable so it leaves only
			the value in the last 8 bits, and ignores all the rest of the bits.
		 */

		/* PACK */
		_byteBuffer[0] = uInt >> 24 & 0xff;
		_byteBuffer[1] = uInt >> 16 & 0xff;
		_byteBuffer[2] = uInt >>  8 & 0xff;
		_byteBuffer[3] = uInt       & 0xff;

		/* UNPACK */
		for (int bytePos = 0; bytePos < length; bytePos++)
		{
			int shiftValue = (length - bytePos - 1) * 8;

			// Get the bits to know if there are being well recovered
			std::bitset<8> bs( _byteBuffer[bytePos] );
			std::cout << "		_byteBuffer[" << bytePos << "] to string = " << bs.to_string()
						<< " and the shift will be " << shiftValue << std::endl;

			/*
					 01000011 10110001 10111001 10011010

                _byteBuffer[0] to string = 01000011
                _byteBuffer[1] to string = 10110001
                _byteBuffer[2] to string = 10111001
                _byteBuffer[3] to string = 10011010 
			*/

			// Shifting left (this operation adds zeros at the right end)
			uInt = uInt | ( (_byteBuffer[bytePos] & 0xff) << shiftValue );
			// The same than before:
			// uInt = uInt | ( (_byteBuffer[bytePos] & 0x000000FF) << shiftValue );
		}
		
		std::cout << "After unpacking, uInt = " << uInt << std::endl;
		memcpy (&result, &uInt, length);
		std::cout << "And finally, the result as float is = " << result << std::endl;

		std::cout << "Get value using reinterpret_cast = " << *reinterpret_cast<float*>(&uInt) << std::endl;

		std::cout << std::endl;
	}

	// Packing and unpacking a float	(second version)
	/*
	* In this case, the buffer is set from right (right-most bits)
	* to left (left-most bits).
	*/
	{

		float f = 355.45;
		float result;

		// Create a buffer of 4 bytes
		unsigned char *_byteBuffer = new unsigned char[4];
		memset(_byteBuffer, 0, 4);
		const int length = sizeof(float);
		unsigned int uInt = 0;

		memcpy (&uInt, &f, length);

		std::cout << f << " as uInt using memcpy = " << uInt << std::endl;

		// Using uInt, we need to shift right bytes to split them into 8 bits.

		/*
			0xff = 11111111
			or... under 32-bit integer, 0xff = 00000000000000000000000011111111 

			In a nutshell, “& 0xff” effectively masks the variable so it leaves only
			the value in the last 8 bits, and ignores all the rest of the bits.
		 */

		/* PACK */
		_byteBuffer[0] = uInt & 0xff;
		_byteBuffer[1] = uInt >> 8 & 0xff;
		_byteBuffer[2] = uInt >> 16 & 0xff;
		_byteBuffer[3] = uInt >> 24 & 0xff;

		/* UNPACK */

		for (int bytePos = 3; bytePos >= 0; bytePos--)
		{
			int shiftValue = bytePos * 8;

			// Get the bits to know if there are being well recovered
			std::bitset<8> bs( _byteBuffer[bytePos] );
			std::cout << "		_byteBuffer[" << bytePos << "] to string = " << bs.to_string()
						<< " and the shift will be " << shiftValue << std::endl;

			/*
                _byteBuffer[3] to string = 01000011 and the shift will be 24
                _byteBuffer[2] to string = 10110001 and the shift will be 16
                _byteBuffer[1] to string = 10111001 and the shift will be 8
                _byteBuffer[0] to string = 10011010 and the shift will be 0
			*/

			// Shifting left (this operation adds zeros at the right end)
			uInt = uInt | ( (_byteBuffer[bytePos] & 0xff) << shiftValue );
		}

		std::cout << "Second version - uInt = " << uInt << std::endl;
		memcpy (&result, &uInt, length);
		std::cout << "After memcpy (&result, &uInt, length) = " << result << std::endl;

		unsigned int dword;

		((uint8_t*)&dword)[0] = (_byteBuffer[0]);
		((uint8_t*)&dword)[1] = (_byteBuffer[1]);
		((uint8_t*)&dword)[2] = (_byteBuffer[2]);
		((uint8_t*)&dword)[3] = (_byteBuffer[3]);
	
		std::cout << "Second version - dword = " << dword << std::endl;
		memcpy (&result, &dword, length);
		std::cout << "After memcpy (&result, &dword, length) = " << result << std::endl;
		std::cout << "Get value using reinterpret_cast = " << *reinterpret_cast<float*>(&dword) << std::endl;
		std::cout << "Get value using casting = " << *(float*)(&dword) << std::endl;

		std::cout << std::endl;
	}

	return 0;
}
