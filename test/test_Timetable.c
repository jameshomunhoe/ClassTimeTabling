#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include "Timetable.h"
#include "Structure.h"
#include "TestStructure.h"
#include "ErrorCode.h"
#include "mock_Random.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
  initVenueList();
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

void test_createTimeTable_should_able_to_create_timeTable(){
  
  Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  
  createTimeTable(timeTable);
  
  //venue 0 = 55,P
  //venue 1 = 80,L
  //venue 2 = 50,T
  // class[0]  = group 0,1,2,3. lecturer = 0. lecture. size = 72
  // class[1]  = group 0,1,2,3. lecturer = 0. lecture. size = 72
  // class[2]  = group 0,1.     lecturer = 0. lecture. size = 32
  // class[3]  = group 2,3.     lecturer = 0. lecture. size = 40
  // class[4]  = group 2,3,4,5. lecturer = 1. lecture. size = 60
  // class[5]  = group 2,3,4,5. lecturer = 1. lecture. size = 60
  // class[6]  = group 2,3.     lecturer = 1. lecture. size = 40
  // class[7]  = group 2,3.     lecturer = 1. lecture. size = 40
  // class[8]  = group 4,5.     lecturer = 1. lecture. size = 20
  // class[9]  = group 4,5.     lecturer = 1. lecture. size = 20
  // class[10] = group 0,1,4,5. lecturer = 2. lecture. size = 52
  // class[11] = group 0,1,4,5. lecturer = 2. lecture. size = 52
  // class[12] = group 0,1.     lecturer = 2. lecture. size = 32
  // class[13] = group 4,5.     lecturer = 2. lecture. size = 20
  // class[14] = group 0,1.     lecturer = 2. lecture. size = 32
  // class[15] = group 4,5.     lecturer = 2. lecture. size = 20
 
  // randomVenue_ExpectAndReturn();
  // randomDay_ExpectAndReturn();
  // randomTime_ExpectAndReturn();
  
}






















