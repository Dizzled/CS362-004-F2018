/*
 * Assignment 3 CS362 Unit Test 1
 * 
 */

/* 
 * File: cardtest1.c
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
 * Simple C Test Suite
 */
/*Part of the ASSERTTRUE test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}
/*First test of the smithy card functionality*/
void test1() {
    int* bonus;
    int card, choice1, choice2, choice3, handPos, ret,r;
    struct gameState state;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    
    
    /*Initialize Game*/
    memset(&state, 23, sizeof(struct gameState)); 
    
    r = initializeGame(2, k, 1, &state);
    /*Test that game was initialized*/
    ASSERTTRUE(r != -1,__LINE__);

   /*Test the Hand Count for Each of the Two Players*/
    for(int i = 0; i < state.numPlayers; i++){
        /*Adds an additional three cards with one discard*/
        state.whoseTurn = i;
        int storedHandCount = state.handCount[i]+2;
        int storedPlayedCard = state.playedCardCount;
        
        ret = cardEffect(smithy,0,0,0,&state,1, 0);
        
        ASSERTTRUE(state.handCount[i] == storedHandCount,__LINE__);
      
        ASSERTTRUE(state.playedCardCount > storedPlayedCard ,__LINE__);
        printf("Current Played Count Player[%d]:%d\n",i,state.playedCardCount);

    }
    
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% cardtest1\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (cardtest1)\n");
    test1();
    printf("%%TEST_FINISHED%% test1 (cardtest1) \n");

 
    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
