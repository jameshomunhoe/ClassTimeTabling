#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include <stdio.h>
#include "TestStructure.h"
#include "Constraints.h"
#include "Structure.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
}
void tearDown(void){}

/**
* MAX_VENUE = 2
* MAX_DAY = 3
* MAX_TIME_SLOT = 6
**/

/************************************************************************
 *  TEST of clearCounter
 ************************************************************************/
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

/************************************************************************
 *  TEST of studyHourOverloaded
 ************************************************************************/
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
  
  exampleClass[0][2][0] = clazzList[0]; // 0,1,2,3
  exampleClass[0][2][1] = clazzList[0]; // 0,1,2,3
  exampleClass[1][2][0] = clazzList[0]; // 0,1,2,3
  exampleClass[1][2][1] = clazzList[0]; // 0,1,2,3
                                        // The following will cap at 2 class, 
                                        // because each group only can take 2 L class for English
  
  TEST_ASSERT_EQUAL(0,studyHourOverloaded(exampleClass, WEDNESDAY, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_2_when_2_group_exceeded_1_hour(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][2][0] = clazzList[0]; // 0,1,2,3
  exampleClass[0][2][1] = clazzList[1]; // 0,1,2,3
  exampleClass[1][2][0] = clazzList[2]; // 0,1
  exampleClass[1][2][1] = clazzList[3]; // 2,3
  exampleClass[1][2][4] = clazzList[11];// 0,1,4,5
  exampleClass[1][2][2] = clazzList[14];// 0,1
                                        //group 0 and 1, exceeded 1 hour
  
  TEST_ASSERT_EQUAL(2,studyHourOverloaded(exampleClass, WEDNESDAY, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_4_when_4_group_exceeded_1_hour(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][2][0] = clazzList[0]; // 0,1,2,3
  exampleClass[0][2][1] = clazzList[1]; // 0,1,2,3
  exampleClass[0][2][2] = clazzList[2]; // 0,1
  exampleClass[0][2][3] = clazzList[3]; // 2,3
  exampleClass[1][2][0] = clazzList[11];// 0,1,4,5
  exampleClass[1][2][1] = clazzList[14];// 0,1
  exampleClass[1][2][2] = clazzList[4]; // 2,3,4,5
  exampleClass[1][2][3] = clazzList[4]; // 2,3,4,5
                                        //group 0, 1, 2, and 3 exceeded 1 hour
  
  
  TEST_ASSERT_EQUAL(4,studyHourOverloaded(exampleClass, WEDNESDAY, MAX_VENUE));
}


void test_studyHourOverloaded_should_return_0_when_checking_different_day(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
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
  
  TEST_ASSERT_EQUAL(0,studyHourOverloaded(exampleClass, MONDAY, MAX_VENUE));
}

void test_studyHourOverloaded_should_return_8(void)
{
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  //There are 4 group in clazzList[0]
  
  exampleClass[0][2][0] = clazzList[0]; //0123
  exampleClass[0][2][1] = clazzList[1]; //0123
  exampleClass[0][2][2] = clazzList[2]; //01
  exampleClass[0][2][3] = clazzList[3]; //  23
  exampleClass[0][2][4] = clazzList[4]; //  2345
  exampleClass[0][2][5] = clazzList[5]; //  2345
  exampleClass[1][2][0] = clazzList[6]; //  23
  exampleClass[1][2][1] = clazzList[7]; //  23
  exampleClass[1][2][2] = clazzList[8]; //    45
  exampleClass[1][2][3] = clazzList[9]; //    45
  exampleClass[1][2][4] = clazzList[10];//01  45
                                        //group 2,3 exceeded 3 hours
                                        //group 4,5 exceeded 1 hours
                                        //3+3+1+1 = 8
  
  TEST_ASSERT_EQUAL(8,studyHourOverloaded(exampleClass, WEDNESDAY, MAX_VENUE));
}

/************************************************************************
 *  TEST of lecturerInMultipleVenue
 ************************************************************************/
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
  
  TEST_ASSERT_EQUAL(1, lecturerInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 2));
}


void test_lecturerInMultipleVenue_should_return_6_if_same_lecturer_in_different_venue(void)
{
  // set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][0] = clazzList[0];
  exampleClass[2][0][0] = clazzList[0];
  exampleClass[3][0][0] = clazzList[0];
  exampleClass[4][0][0] = clazzList[0];
  exampleClass[5][0][0] = clazzList[0];
  exampleClass[6][0][0] = clazzList[0];
  
  TEST_ASSERT_EQUAL(6, lecturerInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));
}

