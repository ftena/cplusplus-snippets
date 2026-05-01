# cplusplus-snippets
C and C++ Source Code Snippets

## Compilation

    $ conan config install conan_profiles
    $ mkdir build && cd build
    $ conan install .. -pr=gcc11_cxx17_release -pr:b=default --output-folder .
    $ cmake .. -DCMAKE_TOOLCHAIN_FILE=./conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
    $ cmake --build . --parallel 4
