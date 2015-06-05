#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include <stdio.h>
#include "Constraints.h"
#include "Structure.h"


void setUp(void){}
void tearDown(void){}

/**
* MAX_VENUE = 2
* MAX_DAY = 3
* MAX_TIME_SLOT = 6
**/

void test_studyHourOverloaded_should_return_0_with_empty_Class(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(0,studyHourOverloaded(exampleClass, 2, MAX_VENUE));
  
}

void test_studyHourOverloaded_should_return_negative_1_when_exceeding_MAX_DAY(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
 
  TEST_ASSERT_EQUAL(-1,studyHourOverloaded(exampleClass, 3, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_0_only_4_class_total_2_venues(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][2][0] = clazzList[0];
  exampleClass[0][2][1] = clazzList[0];
  exampleClass[1][2][0] = clazzList[0];
  exampleClass[1][2][1] = clazzList[0];
  
  TEST_ASSERT_EQUAL(0,studyHourOverloaded(exampleClass, 2, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_4_each_group_exceeded_1_hour(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  //There are 4 group in clazzList[0]
  
  exampleClass[0][2][0] = clazzList[0];
  exampleClass[0][2][1] = clazzList[0];
  exampleClass[1][2][0] = clazzList[0];
  exampleClass[1][2][1] = clazzList[0];
  exampleClass[1][2][2] = clazzList[0];
  
  TEST_ASSERT_EQUAL(4,studyHourOverloaded(exampleClass, 2, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_32_each_group_exceeded_8_hour(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  //There are 4 group in clazzList[0]
  
  exampleClass[0][2][0] = clazzList[0];
  exampleClass[0][2][1] = clazzList[0];
  exampleClass[0][2][2] = clazzList[0];
  exampleClass[0][2][3] = clazzList[0];
  exampleClass[0][2][4] = clazzList[0];
  exampleClass[0][2][5] = clazzList[0];
  exampleClass[1][2][0] = clazzList[0];
  exampleClass[1][2][1] = clazzList[0];
  exampleClass[1][2][2] = clazzList[0];
  exampleClass[1][2][3] = clazzList[0];
  exampleClass[1][2][4] = clazzList[0];
  exampleClass[1][2][5] = clazzList[0];
  
  //exceeded 8 hours, 4 groups x 8 hours = 32 violations
  
  TEST_ASSERT_EQUAL(32,studyHourOverloaded(exampleClass, 2, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_0_when_checking_different_day(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  //There are 4 group in clazzList[0]
  
  exampleClass[0][2][0] = clazzList[0];
  exampleClass[0][2][1] = clazzList[0];
  exampleClass[0][2][2] = clazzList[0];
  exampleClass[0][2][3] = clazzList[0];
  exampleClass[0][2][4] = clazzList[0];
  exampleClass[0][2][5] = clazzList[0];
  exampleClass[1][2][0] = clazzList[0];
  exampleClass[1][2][1] = clazzList[0];
  exampleClass[1][2][2] = clazzList[0];
  exampleClass[1][2][3] = clazzList[0];
  exampleClass[1][2][4] = clazzList[0];
  exampleClass[1][2][5] = clazzList[0];
  
  //exceeded 8 hours, 4 groups x 8 hours = 32 violations
  
  TEST_ASSERT_EQUAL(0,studyHourOverloaded(exampleClass, 0, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_20(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  //There are 4 group in clazzList[0]
  
  exampleClass[0][2][0] = clazzList[0]; //0123
  exampleClass[0][2][1] = clazzList[1]; //0123
  exampleClass[0][2][2] = clazzList[2]; //0123
  exampleClass[0][2][3] = clazzList[3]; //  2345
  exampleClass[0][2][4] = clazzList[4]; //  2345
  exampleClass[0][2][5] = clazzList[5]; //  2345
  exampleClass[1][2][0] = clazzList[6]; //  2345
  exampleClass[1][2][1] = clazzList[7]; //01  45
  exampleClass[1][2][2] = clazzList[8]; //01  45
  exampleClass[1][2][3] = clazzList[9]; //01  45
  exampleClass[1][2][4] = clazzList[10];//01  45

  
  //group 0 exceeded 3
  //group 1 exceeded 3
  //group 2 exceeded 3
  //group 3 exceeded 3
  //group 4 exceeded 4
  //group 5 exceeded 4
  //a total of       20
  
  TEST_ASSERT_EQUAL(20,studyHourOverloaded(exampleClass, 2, MAX_VENUE));
}

void test_lecturerInMultipleVenue_should_return_0_with_empty_class(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 0, 2));
}

void test_lecturerInMultipleVenue_should_return_negative_1_with_exceeded_TIME(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(-1, lecturerInMultipleVenue(exampleClass, 0, 7, 2));
}

void test_lecturerInMultipleVenue_should_return_negative_1_with_exceeded_DAY(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(-1, lecturerInMultipleVenue(exampleClass, 3, 0, 2));
}

void test_lecturerInMultipleVenue_should_return_1_if_same_lecturer_in_different_venue(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][0] = clazzList[0];
  
  TEST_ASSERT_EQUAL(1, lecturerInMultipleVenue(exampleClass, 0, 0, 2));
}

void test_lecturerInMultipleVenue_should_return_6_if_same_lecturer_in_different_venue(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][0] = clazzList[0];
  exampleClass[2][0][0] = clazzList[0];
  exampleClass[3][0][0] = clazzList[0];
  exampleClass[4][0][0] = clazzList[0];
  exampleClass[5][0][0] = clazzList[0];
  exampleClass[6][0][0] = clazzList[0];
  
  TEST_ASSERT_EQUAL(6, lecturerInMultipleVenue(exampleClass, 0, 0, 7));
}

void test_lecturerInMultipleVenue_should_return_6_if_same_lecturer_in_different_venue2(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][2][5] = clazzList[0];
  exampleClass[1][2][5] = clazzList[0];
  exampleClass[2][2][5] = clazzList[0];
  exampleClass[3][2][5] = clazzList[0];
  exampleClass[4][2][5] = clazzList[0];
  exampleClass[5][2][5] = clazzList[0];
  exampleClass[6][2][5] = clazzList[0];
  
  TEST_ASSERT_EQUAL(6, lecturerInMultipleVenue(exampleClass, 2, 5, 7));
}

void test_lecturerInMultipleVenue_should_return_0_when_same_lecturer_in_different_hour(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][1] = clazzList[0];
  exampleClass[2][0][2] = clazzList[0];
  exampleClass[3][0][3] = clazzList[0];
  exampleClass[4][0][4] = clazzList[0];
  exampleClass[5][0][5] = clazzList[0];
  exampleClass[6][0][6] = clazzList[0];
  
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 0, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 1, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 2, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 3, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 4, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 5, 7));
}

void test_lecturerInMultipleVenue_should_return_0_when_same_lecturer_same_slot_different_day(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][1][0] = clazzList[0];
  exampleClass[2][2][0] = clazzList[0];

  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 0, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 1, 0, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 2, 0, 7));

}

void test_lecturerInMultipleVenue_should_return_0_when_different_lecturer_in_same_day_and_time(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][0] = clazzList[3];
  exampleClass[2][0][0] = clazzList[7];

  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, 0, 0, 7));
}