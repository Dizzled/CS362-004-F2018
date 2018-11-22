/*
 * This is a random tester of the Smithy card
 * 
 * 
 */

/* 
 * File:   randomTestCard2.c
 * Author: Dustin LaGrone
 * November 11, 2018
 */

#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#define ASSERTTRUE(BoolCondition,__LINE__) do { if (!(BoolCondition)) { aFailed(__LINE__); } \
else{printf("ASSERTION TRUE! line:%d\n",__LINE__);}} while (0)
/*
 * Simple C Test Suite
 */

/*Part of the ASSERTTRUE test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}
/*Function takes in Randomized game state and checks values for card*/
int checkSmithyCard(int handPos, int player, struct gameState* post){
    
    post->whoseTurn = player;
    struct gameState pre;
    
    memcpy(&pre,post, sizeof(struct gameState));
    
    int* storedDrawCards = (int*)malloc( 3 * sizeof(int));
    int storedHandPos = post->hand[player][handPos];
    int topOfDeck = post->deckCount[player] - 1;
    
    /*Check the stored drawn cards from the players deck vs the hand*/
    if(post->deckCount[player] <= 0){
        
        shuffle(player,&pre);
        topOfDeck = post->deckCount[player] - 1;
        
        for(int i = 0; i < 3; i++){
            
            storedDrawCards[i] = pre.deck[player][topOfDeck];
        }   
    }else{
        
        for(int k = 0; k < 3; k++){
            storedDrawCards[k] = pre.deck[player][topOfDeck];
            topOfDeck--;
        }
    }
    
    int drawncards = 0;
    
    cardEffect(smithy,0,0,0,post,handPos, 0);
    
    int handCount = post->handCount[player] - 1;
   
    for(int k = 2; k >= 0; k--){
        if(storedDrawCards[k] == post->hand[player][handCount]){
            printf("Draw cards Match Hand\n");
            drawncards++;
            handCount--;
         /*Test the discard function for the cards drawn being placed at handPos*/
        }else if(storedDrawCards[k] == post->hand[player][handPos]){
            printf("Draw cards Match Hand\n");
            drawncards++;
        }
    }      
       
    /*Checks that three cards drawn from deck match cards in hand*/
    ASSERTTRUE(drawncards == 3,__LINE__);
    
    /*Check that three cards were drawn with one discard*/
    ASSERTTRUE(pre.handCount[player] + 2 == post->handCount[player],__LINE__);
    if(pre.handCount[player] + 2 != post->handCount[player]){
        printf("Pre Hand:%d\nPost Hand:%d\n", pre.handCount[player],post->handCount[player]);
    }
    /*Check that the card from hand position was discarded*/
    ASSERTTRUE(post->playedCards[post->playedCardCount - 1] == storedHandPos,__LINE__);
    
    return 0;
    
}
void test1() {

    struct gameState state;
    
        /*Random Game Initialization Borrowed from betterTestDrawCard.c*/
        SelectStream(2);
        PutSeed(3);
    
    for(int numberOfRun = 0; numberOfRun <  10000; numberOfRun++){
        
                int  player = floor(Random() * MAX_PLAYERS);
        
        state.whoseTurn = player;
        
        /*Modify the Deck with randomly initlized values
         * To check if the adventurer function is selecting 
         * Copper, Silver or Gold*/
        state.deckCount[player] = floor(Random() * MAX_DECK);
        state.playedCardCount = 0;
       
        for(int i = 0; i < state.deckCount[player]; i++){
          
            state.deck[player][i] = floor(Random() * 27);
        }
        
        state.handCount[player] = floor(Random() * MAX_HAND);
        
        
        /*Randomize each card in randomized hand count*/
        for(int k = 1; k < state.handCount[player]; k++){
            state.hand[player][k] = floor(Random() * 100);
        }
        /*Randomly initiate a discard Pile with cards*/
        for(int a = 0; a < state.discardCount[player]; a++){
            state.discard[player][a] = floor(Random() * 27);
        
        }
        /*Randomly Distribute Supply*/
        for(int m = 0; m < 27; m++){
            state.supplyCount[m] = floor(Random() * 27);
        }
        
        int handPos = 0;
        /*Add the Adventurer card to the players hand to be used*/
        for(int x = 0; x < state.handCount[player]; x++){
            if(state.hand[player][x] == smithy){
                handPos = x;
                printf("Smithy found in Hand!!!\n");
            }
        }
        if(handPos == 0){
            
            ASSERTTRUE(gainCard(smithy,&state,2,player)== 0,__LINE__);
            handPos = state.handCount[player] - 1;
            printf("Smithy Added to Hand!!!\n");        
        }
        ASSERTTRUE(checkSmithyCard(handPos, player, &state)== 0,__LINE__);
        
        }
}


int main(int argc, char** argv) {
     
    printf("%%SUITE_STARTING%% randomtestcard2\n");

    printf("%%TEST_STARTED%% test1\n");
    
    clock_t start, stop;
    
    start = clock();
    test1();
    stop = clock();
    
    double totalTime = ((double)(stop - start) / CLOCKS_PER_SEC);
   
    printf("%%TEST_FINISHED%% \n");
    
    printf("Time taken:%.3f\n", totalTime);

    printf("%%SUITE_FINISHED%% \n");

    return (EXIT_SUCCESS);
}
