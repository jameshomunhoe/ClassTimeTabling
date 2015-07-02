#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include <stdio.h>
#include "Structure.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

void test_clearClass_should_empty_an_empty_class(){
  Class testClass;
  
  testClass = clearClass(testClass);

  TEST_ASSERT_EQUAL(NULL, testClass.course);
  TEST_ASSERT_EQUAL(NULL, testClass.lecturer);
  TEST_ASSERT_EQUAL(NULL, testClass.typeOfClass);
  TEST_ASSERT_EQUAL(NULL, testClass.group[0]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[1]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[2]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[3]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[4]);
}

void test_clearClass_should_empty_a_class(){
  Class testClass = clazzList[0];

  testClass = clearClass(testClass);

  TEST_ASSERT_EQUAL(NULL, testClass.course);
  TEST_ASSERT_EQUAL(NULL, testClass.lecturer);
  TEST_ASSERT_EQUAL(NULL, testClass.typeOfClass);
  TEST_ASSERT_EQUAL(NULL, testClass.group[0]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[1]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[2]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[3]);
  TEST_ASSERT_EQUAL(NULL, testClass.group[4]);
}

void test_clearTimeTable_should_clear_first_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[0][0][0] = clazzList[0];
  
  // double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(&groupList[0], newClass[0][0][0].group[0]);
  TEST_ASSERT_EQUAL(&groupList[1], newClass[0][0][0].group[1]);
  TEST_ASSERT_EQUAL(&groupList[2], newClass[0][0][0].group[2]);
  TEST_ASSERT_EQUAL(&groupList[3], newClass[0][0][0].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[4]);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[4]);

}


void test_clearTimeTable_should_clear_last_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[1][2][5] = clazzList[0];
  
  //double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(&groupList[0], newClass[1][2][5].group[0]);
  TEST_ASSERT_EQUAL(&groupList[1], newClass[1][2][5].group[1]);
  TEST_ASSERT_EQUAL(&groupList[2], newClass[1][2][5].group[2]);
  TEST_ASSERT_EQUAL(&groupList[3], newClass[1][2][5].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[4]);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[4]);

}


void test_clearTimeTable_should_clear_multiple_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[1][2][5] = clazzList[0];
  newClass[0][0][0] = clazzList[0];
  
  //double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(&groupList[0], newClass[0][0][0].group[0]);
  TEST_ASSERT_EQUAL(&groupList[1], newClass[0][0][0].group[1]);
  TEST_ASSERT_EQUAL(&groupList[2], newClass[0][0][0].group[2]);
  TEST_ASSERT_EQUAL(&groupList[3], newClass[0][0][0].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[4]);

  TEST_ASSERT_EQUAL(&courseList[0], newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(&groupList[0], newClass[1][2][5].group[0]);
  TEST_ASSERT_EQUAL(&groupList[1], newClass[1][2][5].group[1]);
  TEST_ASSERT_EQUAL(&groupList[2], newClass[1][2][5].group[2]);
  TEST_ASSERT_EQUAL(&groupList[3], newClass[1][2][5].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[4]);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[4]);
  
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].group[4]);

}

void test_checkEqualClass_should_return_0_when_compare_with_empty_class(){
  Class class1;
  Class class2;
  
  class1 = clazzList[0];
  
  TEST_ASSERT_EQUAL(0, checkEqualClass(class1, class2));
}

void test_checkEqualClass_should_return_0_when_compare_with_different_class(){
  Class class1;
  Class class2;
  
  class1 = clazzList[0];
  class2 = clazzList[2];
  
  TEST_ASSERT_EQUAL(0, checkEqualClass(class1, class2));
}

void test_checkEqualClass_should_return_1_when_compare_empty_class(){
  Class class1;
  Class class2;
  
  class1 = clearClass(class1);
  class2 = clearClass(class2);
  
  TEST_ASSERT_EQUAL(1, checkEqualClass(class1, class2));
}

void test_indexForward_should_increase_time_from_0_to_1(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,0};
  
  indexForward(&newIndex);
  
  TEST_ASSERT_EQUAL(0, newIndex.venue);
  TEST_ASSERT_EQUAL(0, newIndex.day);
  TEST_ASSERT_EQUAL(1, newIndex.time);
}
void test_indexForward_should_increase_day_when_time_maxed(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,5};
  
  indexForward(&newIndex);
  
  TEST_ASSERT_EQUAL(0, newIndex.venue);
  TEST_ASSERT_EQUAL(1, newIndex.day);
  TEST_ASSERT_EQUAL(0, newIndex.time);
}

