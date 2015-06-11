#include "unity.h"
#include <stdio.h>
#include "Structure.h"

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
  
  //double check whether assigned
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

  newClass[2][5][1] = clazzList[0];
  
  //double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[2][5][1].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[2][5][1].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[2][5][1].typeOfClass);
  TEST_ASSERT_EQUAL(&groupList[0], newClass[2][5][1].group[0]);
  TEST_ASSERT_EQUAL(&groupList[1], newClass[2][5][1].group[1]);
  TEST_ASSERT_EQUAL(&groupList[2], newClass[2][5][1].group[2]);
  TEST_ASSERT_EQUAL(&groupList[3], newClass[2][5][1].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[4]);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].course);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[4]);

}


void test_clearTimeTable_should_clear_multiple_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[2][5][1] = clazzList[0];
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

  TEST_ASSERT_EQUAL(&courseList[0], newClass[2][5][1].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[2][5][1].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[2][5][1].typeOfClass);
  TEST_ASSERT_EQUAL(&groupList[0], newClass[2][5][1].group[0]);
  TEST_ASSERT_EQUAL(&groupList[1], newClass[2][5][1].group[1]);
  TEST_ASSERT_EQUAL(&groupList[2], newClass[2][5][1].group[2]);
  TEST_ASSERT_EQUAL(&groupList[3], newClass[2][5][1].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[4]);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].group[4]);
  
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].course);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].lecturer);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].typeOfClass);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[0]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[1]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[2]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[3]);
  TEST_ASSERT_EQUAL(NULL, newClass[2][5][1].group[4]);

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