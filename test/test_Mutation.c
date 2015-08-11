#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include "Mutation.h"
#include "Constraints.h"
#include "Structure.h"
#include "TestStructure.h"
#include "mock_Random.h"


void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
  initVenueList();
}
void tearDown(void){}

void test_performMutation(){
  
  Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  classToMutate[0][0][0] = clazzList[0];
  classToMutate[1][0][0] = clazzList[1];
  
  
  randomVenue_ExpectAndReturn(0);
  randomDay_ExpectAndReturn(0);
  randomTime_ExpectAndReturn(0);
  
  randomVenue_ExpectAndReturn(1);
  randomDay_ExpectAndReturn(0);
  randomTime_ExpectAndReturn(1);
  
  mutationSwapOnce(classToMutate);
  
}