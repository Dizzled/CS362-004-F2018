/*
 * Assignment 3 CS362 Unit Test 3
 * 
 */

/* 
 * File: unittest3.c
 * Author: Dustin LaGrone
 * Created on October 18, 2018
 */


#define ASSERTTRUE(BoolCondition,__LINE__) do { if (!(BoolCondition)) { aFailed(__LINE__); } \
else{printf("ASSERTION TRUE! line:%d\n",__LINE__);}} while (0)

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

void test1() {
   
    struct gameState state;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    int p, deckCount, discardCount,handCount,r, gameOver;
    
    /*Intialize the game*/
    memset(&state, 23, sizeof(struct gameState)); 
    r = initializeGame(2, k, 1, &state);
    state.supplyCount[province] = 8;
    
    for(int i = 8; i > -1; i--){
        
       printf("Number of Province Cards: %d\n", i); 
       gameOver = isGameOver(&state);
       printf("Game Over Return: %d\n", gameOver);
       ASSERTTRUE(gameOver == 1,__LINE__);
       /*Remove a province card*/
       state.supplyCount[province]--;
    }
    
}

void test2() {
   
    struct gameState state;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};
    int p, deckCount, discardCount,handCount,r, gameOver;
    
    /*Intialize the game with two players*/
    memset(&state, 23, sizeof(struct gameState)); 
    r = initializeGame(2, k, 1, &state);
    state.supplyCount[province] = 8;
    
    for(int k = 0; k < 27; k++){
        /*Zero Out the values for all cards*/
        state.supplyCount[k] = 0;
        printf("Supply Count Starting Quantities: %d\n", state.supplyCount[k]);
    }
    
    
    /*
     * Checking the gameover test for if three supply piles
     * are at 0
     */
    gameOver = 1;
    int i = 0;
    while(gameOver == 1){
       
       gameOver = isGameOver(&state);
       printf("Game Over Return: %d\n", gameOver);
       ASSERTTRUE(gameOver == 1,__LINE__);
       /*Remove a province card*/
       state.supplyCount[i]+=3;
       printf("Supply Values for Cards at %d = %d\n", i, state.supplyCount[i]);
       i++;
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

    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}
