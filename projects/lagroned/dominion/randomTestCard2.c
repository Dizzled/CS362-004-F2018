/*
 * This is a random tester of the great hall
 */

/* 
 * File:   randonTestCard3.c
 * Author: root
 *
 * Created on November 13, 2018
 */

#define ASSERTTRUE(BoolCondition,__LINE__) do { if (!(BoolCondition)) { aFailed(__LINE__); } \
else{printf("ASSERTION TRUE! line:%d\n",__LINE__);}} while (0)

#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "limits.h"

/*
 * Simple C Test Suite
 */

/*Part of the ASSERTTRUE test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}

int checkGreatHall(int handPos, int player, struct gameState* post){
    
    post->whoseTurn = player;
    struct gameState pre;
    
    memcpy(&pre,post,sizeof(struct gameState));
    
    /*Stored discarded Card*/
    int cardtoDiscard = pre.hand[player][handPos];
    /*Stored number of Actions*/
    int numberOfAction = pre.numActions;
    /*Stored card to be drawn from deck*/
    int drawnCard = pre.deck[player][pre.deckCount[player] - 1];
    
    cardEffect(great_hall,0,0,0,post,handPos, 0);
    
    /*Test drawn card in players hand*/
    ASSERTTRUE(drawnCard == post->hand[player][handPos],__LINE__);
    
    if(post->hand[player][0] == -1){
        printf("Hand Count Value: 0\nNo Cards in hand!!\n");
    }
    /*Test Number of actions*/
    ASSERTTRUE(numberOfAction + 1 == post->numActions,__LINE__);
    /*Test discard pile for hand Pos card discarded*/
    ASSERTTRUE(cardtoDiscard == post->playedCards[post->playedCardCount - 1],__LINE__);
    
    return 0;
    
    
}
void test1() {
        
    
    struct gameState state;
    /*Random Game Initialization Borrowed from betterTestDrawCard.c*/
    SelectStream(2);
    PutSeed(3);  
    
    
    for(int numberOfRun = 0; numberOfRun <  10000; numberOfRun++){
    
    
    int  player = floor(Random() * 2);
        
    /*Modify the Deck with randomly initialized values
     * To check if the adventurer function is selecting 
     * Copper, Silver or Gold*/  
    state.deckCount[player] = floor(Random() * MAX_DECK);
    state.discardCount[player] = floor(Random() * MAX_DECK);
    state.playedCardCount = floor(Random() * MAX_DECK);
    state.handCount[player] = floor(Random() * MAX_HAND);
        
    for(int i = 0; i < state.deckCount[player]; i++){
        state.deck[player][i] = floor(Random() * 10);
    }
        
    /*Randomize each card in randomized hand count*/
    for(int k = 0; k < state.handCount[player]; k++){
        state.hand[player][k] = floor(Random() * 27);
    }
    
    for(int s = 0; s < state.playedCardCount; s++){
        state.playedCards[s] = floor(Random() * 27);
    }
        
    /*Randomize the positions in the players hand*/
    int handPos = floor(Random() * state.handCount[player]);
    ASSERTTRUE(checkGreatHall(handPos, player, &state)== 0,__LINE__); 
   
    }
}
int main(int argc, char** argv) {
    
    printf("%%SUITE_STARTING%% randomTestCard3\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (randomTestCard3)\n");
    
    clock_t start, stop;
    
    start = clock();
    test1();
    stop = clock();
    
    double totalTime = ((double)(stop - start) / CLOCKS_PER_SEC);
   
    printf("%%TEST_FINISHED%% \n");
    
    printf("Time taken:%.3f\n", totalTime);

    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}
