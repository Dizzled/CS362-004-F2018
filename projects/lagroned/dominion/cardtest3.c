/*
 * Assignment 3 CS362 Unit Test 1
 * 
 */

/* 
 * File: cardtest3.c
 * Author: Dustin LaGrone
 * Created on October 18, 2018
 */

#define ASSERTTRUE(BoolCondition,__LINE__) do { if (!(BoolCondition)) { aFailed(__LINE__); } \
else{printf("ASSERTION TRUE! line:%d\n",__LINE__);}} while (0)
#include <time.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"
/*
 * Simple C Test Suite
 */
/*Part of the ASSERTTRUE test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}
/*First test of the village card functionality*/
void test1() {
   
    
    int card, choice1, choice2, choice3, handPosP1, handPosP2, ret,r;
    struct gameState state;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    
    /*Random Game Initialization Borrowed from betterTestDrawCard.c*/
    memset(&state, 23, sizeof(struct gameState)); 
    
    /*Discard Hand Position*/
    int handPosPlayer = 1;
    /*Test that game was initialized*/
    r = initializeGame(2, k, 1, &state);
    ASSERTTRUE(r != -1,__LINE__);
    /*Stored discard Postion*/
    int cardtoDiscard = state.hand[0][handPosPlayer];
    /*Stored Number of Actions*/
    int numberOfAction = state.numActions;
    printf("Number of Actions: %d", numberOfAction);
    /*Test Village function Discard for selected card */
 
    int cardsInHand = state.handCount[0];
        
    /*Selection for hand position to be discarded used to compare discard piles in Adventurer*/
    cardEffect(village,0,0,0,&state,handPosPlayer, 0);
       
    /*Test Players Hand Before Against After to make sure they're equal*/
    ASSERTTRUE(state.handCount[0] == cardsInHand,__LINE__);   
   
    /*Test the discard for the players hand and the played cards*/
    int sizeofPlayed = state.playedCardCount;
    for(int i = 0; i < sizeofPlayed; i++){
         ASSERTTRUE(state.playedCards[i] == cardtoDiscard,__LINE__);
    }
    
    /*Test Number of Actions increases by two*/
    numberOfAction += 2;
    ASSERTTRUE(numberOfAction == state.numActions,__LINE__);
    printf("Number of Actions: %d", state.numActions);
}
int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% cardtest3\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (cardtest3)\n");
    test1();
    printf("%%TEST_FINISHED%% test1 (cardtest3) \n");

 
    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}