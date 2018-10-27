/*
 * Assignment 3 CS362 Unit Test 1
 * 
 */

/* 
 * File: cardtest2.c
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
#include "interface.h"
/*
 * Simple C Test Suite
 */
/*Part of the ASSERTTRUE test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}
/*First test of the adventurer card functionality*/
void test1() {
    int treasureBefore = 0, treasureAfter = 0, discardBeforeP1 = 0, discardAfterP1 = 0;
    int* bonus;
    int card, choice1, choice2, choice3, handPos, ret,r;
    struct gameState state;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    
    
    /*Random Game Initialization Borrowed from betterTestDrawCard.c*/
    memset(&state, 23, sizeof(struct gameState)); 
    r = initializeGame(2, k, 1, &state);
    
    /*Test that game was initialized*/
    ASSERTTRUE(r != -1,__LINE__);
    /*Test to see if silver, copper or gold are present in deck if zero need to initalize the deck with treasure*/
    for(int k = 0; k < 2; k++ ){
        for(int j = 0; j < 5; j++){        
                              
                if(state.hand[k][j] == copper){
                    //printf("Copper Found:Player %d\n",k);
                    treasureBefore++;
                }else if(state.hand[k][j] == gold){
                    //printf("Gold Found:Player %d\n",k);
                    treasureBefore++;
                    }
                else if(state.hand[k][j] == silver){
                    //printf("Silver Found:Player %d\n",k);
                    treasureBefore++;    
                }
            }
       
        }
    /*Test to compare before and after Adventurer card is played*/
    for(int k = 0; k < 2; k++ ){
        state.whoseTurn = k;
        discardBeforeP1 = state.discardCount[k];
        cardEffect(adventurer,0,0,0,&state,0, 0);
        
        for(int j = 0; j < 5; j++){        
                
                if(state.hand[k][j] == copper){
                    printf("Copper Found:Player %d\n",k);
                    treasureAfter++;
                }else if(state.hand[k][j] == gold){
                    printf("Gold Found:Player %d\n",k);
                    treasureAfter++;
                    }
                else if(state.hand[k][j] == silver){
                    printf("Silver Found:Player %d\n",k);
                    treasureAfter++;    
                }
            }
        /*Check the discard Pile to see if cards were discarded for player 1 only*/
         ASSERTTRUE(discardBeforeP1 < state.discardCount[k],__LINE__);
        }
    /*Check whether there is more treasure*/
    ASSERTTRUE(treasureBefore < treasureAfter,__LINE__);
    
    

}
int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% cardtest2\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (cardtest2)\n");
    test1();
    printf("%%TEST_FINISHED%% test1 (cardtest2) \n");

 
    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}