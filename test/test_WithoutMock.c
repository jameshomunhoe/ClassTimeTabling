#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include <string.h>
#include "Structure.h"
#include "Mutation.h"
#include "Crossover.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "Rotations.h"
#include "LinkedList.h"
#include "CustomAssertion.h"
#include "Constraints.h"
#include "TestStructure.h"
#include "Timetable.h"
#include "Random.h"
#include "malloc.h"

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

/************************************************************************
 *  TEST of createSinglePopulation
 ************************************************************************/
void test_createSinglePopulation_should_fill_in_class_and_violation(){
  
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  TTPopulation *noob = NULL;
  ClassIndex ttIndex = {0,0,0};
  int i;
  
  noob = createSinglePopulation(newClass);

  printf("violations in population %d\n",noob->violations);
  
  for(i = 0 ; i < MAX_VENUE*MAX_DAY*MAX_TIME_SLOT ; i++){
    TEST_ASSERT_EQUAL(1, updateGroupCounterFromClassWithSignal(&(noob->timeTable[ttIndex.venue][ttIndex.day][ttIndex.time])));
    indexForward(&ttIndex);
  }
}

/************************************************************************
 *  TEST of createPopulationsOfTimeTable
 ************************************************************************/
void test_createPopulationsOfTimeTable_should_not_gives_error(){
  
  root = NULL;
  createPopulationsOfTimeTable(100);
  
  TEST_ASSERT_NOT_NULL(root);
  TEST_ASSERT_NOT_NULL(root->left);
  TEST_ASSERT_NOT_NULL(root->right);
  
  int i = 1;
  
  Node *node = malloc(sizeof(Node));
  Element *elem = malloc(sizeof(Element));
  
  while(i<=100){
    node = removeNextLargerSuccessor(&root);
    
    while(node->list.length > 0){
      elem = listRemoveFirst(&node->list);
      printf("node(list) %d : %d\n", i, elem->timeTable->violations);
      i++;
    }
      printf("node(node) %d : %d\n", i, node->timeTable->violations );
      i++;
  }
}