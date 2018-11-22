/*
 * This is a random tester of the Adventurer card
 * 
 */

/* 
 * File:   randomtestcard1.c
 * Author: Dustin LaGrone
 * November 6, 2018
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

/*
 * Simple C Test Suite
 */
/*Part of the ASSERTTRUE test*/
void aFailed(int line){
    
    printf("ASSERTION FALSE! line: %d\n",line);
}

int checkAdventurerCard(int player, struct gameState* post, int handPos){
    
    
    struct gameState pre;
    
    memcpy(&pre,post, sizeof(struct gameState));
    
    int discardAfter, treasureBefore = 0, treasureAfter = 0, count = 0;
    
    /*Dont Forget to Free Used to Test Treasure in Deck Against Treasure in Hand*/
    int* storedTreasure = (int*)malloc( 2 * sizeof(int));
    
    /*Need to test against the the Deck to check and see what cards
     *Are going to be drawn store those and verify they are in fact in the hand*/
    int storedDeckCount = post->deckCount[player] - 1;
    int storedHandCount = post->handCount[player];
    
    if(storedDeckCount < 0){
        printf("Deck Uninitialized!!\n");
        return 1;
    }
    if(storedHandCount <= 0){
        printf("Hand Uninitialized!!\n");
        return 1;
    }
    
    int storedDiscardCount = pre.discardCount[player];
    
    while(count < 2){
        
        if(post->deck[player][storedDeckCount] == copper){
            
            printf("Struck Copper! Stored @ %d\n",count);
            storedTreasure[count] = post->deck[player][storedDeckCount];
            post->deck[player][storedDeckCount--];
            count++;
            
        }else if(post->deck[player][storedDeckCount] == silver){
            
            printf("Struck Silver! Stored @ %d\n",count);
            storedTreasure[count] = post->deck[player][storedDeckCount];
            post->deck[player][storedDeckCount--];
            count++;
            
        }else if(post->deck[player][storedDeckCount] == gold){
            
            printf("Struck Gold! Stored @ %d\n",count);
            storedTreasure[count] = post->deck[player][storedDeckCount];
            post->deck[player][storedDeckCount--];
            count++;
            
        }else{
            
            storedDiscardCount++; //Card is not treasure and will be discarded;
            post->deck[player][storedDeckCount--]; //Decrement the deck for the next potential treasure
        }
    }
    
    for(int i = 0; i < count; i++){
        if(storedTreasure[i] != copper && storedTreasure[i] != silver && storedTreasure[i] != gold){
            printf("NO TREASURE IN DECK!!\n");
                    
        }
    }
    ASSERTTRUE(storedTreasure != NULL,__LINE__);
    //discardBefore = post->discardCount[player];
    
    cardEffect(adventurer,0,0,0,post,handPos, 0);
    
    discardAfter = post->discardCount[player];
    
    /*Check the discard Pile to see if cards that were drawn are also discarded*/
    ASSERTTRUE(storedDiscardCount == discardAfter,__LINE__);
    if(storedDiscardCount != discardAfter){
        printf("stored cards not equal:\nExpected Discard Count:%d\nDiscard Count After:%d\n",storedDiscardCount,discardAfter);
    }
    
    for(int j = 0; j < pre.handCount[player]; j++){        
                              
            if(pre.hand[player][j] == copper){
                //printf("Copper Found:Player %d\n",k);
                treasureBefore++;
            }else if(pre.hand[player][j] == gold){
                //printf("Gold Found:Player %d\n",k);
                treasureBefore++;
                }
            else if(pre.hand[player][j] == silver){
                //printf("Silver Found:Player %d\n",k);
                treasureBefore++;    
                }
        }
    
    treasureAfter = treasureBefore;
    /*Post Test Case for last added cards to check against Deck Treasure Cards to be drawn.3*/
    for(int k = 1; k >= 0; k--){
        for(int j = post->handCount[player] - 1; j >= 0; j--){        
                
                if(post->hand[player][j] == copper && post->hand[player][j] == storedTreasure[k]){
                    
                    printf("Copper Found and Added:Player %d\n",player);
                    treasureAfter++;
                    k--;
                }else if(post->hand[player][j] == gold && post->hand[player][j] == storedTreasure[k]){
                    
                    printf("Gold Found and Added:Player %d\n",player);
                    treasureAfter++;
                    k--;
                    
                }else if(post->hand[player][j] == silver && post->hand[player][j] == storedTreasure[k]){
                    
                    printf("Silver Found and Added:Player %d\n",player);
                    treasureAfter++;
                    k--;
                }
            }
        
    }
    /*Check that there's more treasure cards in the hand */
    if(treasureBefore == treasureAfter){
        printf("No Additional Treasure in Deck\n");
    }
    ASSERTTRUE(treasureBefore < treasureAfter,__LINE__);
    int preHand = pre.handCount[player];
    int postHand = post->handCount[player];
    /*Check that only two cards have been added to the hand*/
    ASSERTTRUE(preHand + 1 == postHand,__LINE__);
    
    if(preHand + 1 != postHand){
        printf("Pre-Hand:%d\nPost-Hand:%d\n",preHand,postHand);
    }
    free(storedTreasure);
    return 0;
        
}
void test1() {
    
    struct gameState state; 
    /*Test to see if silver, copper or gold are present in deck if zero need to initalize the deck with treasure*/
    SelectStream(2);
    PutSeed(3);
    
    for(int numberOfRun = 0; numberOfRun <  10000; numberOfRun++){
       
        /*Random Game Initialization Borrowed from betterTestDrawCard.c*/
        
       
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
            if(state.hand[player][x] == adventurer){
                handPos = x;
                printf("Adventurer found in Hand!!!\n");
            }
        }
        if(handPos == 0){
            
            ASSERTTRUE(gainCard(adventurer,&state,2,player)== 0,__LINE__);
            handPos = state.handCount[player] - 1;
            printf("Adventurer Added to Hand!!!\n");        
        }
        
        ASSERTTRUE(checkAdventurerCard(player, &state, handPos) == 0,__LINE__);
    }
}
     
 

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% randomtestcard1\n");
    

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
