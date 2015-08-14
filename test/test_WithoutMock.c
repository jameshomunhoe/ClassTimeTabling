#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include "Mutation.h"
#include "Crossover.h"
#include "Constraints.h"
#include "Structure.h"
#include "TestStructure.h"
#include "Timetable.h"
#include "Random.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
  initVenueList();
  initRandom();
}
void tearDown(void){}

/************************************************************************
 *  TEST of performMutation
 ************************************************************************/
void test_performMutation_should_able_to_reduce_violation_of_a_timeTable(){
  
  Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  int violationBefore = 0;
  int violationAfter = 0;
  int i = 0;
  ClassIndex osIndex = {0,0,0};
  
  createTimeTable(classToMutate);
  
  violationBefore = calculateTotalViolationInTimetable(classToMutate);
  printf("Violation before %d\n",violationBefore);
  
  performMutation(classToMutate,100);
  
  violationAfter = calculateTotalViolationInTimetable(classToMutate);
  printf("Violation after  %d\n",violationAfter);
  
  for(i = 0 ; i < MAX_VENUE*MAX_DAY*MAX_TIME_SLOT ; i++){
    TEST_ASSERT_EQUAL(1, updateGroupCounterFromClassWithSignal(&classToMutate[osIndex.venue][osIndex.day][osIndex.time]));
    indexForward(&osIndex);
  }
}

/************************************************************************
 *  TEST of performCrossover
 ************************************************************************/
void test_performCrossover_should_retain_elements(){
  
  Class father[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  Class mother[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  Class offSpring[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  int violationFather = 0;
  int violationMother = 0;
  int violationOffSpring = 0;
  int i;
  ClassIndex osIndex = {0,0,0};
  
  createTimeTable(father);
  createTimeTable(mother);
  
  violationFather = calculateTotalViolationInTimetable(father);
  violationMother = calculateTotalViolationInTimetable(mother);
  printf("Violation of Father before %d\n",violationFather);
  printf("Violation of Mother before %d\n",violationMother);
  
  performCrossover(father, mother, offSpring, MAX_VENUE);
  
  violationOffSpring = calculateTotalViolationInTimetable(offSpring);
  printf("Violation of offSpring %d\n",violationOffSpring);
  
  
  for(i = 0 ; i < MAX_VENUE*MAX_DAY*MAX_TIME_SLOT ; i++){
    TEST_ASSERT_EQUAL(1, updateGroupCounterFromClassWithSignal(&offSpring[osIndex.venue][osIndex.day][osIndex.time]));
    indexForward(&osIndex);
  }
  
}

/************************************************************************
 *  TEST of createTimeTable
 ************************************************************************/
void test_createTimeTable_should_able_to_create_timeTable(){
  
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  
  createTimeTable(timeTable);
  
  int i;
  ClassIndex classIndex = {0,0,0};
  initClassCounter();
  for(i = 0 ; i < MAX_VENUE*MAX_DAY*MAX_TIME_SLOT ; i++){
    
    TEST_ASSERT_EQUAL(1, updateGroupCounterFromClassWithSignal(&timeTable[classIndex.venue][classIndex.day][classIndex.time]));
    
    indexForward(&classIndex);
  }
    TEST_ASSERT_EQUAL(0, updateGroupCounterFromClassWithSignal(&timeTable[classIndex.venue][classIndex.day][classIndex.time]));
  
}