void test_indexForward_should_increase_venue_when_time_and_day_maxed(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,2,5};
  
  indexForward(&newIndex);
  
  TEST_ASSERT_EQUAL(1, newIndex.venue);
  TEST_ASSERT_EQUAL(0, newIndex.day);
  TEST_ASSERT_EQUAL(0, newIndex.time);
}

void test_indexForward_should_reset_index_when_maxed(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {1,2,5};
  
  indexForward(&newIndex);
  
  TEST_ASSERT_EQUAL(0, newIndex.venue);
  TEST_ASSERT_EQUAL(0, newIndex.day);
  TEST_ASSERT_EQUAL(0, newIndex.time);
}

void test_indexForward_should_throw_error_when_invalid_value(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,-1};
  ErrorCode e;
  
  Try{
  indexForward(&newIndex);}
  Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
}

void test_indexForward_should_throw_error_when_exceeding_value(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {200,0,0};
  ErrorCode e;
  
  Try{
  indexForward(&newIndex);}
  Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
}

void test_indexBackward_should_reduce_time_to_0(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,1};
 
  indexBackward(&newIndex);
  
  TEST_ASSERT_EQUAL(0, newIndex.venue);
  TEST_ASSERT_EQUAL(0, newIndex.day);
  TEST_ASSERT_EQUAL(0, newIndex.time);
}

void test_indexBackward_should_reduce_day_when_time_reaches_0(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,2,0};
 
  indexBackward(&newIndex);
  
  TEST_ASSERT_EQUAL(0, newIndex.venue);
  TEST_ASSERT_EQUAL(1, newIndex.day);
  TEST_ASSERT_EQUAL(5, newIndex.time);
}

void test_indexBackward_should_reduce_venue_when_day_and_time_reaches_0(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {1,0,0};
 
  indexBackward(&newIndex);
  
  TEST_ASSERT_EQUAL(0, newIndex.venue);
  TEST_ASSERT_EQUAL(2, newIndex.day);
  TEST_ASSERT_EQUAL(5, newIndex.time);
}

void test_indexBackward_should_reset_index_when_all_0(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,0};
 
  indexBackward(&newIndex);
  
  TEST_ASSERT_EQUAL(1, newIndex.venue);
  TEST_ASSERT_EQUAL(2, newIndex.day);
  TEST_ASSERT_EQUAL(5, newIndex.time);
}

void test_indexBackward_should_throw_when_invalid_index(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,-1};
  ErrorCode e;
  
  Try{
  indexBackward(&newIndex);}
  Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
}

void test_indexBackward_should_throw_when_exceeded_index(){
  //max venue = 2, day = 3, time = 6
  ClassIndex newIndex = {0,0,100};
  ErrorCode e;
  
  Try{
  indexBackward(&newIndex);}
  Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
}

void test_classIsNull_will_return_0_when_course_available(){
  Class newClass;
  
  newClass = clearClass(newClass);
  
  newClass.course = &courseList[0];
  
  TEST_ASSERT_EQUAL(0, classIsNull(newClass));
}

void test_classIsNull_will_return_0_when_lecturer_available(){
  Class newClass;
  
   newClass = clearClass(newClass);
  
  newClass.lecturer = &lecturerList[0];
  
  TEST_ASSERT_EQUAL(0, classIsNull(newClass));
}

void test_classIsNull_will_return_0_when_typeOfClass_available(){
  Class newClass;
  
   newClass = clearClass(newClass);
  
  newClass.typeOfClass = 'l';
  
  TEST_ASSERT_EQUAL(0, classIsNull(newClass));
}

void test_classIsNull_will_return_0_when_group_available(){
  Class newClass;
  
   newClass = clearClass(newClass);
  
  newClass.group[0] = &groupList[0];
  
  TEST_ASSERT_EQUAL(0, classIsNull(newClass));
}

void test_classIsNull_will_return_1_when_empty_class(){
  Class newClass;
  
   newClass = clearClass(newClass);
  
  TEST_ASSERT_EQUAL(1, classIsNull(newClass));
}
