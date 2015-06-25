#define FOR_TEST

#include "unity.h"
#include <stdio.h>
#include "Crossover.h"
#include "Structure.h"
#include "mock_Random.h"

void setUp(void){
  int i;
  
  for(i = 0 ; i < (sizeof(classCount)/sizeof(ClassCounter)) ; i++){
    classCount[i].lectureCounter = 0;
    classCount[i].tutorialCounter = 0;
    classCount[i].practicalCounter = 0;
    classCount[i].forEmptyClasses = 0;
  }
}
void tearDown(void){}

void test_updateEmptyCounter_should_return_1_when_update_from_0_to_1(){
  
  Class newClass;
  newClass = clearClass(newClass);
  
  TEST_ASSERT_EQUAL(1, updateEmptyCounter(newClass, 3, 1));
  TEST_ASSERT_EQUAL(1, classCount[3].forEmptyClasses);
  
}

void test_updateEmptyCounter_should_return_0_when_empty_counter_overload(){
  
  Class newClass;
  newClass = clearClass(newClass);
  
  TEST_ASSERT_EQUAL(1, updateEmptyCounter(newClass, 3, 1));
  TEST_ASSERT_EQUAL(0, updateEmptyCounter(newClass, 3, 1));
  TEST_ASSERT_EQUAL(1, classCount[3].forEmptyClasses);
  
}

void test_updateEmptyCounter_should_return_1_when_filling_2_lecture(){
  
  Class newClass;
  newClass = clazzList[0]; //2 Lecture
  
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass));
  TEST_ASSERT_EQUAL(2, classCount[0].lectureCounter);
  
}

void test_updateEmptyCounter_should_return_0_when_filling_3rd_lecture(){
  
  Class newClass;
  newClass = clazzList[0]; //2 Lecture
  
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass));
  TEST_ASSERT_EQUAL(0, updateLectureCounter(newClass));
  TEST_ASSERT_EQUAL(2, classCount[0].lectureCounter);
 
}

void test_updateEmptyCounter_should_return_1_when_filling_1_tutorial(){
  
  Class newClass;
  newClass = clazzList[0]; //1 Tutorial
  
  TEST_ASSERT_EQUAL(1, updateTutorialCounter(newClass));
  TEST_ASSERT_EQUAL(1, classCount[0].tutorialCounter);
  
}

void test_updateEmptyCounter_should_return_0_when_filling_2nd_Tutorial(){
  
  Class newClass;
  newClass = clazzList[0]; //1 Tutorial
  
  TEST_ASSERT_EQUAL(1, updateTutorialCounter(newClass));
  TEST_ASSERT_EQUAL(0, updateTutorialCounter(newClass));
  TEST_ASSERT_EQUAL(1, classCount[0].tutorialCounter);
  
}

void test_updateEmptyCounter_should_return_1_when_filling_1_Practical(){
  
  Class newClass;
  newClass = clazzList[10]; //1 Practical
  
  TEST_ASSERT_EQUAL(1, updatePracticalCounter(newClass));
  TEST_ASSERT_EQUAL(1, classCount[2].practicalCounter);
  
}

void test_updateEmptyCounter_should_return_0_when_filling_2nd_Practical(){
  
  Class newClass;
  newClass = clazzList[10]; //1 Practical
  
  TEST_ASSERT_EQUAL(1, updatePracticalCounter(newClass));
  TEST_ASSERT_EQUAL(0, updatePracticalCounter(newClass));
  TEST_ASSERT_EQUAL(1, classCount[2].practicalCounter);
  
}

void test_updateLectureCounter_should_update_3_different_course_and_return_1(){
  
  Class newClass;
  Class newClass2;
  Class newClass3;
  newClass = clazzList[0]; //2 Lecture
  newClass2 = clazzList[3]; //2 Lecture
  newClass3 = clazzList[7]; //2 Lecture
  
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass2));
  TEST_ASSERT_EQUAL(1, updateLectureCounter(newClass3));
  TEST_ASSERT_EQUAL(1, classCount[0].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[1].lectureCounter);
  TEST_ASSERT_EQUAL(1, classCount[2].lectureCounter);
  
}

void test_updateCounter_should_return_1_with_one_empty_class(){
  
  Class newClass;
  
  
  newClass = clearClass(newClass);
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
}

void test_updateCounter_should_return_1_with_25_empty_classes(){
  
  Class newClass;
  int i;
  
  newClass = clearClass(newClass);
  
  for(i = 0 ; i < 25 ; i++){
    TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  }
}

void test_updateCounter_should_return_0_with_26_empty_classes(){
  
  Class newClass;
  int i;
  
  newClass = clearClass(newClass);
  
  for(i = 0 ; i < 25 ; i++){
    TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  }
  TEST_ASSERT_EQUAL(0, updateCounter(newClass));
}

