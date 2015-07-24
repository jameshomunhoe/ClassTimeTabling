#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include <stdio.h>
#include "Constraints.h"
#include "Structure.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
}
void tearDown(void){}

/**
* MAX_VENUE = 2
* MAX_DAY = 3
* MAX_TIME_SLOT = 6
**/


/*
void test_clear_counter_should_clear_all_array_to_0(){
  int sizeOfArray = 5;
  int array[sizeOfArray];
  
  clearCounter(sizeOfArray,array);
  
  TEST_ASSERT_EQUAL(0,array[0]);
  TEST_ASSERT_EQUAL(0,array[1]);
  TEST_ASSERT_EQUAL(0,array[2]);
  TEST_ASSERT_EQUAL(0,array[3]);
  TEST_ASSERT_EQUAL(0,array[4]);
 
}

void test_studyHourOverloaded_should_return_0_with_empty_Class(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  TEST_ASSERT_EQUAL(0,studyHourOverloaded(exampleClass, 2, MAX_VENUE));
  
}

void test_studyHourOverloaded_should_Throw_when_exceeding_MAX_DAY(void)
{
  ErrorCode e;
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
 
  Try{
    studyHourOverloaded(exampleClass, 3, MAX_VENUE);
  }Catch(e){
  TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
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

void test_lecturerInMultipleVenue_should_Throw_with_exceeded_TIME(void)
{
  ErrorCode e;
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  Try{
    lecturerInMultipleVenue(exampleClass, 0, 7, 2);
  }Catch(e){
  TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX,e);
  }
}

void test_lecturerInMultipleVenue_should_Throw_with_exceeded_DAY(void)
{
  ErrorCode e;
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  Try{
    lecturerInMultipleVenue(exampleClass, 3, 0, 2);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX,e);
  }
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

void test_groupInMultipleVenue_should_return_0_when_empty_class_inserted(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};

  TEST_ASSERT_EQUAL(0, groupInMultipleVenue(exampleClass, 0, 0, 7));
}

void test_groupInMultipleVenue_should_Throw_when_Exceeded_DAY(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};

  Try{
    groupInMultipleVenue(exampleClass, 5, 0, 7);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX,e);
  }
}

void test_groupInMultipleVenue_should_Throw_when_Exceeded_TIME(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};

  Try{
    groupInMultipleVenue(exampleClass, 0, 6, 7);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX,e);
  }
}

void test_groupInMultipleVenue_should_return_1_when_1_clashes(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0].group[0] = &groupList[0];
  exampleClass[0][0][0].group[1] = NULL;
  exampleClass[1][0][0].group[0] = &groupList[0];
  exampleClass[1][0][0].group[1] = NULL;

  TEST_ASSERT_EQUAL(1, groupInMultipleVenue(exampleClass, 0, 0, 7));

}

void test_groupInMultipleVenue_should_return_2_when_2_clashes(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0].group[0] = &groupList[0];
  exampleClass[0][0][0].group[1] = &groupList[1];
  exampleClass[0][0][0].group[2] = NULL;
  exampleClass[1][0][0].group[0] = &groupList[1];
  exampleClass[1][0][0].group[1] = &groupList[2];
  exampleClass[1][0][0].group[2] = NULL;
  exampleClass[6][0][0].group[0] = &groupList[1];
  exampleClass[6][0][0].group[1] = &groupList[3];
  exampleClass[6][0][0].group[2] = NULL;

  TEST_ASSERT_EQUAL(2, groupInMultipleVenue(exampleClass, 0, 0, 7));

}

void test_groupInMultipleVenue_should_return_0_when_different_groups_in_same_day_and_time(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0].group[0] = &groupList[0];
  exampleClass[0][0][0].group[1] = NULL;
  exampleClass[1][0][0].group[0] = &groupList[1];
  exampleClass[1][0][0].group[1] = NULL;
  exampleClass[2][0][0].group[0] = &groupList[2];
  exampleClass[2][0][0].group[1] = NULL;

  TEST_ASSERT_EQUAL(0, groupInMultipleVenue(exampleClass, 0, 0, 7));
}

void test_groupInMultipleVenue_should_return_0_when_0_clashes(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0].group[0] = &groupList[0];
  exampleClass[0][0][0].group[1] = &groupList[1];
  exampleClass[0][0][0].group[2] = NULL;
  exampleClass[1][0][0].group[0] = &groupList[2];
  exampleClass[1][0][0].group[1] = &groupList[3];
  exampleClass[1][0][0].group[2] = NULL;

  TEST_ASSERT_EQUAL(0, groupInMultipleVenue(exampleClass, 0, 0, 7));

}

void test_venueOverloaded_should_return_0_when_empty_class(){
  Class exampleClass;
  exampleClass = clearClass(exampleClass);
  
  TEST_ASSERT_EQUAL(0, venueOverloaded(exampleClass,0));
}

void test_venueOverloaded_should_return_5_when_insufficient_space(){
  Class exampleClass;
  exampleClass = clearClass(exampleClass);
  exampleClass = clazzList[3];
  
  TEST_ASSERT_EQUAL(5, venueOverloaded(exampleClass,0));
}

void test_venueOverloaded_should_return_17_when_insufficient_space(){
  Class exampleClass;
  exampleClass = clearClass(exampleClass);
  exampleClass = clazzList[0];
  
  TEST_ASSERT_EQUAL(17, venueOverloaded(exampleClass,0));
}

void test_venueOverloaded_should_return_0_when_venue1_sufficient(){
  Class exampleClass;
  exampleClass = clearClass(exampleClass);
  exampleClass = clazzList[0];
  
  TEST_ASSERT_EQUAL(0, venueOverloaded(exampleClass,1));
}

void test_wrongVenueType_should_return_0_if_class_is_empty(){
  Class newClass;
  newClass = clearClass(newClass);
  
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 0));
}

void test_wrongVenueType_should_return_0_if_lecture_in_practial_lab(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[0]; //English lecture
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 0));
}

void test_wrongVenueType_should_return_0_if_tutorial_in_practial_lab(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[2]; //English tutorial
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 0));
}

void test_wrongVenueType_should_return_0_if_pratical_in_practial_lab(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[10]; //Control system practical
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 0));
}

void test_wrongVenueType_should_return_0_if_lecture_in_tutorial_class(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[0]; //English lecture
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 2));
}

void test_wrongVenueType_should_return_0_if_tutorial_in_tutorial_class(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[2]; //English tutorial
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 2));
}

void test_wrongVenueType_should_return_1_if_pratical_in_tutorial_class(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[10]; //Control system practical
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(1, wrongVenueType(newClass, 2));
}

void test_wrongVenueType_should_return_0_if_lecture_in_leture_class(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[0]; //English lecture
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 1));
}

void test_wrongVenueType_should_return_0_if_tutorial_in_leture_class(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[2]; //English tutorial
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(newClass, 1));
}

void test_wrongVenueType_should_return_1_if_pratical_in_leture_class(){
  Class newClass;
  newClass = clearClass(newClass);
  newClass = clazzList[10]; //Control system practical
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(1, wrongVenueType(newClass, 1));
}
*/