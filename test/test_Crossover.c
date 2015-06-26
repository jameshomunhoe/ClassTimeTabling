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

void test_getMidPoint_should_set_parents_index_to_middle(){
  int venueLeft, dayLeft, timeLeft;
  int venueRight, dayRight, timeRight;
  
 getMidPoint(&venueLeft,&dayLeft,&timeLeft,&venueRight,&dayRight,&timeRight,2);
 
 TEST_ASSERT_EQUAL(1,venueLeft);
 TEST_ASSERT_EQUAL(0,dayLeft);
 TEST_ASSERT_EQUAL(0,timeLeft);
 TEST_ASSERT_EQUAL(1,venueRight);
 TEST_ASSERT_EQUAL(0,dayRight);
 TEST_ASSERT_EQUAL(1,timeRight);
 
}

void test_getMidPoint_should_set_parents_index_to_middle_even_invalid_initial_value(){
  int venueLeft = 1000, dayLeft = 9999, timeLeft = 0;
  int venueRight = 1000, dayRight = 9999, timeRight = 0;
  
 getMidPoint(&venueLeft,&dayLeft,&timeLeft,&venueRight,&dayRight,&timeRight,2);
 
 TEST_ASSERT_EQUAL(1,venueLeft);
 TEST_ASSERT_EQUAL(0,dayLeft);
 TEST_ASSERT_EQUAL(0,timeLeft);
 TEST_ASSERT_EQUAL(1,venueRight);
 TEST_ASSERT_EQUAL(0,dayRight);
 TEST_ASSERT_EQUAL(1,timeRight);
 
}

void test_performCrossover_mother_ascending_order_father_reversed(){
  Class father[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class mother[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class offspring[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  // Class emptyClass;
  
  clearTimeTable(father);
  clearTimeTable(mother);
  clearTimeTable(offspring);
  // emptyClass = clearClass(emptyClass);
  
 int i;
 int a = 0, b = 0 , c = 0;
 int d = MAX_VENUE-1, e = MAX_DAY-1, f = MAX_TIME_SLOT - 1;
 
 for( i = 0 ; i < 11 ; i++){
   mother[a][b][c] = clazzList[i];
   father[d][e][f] = clazzList[i];
   indexForward(&a,&b,&c);
   indexBackward(&d,&e,&f);
 }
 
 randomVenue_ExpectAndReturn(1);
 randomDay_ExpectAndReturn(2);
 randomTime_ExpectAndReturn(5);
 randomVenue_ExpectAndReturn(0);
 randomDay_ExpectAndReturn(0);
 randomTime_ExpectAndReturn(0);
 performCrossover(father,mother,offspring,2);
 
 
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][0],father[1][2][5]));
 //starting point for father ^, mother v
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][1],mother[0][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][2],mother[0][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][3],mother[0][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][4],mother[0][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][5],mother[0][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][0],mother[0][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][1],mother[0][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][2],mother[0][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][3],mother[0][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][4],mother[0][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][5],mother[0][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][0],mother[0][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][1],mother[0][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][2],mother[0][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][3],mother[0][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][4],mother[0][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][5],mother[0][2][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][0],mother[1][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][1],mother[1][0][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][2],mother[1][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][3],mother[1][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][4],mother[1][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][5],mother[1][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][0],mother[1][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][1],mother[1][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][2],mother[1][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][3],mother[1][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][4],mother[1][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][5],mother[1][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][0],mother[1][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][1],mother[1][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][2],mother[1][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][3],mother[1][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][4],mother[1][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][5],mother[1][2][5]));

 
 
 
 
 setUp();
  a = 0;
  b = 0;
  c = 0;
  for(i = 0 ; i < 36 ; i++){
   TEST_ASSERT_EQUAL(1, updateCounter(offspring[a][b][c]));
   indexForward(&a,&b,&c);
 }
   TEST_ASSERT_EQUAL(0, updateCounter(offspring[0][0][0]));
   
 // a=0;
 // b=0;
 // c=0;
 // for(i = 0 ; i < 36 ; i++){
   // if(offspring[a][b][c].course == NULL)
     // printf("%d. Empty\n",i);
   // else
     // printf("%d. %s\n",i,offspring[a][b][c].course->courseName);
   // indexForward(&a,&b,&c);
 // }
 
}

void test_performCrossover_both_parents_are_identical(){
  Class father[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class mother[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  Class offspring[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT];
  
  clearTimeTable(father);
  clearTimeTable(mother);
  clearTimeTable(offspring);
  
 int i;
 int a = 0, b = 0 , c = 0;
 
 for( i = 0 ; i < 11 ; i++){
   mother[a][b][c] = clazzList[i];
   father[a][b][c] = clazzList[i];
   indexForward(&a,&b,&c);

 }
 
 randomVenue_ExpectAndReturn(1);
 randomDay_ExpectAndReturn(2);
 randomTime_ExpectAndReturn(5);
 randomVenue_ExpectAndReturn(0);
 randomDay_ExpectAndReturn(0);
 randomTime_ExpectAndReturn(0);
 performCrossover(father,mother,offspring,2);
 
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][1],father[1][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][1],father[1][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][2],father[1][0][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][3],father[1][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][4],father[1][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][5],father[1][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][0],father[1][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][1],father[1][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][2],father[1][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][3],father[1][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][4],father[1][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][1][5],father[1][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][0],father[1][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][1],father[1][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][2],father[1][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][3],father[1][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][4],father[1][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][2][5],father[1][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][0],father[1][2][5]));
 //starting point for father ^, mother v
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][1],mother[0][0][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][2],mother[0][0][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][3],mother[0][0][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][4],mother[0][0][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][0][5],mother[0][0][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][0],mother[0][0][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][1],mother[0][1][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][2],mother[0][1][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][3],mother[0][1][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][4],mother[0][1][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][1][5],mother[0][1][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][0],mother[0][1][5]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][1],mother[0][2][0]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][2],mother[0][2][1]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][3],mother[0][2][2]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][4],mother[0][2][3]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[1][2][5],mother[0][2][4]));
 TEST_ASSERT_EQUAL(1,checkEqualClass(offspring[0][0][0],mother[0][2][5]));

 
 // a=0;
 // b=0;
 // c=0;
 // for(i = 0 ; i < 36 ; i++){
   // if(offspring[a][b][c].course == NULL)
     // printf("%d. Empty\n",i);
   // else
     // printf("%d. %s\n",i,offspring[a][b][c].course->courseName);
   // indexForward(&a,&b,&c);
 // }
 
 setUp();
  a = 0;
  b = 0;
  c = 0;
  for(i = 0 ; i < 36 ; i++){
   TEST_ASSERT_EQUAL(1, updateCounter(offspring[a][b][c]));
   indexForward(&a,&b,&c);
 }
   TEST_ASSERT_EQUAL(0, updateCounter(offspring[0][0][0]));
}