void test_updateCounter_should_return_1_with_lecture_class(){
  
  //clazzList[0] = 2L, 1T, 0P
  //clazzList[0] is lecture
  Class newClass = clazzList[0];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
}

void test_updateCounter_should_return_0_with_exceeding_lecture_class(){
  
  //clazzList[0] = 2L, 1T, 0P
  //clazzList[0] is lecture
  Class newClass = clazzList[0];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(0, updateCounter(newClass));
}

void test_updateCounter_should_return_1_with_tutorial_class(){
  
  //clazzList[2] = 2L, 1T, 0P
  //clazzList[2] is tutorial
  Class newClass = clazzList[2];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
}

void test_updateCounter_should_return_0_with_exceeding_tutorial_class(){
  
  //clazzList[2] = 2L, 1T, 0P
  //clazzList[2] is tutorial
  Class newClass = clazzList[2];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(0, updateCounter(newClass));
}

void test_updateCounter_should_return_1_with_practical_class(){
  
  //clazzList[10] = 2L, 1T, 1P
  //clazzList[10] is practical
  Class newClass = clazzList[10];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
}

void test_updateCounter_should_return_0_with_exceeded_practical_class(){
  
  //clazzList[10] = 2L, 1T, 1P
  //clazzList[10] is practical
  Class newClass = clazzList[10];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(0, updateCounter(newClass));
}

void test_updateCounter_should_able_to_run_with_different_class(){
  
  Class newClass = clazzList[0];
  Class newClass2 = clazzList[10];
  int i;
  
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateCounter(newClass));
  TEST_ASSERT_EQUAL(1, updateCounter(newClass2));
  TEST_ASSERT_EQUAL(0, updateCounter(newClass2));
}

void test_randomIndex_should_update_values(){
  int venue, day, time;
  
  randomVenue_ExpectAndReturn(1);
  randomDay_ExpectAndReturn(2);
  randomTime_ExpectAndReturn(3);
  randomIndex(&venue,&day,&time);
  
  TEST_ASSERT_EQUAL(1, venue);
  TEST_ASSERT_EQUAL(2, day);
  TEST_ASSERT_EQUAL(3, time);
}

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

void test_ddly(){
  
 Class Father[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
 Class Mother[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
 Class Offspring[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
 
 clearTimeTable(Father);
 clearTimeTable(Mother);
 clearTimeTable(Offspring);
 
 int i;
 int a = 0, b = 0 , c = 0;
 int d = MAX_VENUE-1, e = MAX_DAY-1, f = MAX_TIME_SLOT - 1;
 
 for( i = 0 ; i < 11 ; i++){
   Father[a][b][c] = clazzList[i];
   Mother[d][e][f] = clazzList[i];
   indexForward(&a,&b,&c);
   indexBackward(&d,&e,&f);
 }
 
  // a = 0;
  // b = 0;
  // c = 0;

  // for(i = 0 ; i < 36 ; i++){
   // if(Father[a][b][c].course == NULL)
     // printf("Father %d. Empty\n",i);
   // else
     // printf("Father %d. %s\n",i,Father[a][b][c].course->courseName);
   // indexForward(&a,&b,&c);
 // }
 
  // a = 0;
  // b = 0;
  // c = 0;
   // for(i = 0 ; i < 36 ; i++){
   // if(Mother[a][b][c].course == NULL)
     // printf("Mother %d. Empty\n",i);
   // else
     // printf("Mother %d. %s\n",i,Mother[a][b][c].course->courseName);
   // indexForward(&a,&b,&c);
 // }
 
 randomVenue_ExpectAndReturn(1);
 randomDay_ExpectAndReturn(2);
 randomTime_ExpectAndReturn(5);
 randomVenue_ExpectAndReturn(0);
 randomDay_ExpectAndReturn(0);
 randomTime_ExpectAndReturn(0);
 performCrossover(Father,Mother,Offspring,2);
 
  a = 0;
  b = 0;
  c = 0;
  
 for(i = 0 ; i < 36 ; i++){
   if(Offspring[a][b][c].course == NULL)
     printf("%d. Empty\n",i);
   else
     printf("%d. %s\n",i,Offspring[a][b][c].course->courseName);
   indexForward(&a,&b,&c);
 }
 
 setUp();
  a = 0;
  b = 0;
  c = 0;
  for(i = 0 ; i < 36 ; i++){
   TEST_ASSERT_EQUAL(1, updateCounter(Offspring[a][b][c]));
   indexForward(&a,&b,&c);
 }
   TEST_ASSERT_EQUAL(0, updateCounter(Offspring[0][0][0]));
}