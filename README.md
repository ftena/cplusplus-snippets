# cplusplus-snippets
C and C++ Source Code Snippets

## Compilation

You can compile most of snippets using CMake.

        $ mkdir build && cd build
        $ cmake ..
        $ cmake --build . --parallel 4

## Notes

Some code requires the boost libraries, so it's necessary to have the `BOOST_ROOT` environment variable defined in the system.
