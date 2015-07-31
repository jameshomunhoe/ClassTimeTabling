#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include "Timetable.h"
#include "Structure.h"
#include "ErrorCode.h"
#include "mock_Random.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
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

// void test_fillClassIntoTimetable_should_fill_in_2_classes_to_000_and_111(void){
  // ClassIndex classIndex = {1,2,5};
  // Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  // TEST_ASSERT_EQUAL(1, fillClassIntoTimetable(timeTable, &classIndex, &clazzList[0]));
  // TEST_ASSERT_EQUAL(1, classIsNull(&timeTable[0][0][0]));
  // TEST_ASSERT_EQUAL(1, checkEqualClass(&timeTable[1][2][5], &clazzList[0]));
  
// }
