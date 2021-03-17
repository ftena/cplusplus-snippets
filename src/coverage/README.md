# Gcov example
Gcov example for library and/or executable.

## Compilation

### Library compilation

```
$ cd lib
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Executable compilation

```
$ cd exe
$ mkdir build
$ cd build
$ cmake .. 
```

By default, the executable doesn't link gcov. If you want to enable it, use this command instead `cmake ..`

```
$ cmake -DENABLE_GCOV=ON ..

$ make
```

## Running executable and getting coverage information

This example provides two scripts. Both run the executable. One of them is to get the coverage info for the executable, and the other one to get the coverage info for the library. Use one or another as needed.

