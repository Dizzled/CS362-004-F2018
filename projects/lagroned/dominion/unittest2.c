/*
 * Assignment 3 CS362 Unit Test 2
 */

/* 
 * File: unittest2.c
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

void test1() {
   
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  int returnedCost[10] = {};
  
  printf("Size of K: %d\n",sizeof(k)/sizeof(k[0]));
  
  for(int i = 0; i < sizeof(k)/sizeof(k[0]); i++){
      returnedCost[i] = getCost(k[i]);
      printf("Card Costs: %d\n", returnedCost[i]);
     
      /*Should return cost of six for Adventurer*/
      ASSERTTRUE(getCost(k[i]) == 6,__LINE__);
      /*Should return cost of five for Council Room*/
      ASSERTTRUE(getCost(k[i]) == 5,__LINE__);
      /*Should return cost of four for Feast*/
      ASSERTTRUE(getCost(k[i]) == 4,__LINE__);
      /*Should return cost of four for Gardens*/
      ASSERTTRUE(getCost(k[i]) == 3,__LINE__);    
  }
}



int main(int argc, char** argv) {
 
    printf("%%SUITE_STARTING%% unittest1\n");
    printf("%%SUITE_STARTED%%\n");
    
    printf("%%TEST_STARTED%% test1 (unittest1)\n");
    
    test1();
    
    printf("%%TEST_FINISHED%%\n");

    printf("%%SUITE_FINISHED%%\n");

    return (EXIT_SUCCESS);
}

