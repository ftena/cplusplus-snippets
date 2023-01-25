# cplusplus-snippets
C and C++ Source Code Snippets

## Compilation

You can compile most of snippets using 'make <name-of-file-without-extension>'

For example:

        $ make ascii
        $ make sort
        $ make time

* Some snippets have a makefile and it should be used to compile the code.
* Use cmake if available

## Notes

Some code requires the boost libraries, so it's necessary to have the `BOOST_ROOT` environment varible defined in the system.