This is a collection of functions for the manipulation of pointers, bits, and bytes.

Files

    bandb.c
        Contains all the functions in the library.
    bandb.h
        Contains all the function declarations for the functions in bandb.c
    test_getbytes.c
        Contains a main function for testing the getbytes function
    test_getbits.c
        Contains a main function for testing the getbits function
    test_bits2ull.c
        Contains a main function for testing the bits2ull function
    test_bits2ll.c
        Contains a main function for testing the bits2ll function
    test_spff.c
        Contains a main function for testing the spff function
    test_dpff.c
        Contains a main function for testing the dpff function

Usage

    make all
        Compiles all test files and creates a bandb.o file
    make clean
        Deletes all compiles executables and object files
    make bandb.o
        Compliles bandb.c as an object file called bandb.o
    make test_getbytes.o
        Creates object file test_getbytes.o
    make test_getbits.o
        Creates object file test_getbits.o
    make test_bits2ull.o
        Creates object file test_bits2ull.o
    make test_bits2ll.o
        Creates object file test_bits2ll.o
    make test_spff.o
        Creates object file test_spff.o
    make test_dpff.o
        Creates object file test_dpff.o
    make test_getbytes
        Creates executable test_getbytes
    make test_getbits
        Creates executable test_getbits
    make test_bits2ull
        Creates executable test_bits2ull
    make test_bits2ll
        Creates executable test_bits2ll
    make test_spff
        Creates executable test_spff
    make test_dpff
        Creates executable test_dpff
