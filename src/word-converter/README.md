# Build

This application requires `cmake` and a cmake-supported build toolchain (like GCC
or Visual Studio) to build:

```sh
# creating a new build directory
mkdir build
cd build

# configuring the new build
cmake ../

# building
make -j 4
```

# Basic usage

```sh
./word_converter -i <input_file> [-o <output_file>]
```

# High-level guidelines about the implemented solution

- Based on C++17 to use `std::filesystem`
- No external libraries to have less dependencies, but Boost would be a good improvement. Also a better way to read options from the command line.
- It was considered to use regular expression to search the number in the sentence, but it's something that initially it wasn't necessary due to the first solution applied so it's a TODO.
- The class WordConverter implements the full solution:
	- The constructor takes a sentence as parameter. This constructor initializes a map with the pair `[number as text, number as decimal value]`
	- The `process()` function has many functionalities:
		- It extracts the number in English processing the text word by word. This info is stored in a `std::vector<std::string>`.
		- It uses the dollar sign to mark the text where the numbers were located.
		- It calculates the total value using the internal map to access to the value for each number stored in the vector created before.
		- It returns the sentence already converted replacing the dollar signs. 

# Notes

Just for future reference: https://www.rexegg.com/regex-trick-numbers-in-english.html 
