#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include <stdio.h>
#include "Structure.h"
#include "ErrorCode.h"
#include "CException.h"
#include "malloc.h"

  
void setUp(void){}
void tearDown(void){}

void test_clearClass_should_empty_an_empty_class(){
  initProgrammeList();
  initCourseList();
  initClassList();
  
  printf("%s\n",clazzList[2].groupInClass->groups[0]->groupName);

}