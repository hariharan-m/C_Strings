all:	lib test.c
	gcc -o output cstring.o test.c

lib:	cstring.c cstring.h
	gcc -c cstring.c
clean:	
	\rm *.o output
