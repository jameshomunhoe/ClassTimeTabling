#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include <stdio.h>
#include "Structure.h"
#include "TestStructure.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){
  initProgrammeList();
  initCourseList();
  initClassList();
  initVenueList();
}
void tearDown(void){}

/************************************************************************
 *  TEST of clearClass
 ************************************************************************/
void test_clearClass_should_empty_an_empty_class(){
  Class testClass;
  
  clearClass(&testClass);

  TEST_ASSERT_EQUAL(NULL, testClass.course);
  TEST_ASSERT_EQUAL(NULL, testClass.lecturer);
  TEST_ASSERT_EQUAL(NULL, testClass.typeOfClass);
  TEST_ASSERT_EQUAL(0, testClass.groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL, testClass.groupInClass);
  
}

void test_clearClass_should_empty_a_class(){
  Class testClass = clazzList[0];

  clearClass(&testClass);

  TEST_ASSERT_EQUAL(NULL, testClass.course);
  TEST_ASSERT_EQUAL(NULL, testClass.lecturer);
  TEST_ASSERT_EQUAL(NULL, testClass.typeOfClass);
  TEST_ASSERT_EQUAL(0, testClass.groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL, testClass.groupInClass);
}

/************************************************************************
 *  TEST of clearTimeTable
 ************************************************************************/
void test_clearTimeTable_should_clear_first_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[0][0][0] = clazzList[0];
  
  // double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(0, newClass[0][0][0].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].groupInClass);
  
  clearTimeTable(newClass);
  
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(0,  newClass[0][0][0].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].groupInClass);

}


void test_clearTimeTable_should_clear_last_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[1][2][5] = clazzList[0];
  
  //double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(0, newClass[1][2][5].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].groupInClass);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(0,  newClass[1][2][5].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].groupInClass);

}

void test_clearTimeTable_should_clear_multiple_element_timeTable(){
  Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT] = {0};

  newClass[1][2][5] = clazzList[0];
  newClass[0][0][0] = clazzList[0];
  
  //double check whether assigned
  TEST_ASSERT_EQUAL(&courseList[0], newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(0, newClass[0][0][0].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL, newClass[0][0][0].groupInClass);

  TEST_ASSERT_EQUAL(&courseList[0], newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(&lecturerList[0], newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL('l', newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(0, newClass[1][2][5].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL, newClass[1][2][5].groupInClass);
  
  clearTimeTable(newClass);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].course);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].lecturer);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].typeOfClass);
  TEST_ASSERT_EQUAL(0,  newClass[0][0][0].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL,  newClass[0][0][0].groupInClass);
  
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].course);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].lecturer);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].typeOfClass);
  TEST_ASSERT_EQUAL(0,  newClass[1][2][5].groupIndexInClass);
  TEST_ASSERT_EQUAL(NULL,  newClass[1][2][5].groupInClass);

}

/************************************************************************
 *  TEST of checkEqualClass
 ************************************************************************/
void test_checkEqualClass_should_return_0_when_compare_with_empty_class(){
  Class class1;
  Class class2;
  
  class1 = clazzList[0];
  
  TEST_ASSERT_EQUAL(0, checkEqualClass(&class1, &class2));
}

void test_checkEqualClass_should_return_0_when_compare_with_different_class(){
  Class class1;
  Class class2;
  
  class1 = clazzList[0];
  class2 = clazzList[2];
  
  TEST_ASSERT_EQUAL(0, checkEqualClass(&class1, &class2));
}

void test_checkEqualClass_should_return_1_when_compare_empty_class(){
  Class class1;
  Class class2;
  
  clearClass(&class1);
  clearClass(&class2);
  
  TEST_ASSERT_EQUAL(1, checkEqualClass(&class1, &class2));
}
/************************************************************************
 *  TEST of indexForward
 ************************************************************************/
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

/************************************************************************
 *  TEST of indexBackward
 ************************************************************************/
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

/************************************************************************
 *  TEST of classIsNull
 ************************************************************************/
void test_classIsNull_will_return_0_when_course_available(){
  Class newClass;
  
  clearClass(&newClass);
  
  newClass.course = &courseList[0];
  
  TEST_ASSERT_EQUAL(0, classIsNull(&newClass));
}

void test_classIsNull_will_return_0_when_lecturer_available(){
  Class newClass;
  
  clearClass(&newClass);
  
  newClass.lecturer = &lecturerList[0];
  
  TEST_ASSERT_EQUAL(0, classIsNull(&newClass));
}

void test_classIsNull_will_return_0_when_typeOfClass_available(){
  Class newClass;
  
  clearClass(&newClass);
  
  newClass.typeOfClass = 'l';
  
  TEST_ASSERT_EQUAL(0, classIsNull(&newClass));
}