void test_lecturerInMultipleVenue_should_return_6_if_same_lecturer_in_different_venue2(void)
{
  // set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][2][5] = clazzList[0];
  exampleClass[1][2][5] = clazzList[0];
  exampleClass[2][2][5] = clazzList[0];
  exampleClass[3][2][5] = clazzList[0];
  exampleClass[4][2][5] = clazzList[0];
  exampleClass[5][2][5] = clazzList[0];
  exampleClass[6][2][5] = clazzList[0];
  
  TEST_ASSERT_EQUAL(6, lecturerInMultipleVenue(exampleClass, WEDNESDAY, _1_to_2pm, 7));
}

void test_lecturerInMultipleVenue_should_return_0_when_same_lecturer_in_different_hour(void)
{
  // set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][1] = clazzList[0];
  exampleClass[2][0][2] = clazzList[0];
  exampleClass[3][0][3] = clazzList[0];
  exampleClass[4][0][4] = clazzList[0];
  exampleClass[5][0][5] = clazzList[0];
  exampleClass[6][0][6] = clazzList[0];
  
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _9_to_10am, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _10_to_11am, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _11_to_12pm, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _12_to_1pm, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _1_to_2pm, 7));
}

void test_lecturerInMultipleVenue_should_return_0_when_same_lecturer_same_slot_different_day(void)
{
  // set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][1][0] = clazzList[0];
  exampleClass[2][2][0] = clazzList[0];

  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, TUESDAY, _8_to_9am, 7));
  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, WEDNESDAY, _8_to_9am, 7));

}

void test_lecturerInMultipleVenue_should_return_0_when_different_lecturer_in_same_day_and_time(void)
{
  // set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[1][0][0] = clazzList[4];
  exampleClass[2][0][0] = clazzList[10];

  TEST_ASSERT_EQUAL(0, lecturerInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));
}

/************************************************************************
 *  TEST of groupInMultipleVenue
 ************************************************************************/
void test_groupInMultipleVenue_should_return_0_when_empty_class_inserted(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};

  TEST_ASSERT_EQUAL(0, groupInMultipleVenue(exampleClass, MONDAY, _8_to_9am, MAX_VENUE));
}
void test_groupInMultipleVenue_should_Throw_when_Exceeded_DAY(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};

  Try{
    groupInMultipleVenue(exampleClass, SATURDAY, _8_to_9am, 7);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX,e);
  }
}

void test_groupInMultipleVenue_should_Throw_when_Exceeded_TIME(void)
{
  // set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};

  Try{
    groupInMultipleVenue(exampleClass, MONDAY, _2_to_3pm, 7);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX,e);
  }
}

void test_groupInMultipleVenue_should_return_4_when_1_clashes_4_groups(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0]; // 0,1,2,3
  exampleClass[1][0][0] = clazzList[0]; // 0,1,2,3

  TEST_ASSERT_EQUAL(4, groupInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));

}

void test_groupInMultipleVenue_should_return_2_when_1_clashes_2_groups(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
  exampleClass[0][0][0] = clazzList[0]; //0,1,2,3
  exampleClass[1][0][0] = clazzList[2]; //0,1

  TEST_ASSERT_EQUAL(2, groupInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));

}

void test_groupInMultipleVenue_should_return_0_when_different_groups_in_same_day_and_time(void)
{
  //set venue 7 for testing purpose
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
 exampleClass[0][0][0] = clazzList[2]; //0,1
 exampleClass[1][0][0] = clazzList[3]; //2,3

  TEST_ASSERT_EQUAL(0, groupInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));
}

void test_groupInMultipleVenue_should_return_0_when_0_clashes(void)
{
  //set venue 7 for testing purpose
  ErrorCode e;
  Class exampleClass[7][MAX_DAY][MAX_TIME_SLOT] = {0};
  
 exampleClass[0][0][0] = clazzList[0];
 exampleClass[1][0][1] = clazzList[0];

  TEST_ASSERT_EQUAL(0, groupInMultipleVenue(exampleClass, MONDAY, _8_to_9am, 7));

}

/************************************************************************
 *  TEST of venueOverloaded
 ************************************************************************/
void test_venueOverloaded_should_return_0_when_empty_class(){
  Class exampleClass;
  clearClass(&exampleClass);
  
  TEST_ASSERT_EQUAL(0, venueOverloaded(&exampleClass,0));
}

void test_venueOverloaded_should_return_5_when_insufficient_space(){
  Class exampleClass;
  clearClass(&exampleClass);
  exampleClass = clazzList[4];
  
  TEST_ASSERT_EQUAL(5, venueOverloaded(&exampleClass,0));
}

void test_venueOverloaded_should_return_17_when_insufficient_space(){
  Class exampleClass;
  clearClass(&exampleClass);
  exampleClass = clazzList[0];
  
  TEST_ASSERT_EQUAL(17, venueOverloaded(&exampleClass,0));
}

void test_venueOverloaded_should_return_0_when_venue1_sufficient(){
  Class exampleClass;
  clearClass(&exampleClass);
  exampleClass = clazzList[0];
  
  TEST_ASSERT_EQUAL(0, venueOverloaded(&exampleClass,1));
}

/************************************************************************
 *  TEST of wrongVenueType
 ************************************************************************/
void test_wrongVenueType_should_return_0_if_class_is_empty(){
  Class newClass;
  clearClass(&newClass);
  
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 0));
}

void test_wrongVenueType_should_return_0_if_lecture_in_practial_lab(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[0]; //English lecture
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 0));
}

void test_wrongVenueType_should_return_0_if_tutorial_in_practial_lab(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[2]; //English tutorial
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 0));
}

void test_wrongVenueType_should_return_0_if_pratical_in_practial_lab(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[10]; //Control system practical
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 0));
}

void test_wrongVenueType_should_return_0_if_lecture_in_tutorial_class(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[0]; //English lecture
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 2));
}

void test_wrongVenueType_should_return_0_if_tutorial_in_tutorial_class(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[2]; //English tutorial
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 2));
}

void test_wrongVenueType_should_return_1_if_pratical_in_tutorial_class(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[15]; //Control system practical
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(1, wrongVenueType(&newClass, 2));
}

void test_wrongVenueType_should_return_0_if_lecture_in_leture_class(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[0]; //English lecture
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 1));
}

void test_wrongVenueType_should_return_0_if_tutorial_in_leture_class(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[2]; //English tutorial
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(0, wrongVenueType(&newClass, 1));
}

void test_wrongVenueType_should_return_1_if_pratical_in_leture_class(){
  Class newClass;
  clearClass(&newClass);
  newClass = clazzList[15]; //Control system practical
  
  //venue 0 = Practial, venue 1 = Lecture, venue 2 = Tutorial
  TEST_ASSERT_EQUAL(1, wrongVenueType(&newClass, 1));
}

/************************************************************************
 *  TEST of groupCounterUpdateNumOfAppearing
 ************************************************************************/
void test_groupCounterUpdateNumOfAppearing_should_return_0_when_empty(){
  int counter[5];
  clearCounter(5, counter);
  
  groupCounterUpdateNumOfAppearing(5, counter); 
  
  TEST_ASSERT_EQUAL(0, counter[0]);
  TEST_ASSERT_EQUAL(0, counter[1]);
  TEST_ASSERT_EQUAL(0, counter[2]);
  TEST_ASSERT_EQUAL(0, counter[3]);
  TEST_ASSERT_EQUAL(0, counter[4]);
  
}

void test_groupCounterUpdateNumOfAppearing_should_update_counter_by_1(){
  int counter[5];
  clearCounter(5, counter);
  
  updateGroupCounterFromClass(&(clazzList[0]));//0,1,2,3
  groupCounterUpdateNumOfAppearing(5, counter); 
  
  TEST_ASSERT_EQUAL(1, counter[0]);
  TEST_ASSERT_EQUAL(1, counter[1]);
  TEST_ASSERT_EQUAL(1, counter[2]);
  TEST_ASSERT_EQUAL(1, counter[3]);
  TEST_ASSERT_EQUAL(0, counter[4]);
  
}

void test_groupCounterUpdateNumOfAppearing_should_update_counter_by_2_for_group_0_1(){
  int counter[5];
  clearCounter(5, counter);
  
  updateGroupCounterFromClass(&(clazzList[0]));//0,1,2,3
  updateGroupCounterFromClass(&(clazzList[2]));//0,1
  groupCounterUpdateNumOfAppearing(5, counter); 
  
  TEST_ASSERT_EQUAL(2, counter[0]);
  TEST_ASSERT_EQUAL(2, counter[1]);
  TEST_ASSERT_EQUAL(1, counter[2]);
  TEST_ASSERT_EQUAL(1, counter[3]);
  TEST_ASSERT_EQUAL(0, counter[4]);
  
}

/************************************************************************
 *  TEST of groupCounterUpdateNumOfAppearing
 ************************************************************************/
void test_generateViolationFromCounter_should_return_0_when_counter_empty(){
  int counter[5];
  clearCounter(5, counter);
  
  TEST_ASSERT_EQUAL(0, generateViolationFromCounter(5, counter, 1));
}

void test_generateViolationFromCounter_should_return_0_when_counter_of_each_group_less_than_1(){
  int counter[5];
  clearCounter(5, counter);
  
  updateGroupCounterFromClass(&(clazzList[0]));//0,1,2,3
  groupCounterUpdateNumOfAppearing(5, counter); 
  
  TEST_ASSERT_EQUAL(0, generateViolationFromCounter(5, counter, 1));
}

void test_generateViolationFromCounter_should_return_2_when_when_2_group_exceeded_1_count(){
  int counter[5];
  clearCounter(5, counter);
  
  updateGroupCounterFromClass(&(clazzList[0]));//0,1,2,3
  updateGroupCounterFromClass(&(clazzList[2]));//0,1
  groupCounterUpdateNumOfAppearing(5, counter); 
  
  TEST_ASSERT_EQUAL(2, generateViolationFromCounter(5, counter, 1));
}

/************************************************************************
 *  TEST of teachingHourOverloaded
 ************************************************************************/
void test_teachingHourOverloaded_should_return_0_for_empty_class(){
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0}; 
  
  TEST_ASSERT_EQUAL(0,teachingHourOverloaded(exampleClass, 0, MAX_VENUE));
   
}

void test_teachingHourOverloaded_should_return_0_if_4_hour_a_day(){
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0}; 
  
  //Max 4 hours per day
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[0][0][1] = clazzList[0];
  exampleClass[0][0][2] = clazzList[0];
  exampleClass[0][0][3] = clazzList[0];
  
  TEST_ASSERT_EQUAL(0,teachingHourOverloaded(exampleClass, MONDAY, MAX_VENUE));
}

void test_teachingHourOverloaded_should_return_1_if_5_hour_a_day(){
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0}; 
  
  //Max 4 hours per day
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[0][0][1] = clazzList[0];
  exampleClass[0][0][2] = clazzList[0];
  exampleClass[0][0][3] = clazzList[0];
  exampleClass[0][0][4] = clazzList[0];
  
  TEST_ASSERT_EQUAL(1,teachingHourOverloaded(exampleClass, MONDAY, MAX_VENUE));
}

void test_teachingHourOverloaded_should_return_2_if_5_hour_a_day_2_lecturer(){
  Class exampleClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0}; 
  
  //Max 4 hours per day
  
  exampleClass[0][0][0] = clazzList[0];
  exampleClass[0][0][1] = clazzList[0];
  exampleClass[0][0][2] = clazzList[0];
  exampleClass[0][0][3] = clazzList[0];
  exampleClass[0][0][4] = clazzList[0];
  exampleClass[1][0][0] = clazzList[4];
  exampleClass[1][0][1] = clazzList[4];
  exampleClass[1][0][2] = clazzList[4];
  exampleClass[1][0][3] = clazzList[4];
  exampleClass[1][0][4] = clazzList[4];
  
  TEST_ASSERT_EQUAL(2,teachingHourOverloaded(exampleClass, MONDAY, MAX_VENUE));
}
 
 
 