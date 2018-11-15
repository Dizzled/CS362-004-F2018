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

betterTestDrawCard: betterTestDrawCard.c dominion.o rngs.o
	gcc -o betterTestDrawCard -g betterTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)
	
randomTestCards: 
	gcc -o randomTestAdventurer -g randomTestAdventurer.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomTestCard1 -g randomTestCard1.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomTestCard2 -g randomTestCard2.c dominion.o rngs.o $(CFLAGS)
	
runtests: randomTestCards 
	./randomTestAdventurer 
	gcov -b randomTestAdventurer.c >> randomtestadventurer.out
	cat randomTestAdventurer.c.gcov >> randomtestadventurer.out 
	
	./randomTestCard1 
	gcov -b randomTestCard1.c >> randomtestcard1.out
	cat randomTestCard1.c.gcov >> randomtestcard1.out

	./randomTestCard2 
	gcov -b randomTestCard2.c >> randomtestcard2.out
	cat randomTestCard2.c.gcov >> randomtestcard2.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player randomTestCards runtests 

clean:
	rm -f *.o randomTestAdventurer randomTestAdventurer.exe randomTestCard1 randomTestCard1.exe randomTestCard2 randomTestCard2.exe playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