void test_classIsNull_will_return_0_when_group_available(){
  Class newClass;
  
  clearClass(&newClass);
  
  newClass.groupIndexInClass = 1;
  
  TEST_ASSERT_EQUAL(0, classIsNull(&newClass));
}

void test_classIsNull_will_return_1_when_empty_class(){
  Class newClass;
  
  clearClass(&newClass);
  
  TEST_ASSERT_EQUAL(1, classIsNull(&newClass));
}

/************************************************************************
 *  TEST of courseGetNumberOfCombinedGroups
 ************************************************************************/
void test_courseGetNumberOfCombinedGroups_should_get_2_from_course_0(){
  TEST_ASSERT_EQUAL(2,courseGetNumberOfCombinedGroups(&courseList[0]));
  
}

void test_courseGetNumberOfCombinedGroups_should_get_2_from_course_1(){
  TEST_ASSERT_EQUAL(2,courseGetNumberOfCombinedGroups(&courseList[1]));
  
}

void test_courseGetNumberOfCombinedGroups_should_get_2_from_course_2(){
  TEST_ASSERT_EQUAL(2,courseGetNumberOfCombinedGroups(&courseList[2]));
  
}

void test_courseGetNumberOfCombinedGroups_should_get_0_from_empty_course(){
  Course *emptyCourse = NULL;
  
  TEST_ASSERT_EQUAL(0,courseGetNumberOfCombinedGroups(emptyCourse));
  
}

/************************************************************************
 *  TEST of courseGetCombinedGroups
 ************************************************************************/
void test_courseGetCombinedGroups_should_throw_when_index_exceeded(){
  ErrorCode e;
  
  int groupSize;
  
  Try{
    courseGetCombinedGroups(&courseList[0],2,&groupSize);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
}

void test_courseGetCombinedGroups_should_throw_when_course_is_empty(){
  ErrorCode e;
  
  Course *emptyCourse = NULL;
  int groupSize;
  
  Try{
    courseGetCombinedGroups(emptyCourse,0,&groupSize);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EMPTY_COURSE, e);
  }
}

void test_courseGetCombinedGroups_should_return_group_0_and_1(){

  Group **groupsInCourse;
  int groupSize;
  

  groupsInCourse = courseGetCombinedGroups(&courseList[0],0,&groupSize);

  TEST_ASSERT_EQUAL_PTR(&groupList[0],groupsInCourse[0]);
  TEST_ASSERT_EQUAL_PTR(&groupList[1],groupsInCourse[1]);
  TEST_ASSERT_EQUAL(2,groupSize);
}

void test_courseGetCombinedGroups_should_return_group_1_and_2(){

  Group **groupsInCourse;
  int groupSize;
  

  groupsInCourse = courseGetCombinedGroups(&courseList[0],1,&groupSize);

  TEST_ASSERT_EQUAL_PTR(&groupList[2],groupsInCourse[0]);
  TEST_ASSERT_EQUAL_PTR(&groupList[3],groupsInCourse[1]);
  TEST_ASSERT_EQUAL(2,groupSize);
}

/************************************************************************
 *  TEST of combinedGroupsGetName
 ************************************************************************/
void test_combinedGroupsGetName_should_throw_when_index_exceeded(){
  ErrorCode e;
  
  Try{
    combinedGroupsGetName(courseList[0].combinedGroups,2);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_EXCEEDED_INDEX, e);
  }
}

void test_combinedGroupsGetName_should_get_JJ1(){

  char *groupName;
  

  groupName = combinedGroupsGetName(courseList[0].combinedGroups,0);

  TEST_ASSERT_EQUAL_STRING("JJ1", groupName);

}

void test_combinedGroupsGetName_should_get_K2(){

  char *groupName;
  

  groupName = combinedGroupsGetName(&(courseList[2].combinedGroups[1]),1);

  TEST_ASSERT_EQUAL_STRING("K2", groupName);

}

/************************************************************************
 *  TEST of courseGetProgrammes
 ************************************************************************/
void test_courseGetProgrammes_should_get_programme_0_and_1(){

  Programme **programmes;
  int numberOfProgrammes;

  programmes = courseGetProgrammes(&courseList[0],&numberOfProgrammes);

  TEST_ASSERT_EQUAL(2, numberOfProgrammes);
  TEST_ASSERT_EQUAL_PTR(&programmeList[0], programmes[0]);
  TEST_ASSERT_EQUAL_PTR(&programmeList[1], programmes[1]);

}

void test_courseGetProgrammes_should_get_programme_1_and_2(){

  Programme **programmes;
  int numberOfProgrammes;

  programmes = courseGetProgrammes(&courseList[1],&numberOfProgrammes);

  TEST_ASSERT_EQUAL(2, numberOfProgrammes);
  TEST_ASSERT_EQUAL_PTR(&programmeList[1], programmes[0]);
  TEST_ASSERT_EQUAL_PTR(&programmeList[2], programmes[1]);

}

