CFLAGS= -Wall -fpic -fprofile-arcs -ftest-coverage -lm -std=c99
	
testme: 
	gcc -o testme.out -g testme.c $(CFLAGS)


# Running Unittest for Assigntment appending to ouput file	
runtests: testme 
	./testme 
	gcov -b testme.c
	
all: testme runtests 

clean:
	rm -f *.o testme testme.exe  *.gcov *.gcda *.gcno *.so *.out 
