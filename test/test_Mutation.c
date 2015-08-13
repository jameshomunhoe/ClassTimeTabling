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

/************************************************************************
 *  TEST of shouldMutate
 ************************************************************************/
void test_shouldMutate_should_return_0_when_constraint_and_totalViolation_after_are_higher(){
  int constraintsBefore = 0;
  int constraintsAfter = 1;
  int totalViolationBefore = 0;
  int totalViolationAfter = 1;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(0, result);
}

void test_shouldMutate_should_return_0_when_constraint_higher_totalViolation_lower(){
  int constraintsBefore = 0;
  int constraintsAfter = 1;
  int totalViolationBefore = 100;
  int totalViolationAfter = 0;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(0, result);
}

void test_shouldMutate_should_return_0_when_constraints_maintain_but_violation_Higher(){
  int constraintsBefore = 1;
  int constraintsAfter = 1;
  int totalViolationBefore = 0;
  int totalViolationAfter = 100;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(0, result);
}

void test_shouldMutate_should_return_1_when_constraints_and_totalViolation_lower(){
  int constraintsBefore = 1;
  int constraintsAfter = 0;
  int totalViolationBefore = 100;
  int totalViolationAfter = 0;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(1, result);
}

void test_shouldMutate_should_return_1_when_constraints_lower_but_totalViolation_higher(){
  int constraintsBefore = 1;
  int constraintsAfter = 0;
  int totalViolationBefore = 0;
  int totalViolationAfter = 100;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(1, result);
}

void test_shouldMutate_should_return_0_when_constraints_maintain_but_violation_lower(){
  int constraintsBefore = 1;
  int constraintsAfter = 1;
  int totalViolationBefore = 1000;
  int totalViolationAfter = 1;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(1, result);
}

void test_shouldMutate_should_return_0_when_both_constraints_violation_maintain(){
  int constraintsBefore = 1;
  int constraintsAfter = 1;
  int totalViolationBefore = 1;
  int totalViolationAfter = 1;
  int result;
  
  result = shouldMutate(constraintsBefore, constraintsAfter, \
                        totalViolationBefore, totalViolationAfter);
                        
  TEST_ASSERT_EQUAL(1, result);
}

/************************************************************************
 *  TEST of getTotalViolationsFromTwoClass
 ************************************************************************/
void test_getTotalViolationsFromTwoClass_should_return_22(){
  
  ClassIndex source = {0,0,0};
  ClassIndex goal = {1,0,1};
  Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  int constraintsAfter = 0;
  int fitnessAfter = 0;
  int totalViolationAfter = 0;
  
  classToMutate[0][0][0] = clazzList[0];
  classToMutate[1][0][0] = clazzList[1];

  totalViolationAfter = getTotalViolationsFromTwoClass(classToMutate, &source, &goal, \
                                                       &constraintsAfter, &fitnessAfter);
                                                       
  TEST_ASSERT_EQUAL(22, totalViolationAfter); 
}

void test_getTotalViolationsFromTwoClass_should_return_0(){
  
  ClassIndex source = {1,0,0};
  ClassIndex goal = {1,0,1};
  Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  int constraintsAfter = 0;
  int fitnessAfter = 0;
  int totalViolationAfter = 0;
  
  classToMutate[1][0][0] = clazzList[0];
  classToMutate[1][0][1] = clazzList[1];
  
  totalViolationAfter = getTotalViolationsFromTwoClass(classToMutate, &source, &goal, \
                                                       &constraintsAfter, &fitnessAfter);
                                                       
  TEST_ASSERT_EQUAL(0, totalViolationAfter); 
}


/************************************************************************
 *  TEST of mutationSwapOnce
 ************************************************************************/
void test_mutationSwapOnce_should_change_both_element_and_reduce_total_violation(){
  
  Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  int violationBefore = 0;
  int violationAfter = 0;
  
  classToMutate[0][0][0] = clazzList[0];
  classToMutate[1][0][0] = clazzList[1];
  
  violationBefore = calculateTotalViolationInTimetable(classToMutate);
  
  randomVenue_ExpectAndReturn(0);
  randomDay_ExpectAndReturn(0);
  randomTime_ExpectAndReturn(0);
  
  randomVenue_ExpectAndReturn(1);
  randomDay_ExpectAndReturn(0);
  randomTime_ExpectAndReturn(1);
  
  mutationSwapOnce(classToMutate);
  violationAfter = calculateTotalViolationInTimetable(classToMutate);
  
  TEST_ASSERT_EQUAL(1, classIsNull(&classToMutate[0][0][0]));
  TEST_ASSERT_EQUAL(0, classIsNull(&classToMutate[1][0][1]));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&classToMutate[1][0][1], &clazzList[0]));
  TEST_ASSERT_EQUAL(22, violationBefore);
  TEST_ASSERT_EQUAL(0, violationAfter);
  
}

void test_mutationSwapOnce_should_reduce_violation(){
  
  Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  int violationBefore = 0;
  int violationAfter = 0;
  
  classToMutate[0][0][0] = clazzList[0];//student overload 17
  classToMutate[1][0][1] = clazzList[1];
  classToMutate[0][0][2] = clazzList[2];
  classToMutate[1][0][3] = clazzList[10];
  classToMutate[1][0][4] = clazzList[11]; //2 Group exceed 4 hours study = 2
  
  violationBefore = calculateTotalViolationInTimetable(classToMutate);
  
  randomVenue_ExpectAndReturn(0);
  randomDay_ExpectAndReturn(0);
  randomTime_ExpectAndReturn(0);
  
  randomVenue_ExpectAndReturn(1);
  randomDay_ExpectAndReturn(1);
  randomTime_ExpectAndReturn(0);
  
  mutationSwapOnce(classToMutate);
  violationAfter = calculateTotalViolationInTimetable(classToMutate);
  
  TEST_ASSERT_EQUAL(1, classIsNull(&classToMutate[0][0][0]));
  TEST_ASSERT_EQUAL(0, classIsNull(&classToMutate[1][1][0]));
  TEST_ASSERT_EQUAL(1, checkEqualClass(&classToMutate[1][1][0], &clazzList[0]));
  TEST_ASSERT_EQUAL(19, violationBefore);
  TEST_ASSERT_EQUAL(0, violationAfter);
  
}