/************************************************************************
 *  TEST of programmeGetNames
 ************************************************************************/
void test_programmeGetNames_should_get_programName_RMB3(){

  char *programmeName;

  programmeName = programmeGetName(&programmeList[0]);

  TEST_ASSERT_EQUAL_STRING("RMB3", programmeName);

}

void test_programmeGetNames_should_get_programName_DMK2(){

  char *programmeName;

  programmeName = programmeGetName(&programmeList[2]);

  TEST_ASSERT_EQUAL_STRING("DMK2", programmeName);

}

/************************************************************************
 *  TEST of classGetTotalStudentInLecture
 ************************************************************************/
void test_classGetTotalStudentInLecture_should_return_72(){
 
  TEST_ASSERT_EQUAL(72, classGetTotalStudentInLecture(&clazzList[0]));
}

void test_classGetTotalStudentInLecture_should_return_60(){
 
  TEST_ASSERT_EQUAL(60, classGetTotalStudentInLecture(&clazzList[4]));
}

/************************************************************************
 *  TEST of classGetTotalStudent
 ************************************************************************/
void test_classGetTotalStudent_should_return_72_lecture(){
  
  TEST_ASSERT_EQUAL(72, classGetTotalStudent(&clazzList[0]));
}

void test_classGetTotalStudent_should_return_60_lecture(){
  
  TEST_ASSERT_EQUAL(60, classGetTotalStudent(&clazzList[4]));
}

void test_classGetTotalStudent_should_return_32_tutorial(){
  
  TEST_ASSERT_EQUAL(32, classGetTotalStudent(&clazzList[2]));
}

void test_classGetTotalStudent_should_return_40_tutorial(){
  
  TEST_ASSERT_EQUAL(40, classGetTotalStudent(&clazzList[3]));
}

/************************************************************************
 *  TEST of getIndexInList
 ************************************************************************/
void test_getIndexInList_should_throw_error_when_invalid_type(){
  ErrorCode e;
  int index;
  
  Try{
    getIndexInList(&programmeList[0], 'k');
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_INVALID_TYPE,e);
  }
}

void test_getIndexInList_should_return_courseList_index_0(){
  int index;
  
  index =  getIndexInList(&courseList[0], 'c');

  TEST_ASSERT_EQUAL(0, index);

}

void test_getIndexInList_should_return_courseList_index_2(){
  int index;
  
  index =  getIndexInList(&courseList[2], 'c');

  TEST_ASSERT_EQUAL(2, index);

}

void test_getIndexInList_should_return_exceeded_courseList_index_because_reserved_memory(){
  int index;
  
  index =  getIndexInList(&courseList[1000000], 'c');

  TEST_ASSERT_EQUAL(1000000, index);

}

void test_getIndexInList_should_return_lecturerList_index_0(){
  int index;
  
  index =  getIndexInList(&lecturerList[0], 'l');

  TEST_ASSERT_EQUAL(0, index);

}

void test_getIndexInList_should_return_lecturerList_index_2(){
  int index;
  
  index =  getIndexInList(&lecturerList[2], 'l');

  TEST_ASSERT_EQUAL(2, index);

}

void test_getIndexInList_should_return_exceeded_lecturerList_index_because_reserved_memory(){
  int index;
  
  index =  getIndexInList(&lecturerList[1000000], 'l');

  TEST_ASSERT_EQUAL(1000000, index);

}

void test_getIndexInList_should_return_groupList_index_0(){
  int index;
  
  index =  getIndexInList(&groupList[0], 'g');

  TEST_ASSERT_EQUAL(0, index);

}

void test_getIndexInList_should_return_groupList_index_2(){
  int index;
  
  index =  getIndexInList(&groupList[2], 'g');

  TEST_ASSERT_EQUAL(2, index);

}

void test_getIndexInList_should_return_programmeList_index_0(){
  int index;
  
  index =  getIndexInList(&programmeList[0], 'p');

  TEST_ASSERT_EQUAL(0, index);

}

void test_getIndexInList_should_return_programmeList_index_2(){
  int index;
  
  index =  getIndexInList(&programmeList[2], 'p');

  TEST_ASSERT_EQUAL(2, index);

}

void test_getIndexInList_should_return_venueList_index_0(){
  int index;
  
  index =  getIndexInList(&venueList[0], 'v');

  TEST_ASSERT_EQUAL(0, index);

}

void test_getIndexInList_should_return_venueList_index_1(){
  int index;
  
  index =  getIndexInList(&venueList[1], 'v');

  TEST_ASSERT_EQUAL(1, index);

}
