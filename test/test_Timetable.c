#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include <string.h>
#include "Structure.h"
#include "Timetable.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "Rotations.h"
#include "LinkedList.h"
#include "CustomAssertion.h"
#include "TestStructure.h"
#include "ErrorCode.h"
#include "Constraints.h"
#include "mock_Random.h"
#include "malloc.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
  initVenueList();
  root = NULL;
}
void tearDown(void){}

/*
  For testing value
  #define MAX_VENUE         2
  #define MAX_DAY           3
  #define MAX_TIME_SLOT     6
  #define studyHourLimit    4
  #define teachingHourLimit 4
*/


/************************************************************************
 *  TEST of fillClassIntoTimetable
 ************************************************************************/
void test_fillClassIntoTimetable_should_throw_when_venue_index_exceeded(void){
  ClassIndex classIndex = {2,0,0};
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  ErrorCode e;
  
  Try{
    fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_VENUE_INDEX, e);
  }
}

void test_fillClassIntoTimetable_should_throw_when_day_index_exceeded(void){
  ClassIndex classIndex = {0,-1,0};
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  ErrorCode e;
  
  Try{
    fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_DAY_INDEX, e);
  }
}

void test_fillClassIntoTimetable_should_throw_when_time_index_exceeded(void){
  ClassIndex classIndex = {0,0,6};
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  ErrorCode e;
  
  Try{
    fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_TIME_INDEX, e);
  }
}

void test_fillClassIntoTimetable_should_fill_in_clazzList0_to_timeTable_0_0_0(void){
  ClassIndex classIndex = {0,0,0};
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(1, fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&timeTable[0][0][0], &clazzList[0]));
  
}

void test_fillClassIntoTimetable_should_fill_in_clazzList0_to_timeTable_1_2_5(void){
  ClassIndex classIndex = {1,2,5};
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(1, fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]));
  TEST_ASSERT_EQUAL(1, classIsNull(&timeTable[0][0][0]));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&timeTable[1][2][5], &clazzList[0]));
  
}

void test_fillClassIntoTimetable_should_fill_in_2_classes_to_000_and_111(void){
  ClassIndex classIndex = {0,0,0};
  ClassIndex classIndex2 = {1,2,5};
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(1, fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]));
  TEST_ASSERT_EQUAL(1, fillClassIntoTimetable(timeTable, &classIndex2, &clazzList[0]));
  
  TEST_ASSERT_EQUAL(1, checkEqualClass(&timeTable[1][2][5], &clazzList[0]));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&timeTable[0][0][0], &clazzList[0]));
  
}

/************************************************************************
 *  TEST of successfulAddWithoutConstraint
 ************************************************************************/
void test_successfulAddWithoutConstraints_should_return_1_and_fill(){
  
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  clearTimeTable(newClass);
  ClassIndex ttIndex = {1,0,0};
  
  
  TEST_ASSERT_EQUAL(1, successfulAddWithoutConstraint(newClass,&ttIndex, 0, 0));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&newClass[1][0][0], &clazzList[0]));
}

void test_successfulAddWithoutConstraints_should_return_0_if_occupied(){
  
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  clearTimeTable(newClass);
  newClass[1][0][0] = clazzList[0];
  ClassIndex ttIndex = {1,0,0};
  
  
  TEST_ASSERT_EQUAL(0, successfulAddWithoutConstraint(newClass,&ttIndex, 0, 0));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&newClass[1][0][0], &clazzList[0]));
}

void test_successfulAddWithoutConstraints_should_return_0_if_null_but_have_constraints(){
  
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  clearTimeTable(newClass);
  newClass[1][0][0] = clazzList[0];
  ClassIndex ttIndex = {0,0,0};
  
  
  TEST_ASSERT_EQUAL(0, successfulAddWithoutConstraint(newClass,&ttIndex, 0, 0));
}

void test_successfulAddWithoutConstraints_should_add_2nd_class_and_return_1(){
  
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  clearTimeTable(newClass);
  newClass[1][0][0] = clazzList[0];
  ClassIndex ttIndex = {1,0,1};
  
  
  TEST_ASSERT_EQUAL(1, successfulAddWithoutConstraint(newClass,&ttIndex, 0, 0));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&newClass[1][0][0], &clazzList[0]));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&newClass[1][0][1], &clazzList[0]));
}


/************************************************************************
 *  TEST of insertPopulationIntoRBT
 ************************************************************************/
void test_insertPopulationIntoRBT__should_add_1_population(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  TTPopulation *population = malloc(sizeof(TTPopulation));
  
  memcpy(population->timeTable, newClass, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population->violations = 5;
  
  insertPopulationIntoRBT(population);
  
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);
}

void test_insertPopulationIntoRBT__should_add_2_population(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  Class newClass2[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TTPopulation *population = malloc(sizeof(TTPopulation));
  TTPopulation *population2 = malloc(sizeof(TTPopulation));
  
  memcpy(population->timeTable, newClass, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population->violations = 5;
  memcpy(population2->timeTable, newClass2, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population2->violations = 10;
  
  insertPopulationIntoRBT(population);
  insertPopulationIntoRBT(population2);
  
  TEST_ASSERT_EQUAL(5, root->timeTable->violations);
  TEST_ASSERT_EQUAL(10, root->right->timeTable->violations);
}

void test_insertPopulationIntoRBT__should_add_2_same_violation_population_into_list(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  Class newClass2[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TTPopulation *population = malloc(sizeof(TTPopulation));
  TTPopulation *population2 = malloc(sizeof(TTPopulation));
  
  memcpy(population->timeTable, newClass, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population->violations = 5;
  memcpy(population2->timeTable, newClass2, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population2->violations = 5;
  
  insertPopulationIntoRBT(population);
  insertPopulationIntoRBT(population2);
  
  TEST_ASSERT_EQUAL(5, root->timeTable->violations);
  TEST_ASSERT_EQUAL(1, root->list.length);
  TEST_ASSERT_EQUAL(5, root->list.head->timeTable->violations);
  TEST_ASSERT_NULL(root->list.head->next);

}

void test_insertPopulationIntoRBT__should_add_3_populations_2nd_3rd_same_violation(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  Class newClass2[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  Class newClass3[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TTPopulation *population = malloc(sizeof(TTPopulation));
  TTPopulation *population2 = malloc(sizeof(TTPopulation));
  TTPopulation *population3 = malloc(sizeof(TTPopulation));
  
  memcpy(population->timeTable, newClass, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population->violations = 10;
  memcpy(population2->timeTable, newClass2, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population2->violations = 5;
  memcpy(population3->timeTable, newClass3, sizeof(Class)*MAX_VENUE*MAX_DAY*MAX_TIME_SLOT);
  population3->violations = 5;
  
  insertPopulationIntoRBT(population);
  insertPopulationIntoRBT(population2);
  insertPopulationIntoRBT(population3);
  
  TEST_ASSERT_EQUAL(10, root->timeTable->violations);
  TEST_ASSERT_NULL(root->list.head);
  
  TEST_ASSERT_EQUAL(5, root->left->timeTable->violations);
  TEST_ASSERT_EQUAL(1, root->left->list.length);
  TEST_ASSERT_EQUAL(5, root->left->list.head->timeTable->violations);
  TEST_ASSERT_NULL(root->left->list.head->next);
}
















