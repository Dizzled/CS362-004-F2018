/*
 * Assignment 3 CS362 Unit Test 1
 * 
 */

/* 
 * File: unittest1.c
 * Author: Dustin LaGrone
 * Created on October 18, 2018
 */


#define ASSERTTRUE(BoolCondition,__LINE__) do { if (!(BoolCondition)) { aFailed(__LINE__); } \
else{printf("ASSERTION TRUE! line:%d\n",__LINE__);}} while (0)

#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*
 * Simple C Test 
 */
        
int playerOne = 0;
int playerTwo = 1;
int line;


/*Added from testShuffle*/
int compare(const int* a, const int* b);
/*Part of Assertion Test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}

void test1() {
   
   /*Code borrowed to initialize the game*/
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  
  struct gameState state;
  SelectStream(2);
  PutSeed(3);
  int p,r, discardCount, handCount, count = 0;
  

  /*Sections of Code borrowed from testDrawCard Simple Fixed Test*/
  for (p = 0; p < 2; p++) {
            
          int deckCount = state.deckCount[p];
	  state.deckCount[p] = deckCount;
          
          int ret = shuffle(p,&state);
            
          ASSERTTRUE(deckCount == state.deckCount[p],__LINE__);
            
          }
}    
 


void test2() {
    
  /*Code borrowed to initialize the game*/
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  
  struct gameState state;
  SelectStream(2);
  PutSeed(3);
  int p,r, discardCount, handCount, count = 0;
 
  r = initializeGame(2, k, 1, &state);
  printf("Deck Count:%d\n",state.deckCount[0]);
  int *storedDeck1[2]; 
    for (int i=0; i<2; i++){ 
         storedDeck1[i] = (int *)malloc(state.deckCount[0] * sizeof(int));
    }
  /*Store Decks to Compare to Each Other*/
  for(int k = 0; k < state.deckCount[0]; k++){
      storedDeck1[0][k] = state.deck[0][k];
      }
 
  shuffle(0,&state);
  /*Test that Card Decks Are Not Equal*/
  for(int t = 0; t < state.deckCount[0]; t++){
      ASSERTTRUE(storedDeck1[0][t] != state.deck[0][t],__LINE__);
      }
 
  
  

}

int main(int argc, char** argv) {
 
    printf("%%SUITE_STARTING%% unittest1\n");
    printf("%%SUITE_STARTED%%\n");
    
    printf("%%TEST_STARTED%% test1 (unittest1)\n");
    
    test1();
    
    printf("%%TEST_FINISHED%%\n");

    printf("%%TEST_STARTED%% test2 (unittest1)\n");
    
    test2();
    
    printf("%%TEST_FINISHED%% test2 (unittest1) \n");

    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}
