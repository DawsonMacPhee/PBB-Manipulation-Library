CFLAGS = -std=c99 -Wall -pedantic
CC = gcc

all: bandb.o test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff

bandb.o: bandb.c bandb.h
	$(CC) $(CFLAGS) -c bandb.c -o bandb.o

test_getbytes.o: test_getbytes.c bandb.h
	$(CC) $(CFLAGS) -c test_getbytes.c -o test_getbytes.o

test_getbits.o: test_getbits.c bandb.h
	$(CC) $(CFLAGS) -c test_getbits.c -o test_getbits.o

test_bits2ull.o: test_bits2ull.c bandb.h
	$(CC) $(CFLAGS) -c test_bits2ull.c -o test_bits2ull.o

test_bits2ll.o: test_bits2ll.c bandb.h
	$(CC) $(CFLAGS) -c test_bits2ll.c -o test_bits2ll.o

test_spff.o: test_spff.c bandb.h
	$(CC) $(CFLAGS) -c test_spff.c -o test_spff.o

test_dpff.o: test_dpff.c bandb.h
	$(CC) $(CFLAGS) -c test_dpff.c -o test_dpff.o

test_getbytes: bandb.o test_getbytes.o
	$(CC) $(CFLAGS) bandb.o test_getbytes.o -o test_getbytes

test_getbits: bandb.o test_getbits.o
	$(CC) $(CFLAGS) bandb.o test_getbits.o -o test_getbits

test_bits2ull: bandb.o test_bits2ull.o
	$(CC) $(CFLAGS) bandb.o test_bits2ull.o -o test_bits2ull

test_bits2ll: bandb.o test_bits2ll.o
	$(CC) $(CFLAGS) bandb.o test_bits2ll.o -o test_bits2ll

test_spff: bandb.o test_spff.o
	$(CC) $(CFLAGS) bandb.o test_spff.o -o test_spff

test_dpff: bandb.o test_dpff.o
	$(CC) $(CFLAGS) bandb.o test_dpff.o -o test_dpff

clean: 
	rm bandb.o test_getbytes.o test_getbits.o test_bits2ull.o test_bits2ll.o test_spff.o test_dpff.o test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff