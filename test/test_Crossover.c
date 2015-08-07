#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include "mock_Random.h"
#include "Crossover.h"
#include "Structure.h"
#include "TestStructure.h"


 

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initClassCounter();
  initVenueList();
}
void tearDown(void){}

void test_alele(){
  
}

/************************************************************************
 *  TEST of updateEmptyCounterFromClass
 ************************************************************************/
void test_updateEmptyCounterFromClass_should_return_1_when_update_from_0_to_1(){
  
  TEST_ASSERT_EQUAL(1, updateEmptyCounterFromClass(3, 1));
  TEST_ASSERT_EQUAL(1, classCount[3].forEmptyClasses);
  
}

void test_updateEmptyCounterFromClass_should_return_0_when_empty_counter_overload(){
  
  TEST_ASSERT_EQUAL(1, updateEmptyCounterFromClass(3, 1));
  TEST_ASSERT_EQUAL(0, updateEmptyCounterFromClass(3, 1));
  
}

/************************************************************************
 *  TEST of updateGroupLectureCounterFromClass
 ************************************************************************/
void test_updateGroupLectureCounterFromClass_should_return_1_when_filling_2_lecture(){
  
  Class newClass;
  newClass = clazzList[0]; //2 Lecture
  
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[0].lectureCounter);
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[1].lectureCounter);
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[2].lectureCounter);
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[3].lectureCounter);
  
}

void test_updateGroupLectureCounterFromClass_should_return_0_when_filling_3rd_lecture(){
  
  Class newClass;
  newClass = clazzList[0]; //2 Lecture
  
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(0, updateGroupLectureCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[0].lectureCounter);
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[1].lectureCounter);
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[2].lectureCounter);
  TEST_ASSERT_EQUAL(2, classCount[0].groupCounter[3].lectureCounter);
 
}

void test_updateGroupLectureCounterFromClass_should_update_3_different_course_and_return_1(){
  
  Class newClass;
  Class newClass2;
  Class newClass3;
  newClass = clazzList[0]; //2 Lecture
  newClass2 = clazzList[4]; //2 Lecture
  newClass3 = clazzList[10]; //2 Lecture
  
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass2));
  TEST_ASSERT_EQUAL(1, updateGroupLectureCounterFromClass(&newClass3));
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[0].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[1].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[2].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[3].lectureCounter);
  TEST_ASSERT_EQUAL(0, classCount[0].groupCounter[4].lectureCounter);
  TEST_ASSERT_EQUAL(0, classCount[0].groupCounter[5].lectureCounter);
  
  TEST_ASSERT_EQUAL(0, classCount[1].groupCounter[0].lectureCounter);
  TEST_ASSERT_EQUAL(0, classCount[1].groupCounter[1].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[1].groupCounter[2].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[1].groupCounter[3].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[1].groupCounter[4].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[1].groupCounter[5].lectureCounter);
  
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[0].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[1].lectureCounter);
  TEST_ASSERT_EQUAL(0, classCount[2].groupCounter[2].lectureCounter);
  TEST_ASSERT_EQUAL(0, classCount[2].groupCounter[3].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[4].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[5].lectureCounter);

}
/************************************************************************
 *  TEST of updateGroupTutorialCounterFromClass
 ************************************************************************/
void test_updateGroupTutorialCounterFromClass_should_return_1_when_filling_1_tutorial(){
  
  Class newClass;
  newClass = clazzList[2]; //1 Tutorial
  
  TEST_ASSERT_EQUAL(1, updateGroupTutorialCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[0].tutorialCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[1].tutorialCounter);
  
}

void test_updateGroupTutorialCounterFromClass_should_return_0_when_filling_2nd_Tutorial(){
  
  Class newClass;
  newClass = clazzList[2]; //1 Tutorial
  
  TEST_ASSERT_EQUAL(1, updateGroupTutorialCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(0, updateGroupTutorialCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[0].tutorialCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[1].tutorialCounter);
  
}

void test_updateGroupTutorialCounterFromClass_should_return_1_when_filling_tutorial_seperately(){
  
  Class newClass, newClass2;
  newClass = clazzList[2]; //1 Tutorial
  newClass2 = clazzList[3]; //1 Tutorial
  
  TEST_ASSERT_EQUAL(1, updateGroupTutorialCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupTutorialCounterFromClass(&newClass2));
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[0].tutorialCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[1].tutorialCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[2].tutorialCounter);
  TEST_ASSERT_EQUAL(1, classCount[0].groupCounter[3].tutorialCounter);
  
}

/************************************************************************
 *  TEST of updateGroupPracticalCounterFromClass
 ************************************************************************/
void test_updateGroupPracticalCounterFromClass_should_return_1_when_filling_1_Practical(){
  
  Class newClass;
  newClass = clazzList[14]; //1 Practical
  
  TEST_ASSERT_EQUAL(1, updateGroupPracticalCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[0].practicalCounter);
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[1].practicalCounter);
  
}

void test_updateGroupPracticalCounterFromClass_should_return_0_when_filling_2nd_Practical(){
  
  Class newClass;
  newClass = clazzList[10]; //1 Practical
  
  TEST_ASSERT_EQUAL(1, updateGroupPracticalCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(0, updateGroupPracticalCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[0].practicalCounter);
  TEST_ASSERT_EQUAL(1, classCount[2].groupCounter[1].practicalCounter);
  
}

/************************************************************************
 *  TEST of updateGroupCounterFromClass
 ************************************************************************/
void test_updateGroupCounterFromClass_should_return_1_with_one_empty_class(){
  
  Class newClass;
  
  clearClass(&newClass);
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_1_with_25_empty_classes(){
  
  Class newClass;
  int i;
  
  clearClass(&newClass);
  
  for(i = 0 ; i < 20 ; i++){
    TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
    TEST_ASSERT_EQUAL(i+1, classCount[3].forEmptyClasses);
  }
}

void test_updateGroupCounterFromClass_should_return_0_with_26_empty_classes(){
  
  Class newClass;
  int i;
  
  clearClass(&newClass);
  
  for(i = 0 ; i < 20 ; i++){
    TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
    TEST_ASSERT_EQUAL(i+1, classCount[3].forEmptyClasses);
  }
  TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_1_with_lecture_class(){
  
  //clazzList[0] = 2L, 1T, 0P
  //clazzList[0] is lecture
  Class newClass = clazzList[0];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_0_with_exceeding_lecture_class(){
  
  //clazzList[0] = 2L, 1T, 0P
  //clazzList[0] is lecture
  Class newClass = clazzList[0];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_1_with_tutorial_class(){
  
  //clazzList[2] = 2L, 1T, 0P
  //clazzList[2] is tutorial
  Class newClass = clazzList[2];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_0_with_exceeding_tutorial_class(){
  
  //clazzList[2] = 2L, 1T, 0P
  //clazzList[2] is tutorial
  Class newClass = clazzList[2];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_1_with_practical_class(){
  
  //clazzList[14] = 2L, 1T, 1P
  //clazzList[14] is practical
  Class newClass = clazzList[14];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_return_0_with_exceeded_practical_class(){
  
  //clazzList[14] = 2L, 1T, 1P
  //clazzList[14] is practical
  Class newClass = clazzList[14];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&newClass));
}

void test_updateGroupCounterFromClass_should_able_to_run_with_different_class(){
  
  Class newClass = clazzList[0];
  Class newClass2 = clazzList[14];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass));
  TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&newClass2));
  TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&newClass2));
}

/************************************************************************
 *  TEST of randomIndex
 ************************************************************************/
void test_randomIndex_should_update_values(){
  ClassIndex newClassIndex;
  
  randomVenue_ExpectAndReturn(1);
  randomDay_ExpectAndReturn(2);
  randomTime_ExpectAndReturn(3);
  randomIndex(&newClassIndex);
  
  TEST_ASSERT_EQUAL(1, newClassIndex.venue);
  TEST_ASSERT_EQUAL(2, newClassIndex.day);
  TEST_ASSERT_EQUAL(3, newClassIndex.time);
}

/************************************************************************
 *  TEST of updateStopFlag
 ************************************************************************/
void test_updateStopFlag_should_update_when_opposite_direction_not_stop_yet(){
  int currentSide = 0;
  int oppositeSide = 0;
  
  updateStopFlag (&currentSide, &oppositeSide);
  
  TEST_ASSERT_EQUAL(1,currentSide);
  TEST_ASSERT_EQUAL(0,oppositeSide);
}

void test_updateStopFlag_should_not_update_when_opposite_direction_stopped(){
  int currentSide = 0;
  int oppositeSide = 1;
  
  updateStopFlag (&currentSide, &oppositeSide);
  
  TEST_ASSERT_EQUAL(0,currentSide);
  TEST_ASSERT_EQUAL(1,oppositeSide);
}

void test_updateStopFlag_should_remain_1_even_initially_1(){
  int currentSide = 1;
  int oppositeSide = 0;
  
  updateStopFlag (&currentSide, &oppositeSide);
  
  TEST_ASSERT_EQUAL(1,currentSide);
  TEST_ASSERT_EQUAL(0,oppositeSide);
}

/************************************************************************
 *  TEST of getMidPoint
 ************************************************************************/
void test_getMidPoint_should_set_parents_index_to_middle(){
  ClassIndex indexLeft;
  ClassIndex indexRight;
  
 getMidPoint(&indexLeft,&indexRight,2);
 
 TEST_ASSERT_EQUAL(1,indexLeft.venue);
 TEST_ASSERT_EQUAL(0,indexLeft.day);
 TEST_ASSERT_EQUAL(0,indexLeft.time);
 TEST_ASSERT_EQUAL(1,indexRight.venue);
 TEST_ASSERT_EQUAL(0,indexRight.day);
 TEST_ASSERT_EQUAL(1,indexRight.time);
 
}

void test_getMidPoint_should_set_parents_index_to_middle_even_invalid_initial_value(){
  ClassIndex indexLeft = {1000,9999,0};
  ClassIndex indexRight = {1000,9999,0};
  
 getMidPoint(&indexLeft,&indexRight,2);
 
 TEST_ASSERT_EQUAL(1,indexLeft.venue);
 TEST_ASSERT_EQUAL(0,indexLeft.day);
 TEST_ASSERT_EQUAL(0,indexLeft.time);
 TEST_ASSERT_EQUAL(1,indexRight.venue);
 TEST_ASSERT_EQUAL(0,indexRight.day);
 TEST_ASSERT_EQUAL(1,indexRight.time);
 
}

/************************************************************************
 *  TEST of performCrossover
 ************************************************************************/
void test_performCrossover_mother_ascending_order_father_reversed(){
  Class father[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class mother[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class offspring[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];

  clearTimeTable(father);
  clearTimeTable(mother);
  clearTimeTable(offspring);
  
 int i;
 ClassIndex motherIndex = {0,0,0};
 ClassIndex fatherIndex = {MAX_VENUE - 1,MAX_DAY - 1,MAX_TIME_SLOT - 1};
 ClassIndex offSpringIndex = {0,0,0};
 
 int clazzListSize = getClazzListSize();
 
 for( i = 0 ; i < clazzListSize ; i++){
   mother[motherIndex.venue][motherIndex.day][motherIndex.time] = clazzList[i];
   father[fatherIndex.venue][fatherIndex.day][fatherIndex.time] = clazzList[i];
   indexForward(&motherIndex);
   indexBackward(&fatherIndex);
 }
 
 randomVenue_ExpectAndReturn(1);
 randomDay_ExpectAndReturn(2);
 randomTime_ExpectAndReturn(5);
 randomVenue_ExpectAndReturn(0);
 randomDay_ExpectAndReturn(0);
 randomTime_ExpectAndReturn(0);
 performCrossover(father,mother,offspring,2);
 
 
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][0],&father[1][2][5]));
 //starting point for father ^, mother v
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][1],&mother[0][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][2],&mother[0][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][3],&mother[0][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][4],&mother[0][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][5],&mother[0][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][0],&mother[0][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][1],&mother[0][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][2],&mother[0][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][3],&mother[0][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][4],&mother[0][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][5],&mother[0][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][0],&mother[0][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][1],&mother[0][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][2],&mother[0][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][3],&mother[0][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][4],&mother[0][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][5],&mother[0][2][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][0],&mother[1][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][1],&mother[1][0][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][2],&mother[1][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][3],&mother[1][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][4],&mother[1][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][5],&mother[1][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][0],&mother[1][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][1],&mother[1][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][2],&mother[1][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][3],&mother[1][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][4],&mother[1][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][5],&mother[1][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][0],&mother[1][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][1],&mother[1][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][2],&mother[1][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][3],&mother[1][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][4],&mother[1][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][5],&mother[1][2][5]));


 setUp();
  for(i = 0 ; i < MAX_VENUE*MAX_DAY*MAX_TIME_SLOT ; i++){
   TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&offspring[offSpringIndex.venue][offSpringIndex.day][offSpringIndex.time]));
   indexForward(&offSpringIndex);
 }
   TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&offspring[0][0][0])); 
}


void test_performCrossover_both_parents_are_identical(){
  Class father[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class mother[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class offspring[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  
  clearTimeTable(father);
  clearTimeTable(mother);
  clearTimeTable(offspring);
  
 int i;
 ClassIndex index = {0,0,0};
 ClassIndex offSpringIndex = {0,0,0};
 
 int clazzListSize = getClazzListSize();
 
 for( i = 0 ; i < clazzListSize ; i++){
   mother[index.venue][index.day][index.time] = clazzList[i];
   father[index.venue][index.day][index.time] = clazzList[i];
   indexForward(&index);
 }
 
 randomVenue_ExpectAndReturn(1);
 randomDay_ExpectAndReturn(2);
 randomTime_ExpectAndReturn(5);
 randomVenue_ExpectAndReturn(0);
 randomDay_ExpectAndReturn(0);
 randomTime_ExpectAndReturn(0);
 performCrossover(father,mother,offspring,2);
 
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][1],&father[1][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][2],&father[1][0][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][3],&father[1][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][4],&father[1][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][5],&father[1][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][0],&father[1][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][1],&father[1][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][2],&father[1][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][3],&father[1][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][4],&father[1][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][1][5],&father[1][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][0],&father[1][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][1],&father[1][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][2],&father[1][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][3],&father[1][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][4],&father[1][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][2][5],&father[1][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][0],&father[1][2][5]));
 //starting point for father ^, mother v
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][1],&mother[0][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][2],&mother[0][0][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][3],&mother[0][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][4],&mother[0][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][0][5],&mother[0][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][0],&mother[0][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][1],&mother[0][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][2],&mother[0][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][3],&mother[0][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][4],&mother[0][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][1][5],&mother[0][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][0],&mother[0][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][1],&mother[0][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][2],&mother[0][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][3],&mother[0][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][4],&mother[0][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[1][2][5],&mother[0][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(&offspring[0][0][0],&mother[0][2][5]));

 setUp();
 
  for(i = 0 ; i < MAX_VENUE*MAX_DAY*MAX_TIME_SLOT ; i++){
   TEST_ASSERT_EQUAL(1, updateGroupCounterFromClass(&offspring[offSpringIndex.venue][offSpringIndex.day][offSpringIndex.time]));
   indexForward(&offSpringIndex);
 }
   TEST_ASSERT_EQUAL(0, updateGroupCounterFromClass(&offspring[offSpringIndex.venue][offSpringIndex.day][offSpringIndex.time]));
}
