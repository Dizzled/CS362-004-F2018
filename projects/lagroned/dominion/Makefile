CFLAGS= -Wall -fpic -fprofile-arcs -ftest-coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)
	

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)
	
unittestresults: 
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

# Running Unittest for Assigntment appending to ouput file	
runtests: unittestresults 
	./unittest1 
	gcov -b unittest1.c >> unittestresult.out
	cat unittest1.c.gcov >> unittestresult.out
	./unittest2 
	gcov -b unittest2.c >> unittestresult.out
	cat unittest2.c.gcov >> unittestresult.out
	./unittest3 
	gcov -b unittest3.c >> unittestresult.out
	cat unittest3.c.gcov >> unittestresult.out
	./unittest4
	gcov -b unittest4.c >> unittestresult.out
	cat unittest4.c.gcov >> unittestresult.out
	./cardtest1
	gcov -b ./cardtest1.c >> unittestresult.out
	cat cardtest1.c.gcov >> unittestresult.out
	./cardtest2
	gcov -b ./cardtest2.c >> unittestresult.out
	cat cardtest2.c.gcov >> unittestresult.out
	./cardtest3
	gcov -b ./cardtest3.c >> unittestresult.out
	cat cardtest3.c.gcov >> unittestresult.out
	./cardtest4
	gcov -b ./cardtest4.c >> unittestresult.out
	cat cardtest4.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittestresults runtests 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
