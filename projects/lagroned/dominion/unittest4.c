/*
 * Assignment 3 CS362 Unit Test 1
 * 
 */

/* 
 * File: unittest4.c
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
        
/*Added from testShuffle*/
int compare(const int* a, const int* b);
/*Part of Assertion Test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}
/*Test for uninitialized and Game State Initialized*/
void test1() {
   struct gameState state;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    int p, deckCount, discardCount,handCount,r, gameOver;
    
    int player = whoseTurn(&state);
    
    /*Uninitialized turn = 0*/
    printf("Player %d Turn\n", player);
    ASSERTTRUE((whoseTurn(&state) == NULL),__LINE__);
    
    /*Intialize the game*/
    memset(&state, 23, sizeof(struct gameState)); 
    
    r = initializeGame(2, k, 1, &state);
    
    state.whoseTurn = 4;
    player = whoseTurn(&state);
    printf("Player %d Turn\n", player);
    ASSERTTRUE((whoseTurn(&state) == 0),__LINE__);
 
}
/*Test for return values for initialized game with incorrect whose turn input*/
void test2() {
    struct gameState state;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    r = initializeGame(2, k, 1, &state);
    
    state.whoseTurn = 15693250560;
    int player = whoseTurn(&state);
    printf("Player %d Turn\n", player);
    ASSERTTRUE((whoseTurn(&state) > 0),__LINE__);
 
}

int main(int argc, char** argv) {
 
    printf("%%SUITE_STARTING%% unittest4\n");
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
