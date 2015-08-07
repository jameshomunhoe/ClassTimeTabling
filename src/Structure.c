#include <stdio.h>
#include "Random.h"
#include "Structure.h"
#include "TestStructure.h"
#include "CException.h"
#include "ErrorCode.h"
#include "malloc.h"

#define FOR_TEST

#define Lecture             'l'
#define Tutorial            't'
#define Practical           'p'


ClassCounter *classCount;
            
/****************************************************************************
 * Functions
 *****************************************************************************/
 


/****************************************************************************
 *  Function name : clearClass
 *  Inputs        : Class sourceClass
 *  Output/return : NONE
 *  Destroy       : Class sourceClass
 *  Description   : The purpose of this function is to clear particular slot in class[][][]
 *****************************************************************************/
void clearClass(Class *sourceClass){
  
  sourceClass->course = NULL;
  sourceClass->lecturer = NULL;
  sourceClass->typeOfClass = 0;
  sourceClass->groupIndexInClass = 0;
  sourceClass->groupInClass = NULL;
}

/****************************************************************************
 *  Function name : clearTimeTable
 *  Inputs        : Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS]
 *  Output/return : NONE
 *  Destroy       : Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS]
 *  Description   : The purpose of this function is to clear a class[][][]
 *****************************************************************************/
void clearTimeTable(Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  int venue, day, time;
  
  for( venue = 0 ; venue < MAX_VENUE ; venue++ ){
    for( day = 0 ; day < MAX_DAY ; day++ ){
      for( time = 0 ; time < MAX_TIME_SLOT ; time++ ){
        clearClass(&sourceClass[venue][day][time]);
      }
    }
  }
}

/****************************************************************************
 *  Function name : checkEqualClass
 *  Inputs        : Class sourceClass, Class classToCompare
 *  Output/return : 1 if equal, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to compare whether
 *                  two different classes have the same elements
 *****************************************************************************/
int checkEqualClass(Class *newClass, Class *newClass2){

  if(newClass->course == NULL && newClass2->course == NULL)
    return 1;
  
  if(newClass->course != newClass2->course)
    return 0;
  
  if(newClass->lecturer != newClass2->lecturer)
    return 0;
  
  if(newClass->typeOfClass != newClass2->typeOfClass)
    return 0;
  
  if(newClass->groupIndexInClass != newClass2->groupIndexInClass)
    return 0;
  
  if(newClass->groupInClass || newClass2->groupInClass){
    if(newClass->groupInClass != newClass2->groupInClass)
      return 0;
  }

    
  return 1;
}

/****************************************************************************
 *  Function name : classIsNull
 *  Inputs        : Class sourceClass
 *  Output/return : 1 if class is NULL, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to perform 
 *                  class checking to make sure it is NULL or contains data
 *****************************************************************************/
int classIsNull(Class *sourceClass){
  
  if(sourceClass->course != NULL)
    return 0;
  if(sourceClass->lecturer != NULL)
    return 0;
  if(sourceClass->typeOfClass != 0)
    return 0;
  if(sourceClass->groupIndexInClass != 0)
    return 0;
  if(sourceClass->groupInClass != NULL)
    return 0;
  
  return 1;
}

/****************************************************************************
 *  Function name : classGetTotalStudent
 *  Inputs        : Class classToCheck
 *  Output/return : totalStudents
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to perform 
 *                  class checking and return the total students in the class
 *****************************************************************************/
int classGetTotalStudent(Class *classToCheck){
  int combinedGroupSize, totalCombinedGroups, i;
  int totalStudents = 0;
  Group **groups;
  
  if(classIsNull(classToCheck))
    return 0;
  
  if(classToCheck->groupInClass == NULL){
    totalStudents = classGetTotalStudentInLecture(classToCheck);
    return totalStudents;
  }
  else{
    groups = courseGetCombinedGroups(classToCheck->course,classToCheck->groupIndexInClass, &combinedGroupSize);
  
    for(i = 0 ; i < combinedGroupSize ; i++){
      totalStudents += groups[i]->groupSize;
    }
  }
  return totalStudents;
}

/****************************************************************************
 *  Function name : classGetTotalStudentInLecture
 *  Inputs        : Class classToCheck
 *  Output/return : totalStudents(lecture only)
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to perform 
 *                  class checking and return the total students in lectureClass
 *                  This is a sub-function of classGetTotalStudent
 *****************************************************************************/
int classGetTotalStudentInLecture(Class *classToCheck){
  int combinedGroups, combinedGroupSize, i, j;
  int totalStudents = 0;
  Group **groups;
  
  combinedGroups = courseGetNumberOfCombinedGroups(classToCheck->course);

  for(i = 0 ; i < combinedGroups ; i++){
    groups = courseGetCombinedGroups(classToCheck->course,i, &combinedGroupSize);
  
    for(j = 0 ; j < combinedGroupSize ; j++){
      totalStudents += groups[j]->groupSize;
    }
  }
  return totalStudents;
}

/****************************************************************************
 *  Function name : courseGetNumberOfCombinedGroups
 *  Inputs        : Class *course
 *  Output/return : The number of combined group(s) in the course
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to return the total 
 *                  combined groups in the course.
 *****************************************************************************/
int courseGetNumberOfCombinedGroups(Course *course){
  if(course != NULL)
    return course->numOfCombinedGroups;
  else
    return 0;
}

/****************************************************************************
 *  Function name : courseGetCombinedGroups
 *  Inputs        : Course *course, int index, int *number
 *  Output/return : **group in the selected combinedGroup
 *  Destroy       : int *number
 *  Description   : The purpose of this function is to return the group(s)
 *                  in the selected combinedGroup according the index
 *****************************************************************************/
Group **courseGetCombinedGroups(Course *course, int index, int *number){
  
  if(course == NULL)
    Throw(ERR_EMPTY_COURSE);
  
  if(index >= course->numOfCombinedGroups)
    Throw(ERR_EXCEEDED_INDEX);
  
  (*number) = course->combinedGroups[index].size;
  
  return (course->combinedGroups[index].groups);
}

/****************************************************************************
 *  Function name : combinedGroupsGetName
 *  Inputs        : CombinedGroups *combinedGroups, int index
 *  Output/return : *char the name of selected group in combinedGroup
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to return the name of selected
 *                  group among the combinedGroup
 *****************************************************************************/
char *combinedGroupsGetName(CombinedGroups *combinedGroups, int index){
  if(index >= combinedGroups->size)
    Throw(ERR_EXCEEDED_INDEX);
  
  if(combinedGroups->groups[index])
    return combinedGroups->groups[index]->groupName;
}

/****************************************************************************
 *  Function name : courseGetProgrammes
 *  Inputs        : Course *course, int *number
 *  Output/return : **programme in the course
 *  Destroy       : *number
 *  Description   : The purpose of this function is to return the programme(s)
 *                  in the course.
 *                  *number will be replaced with the number of programmes in course
 *****************************************************************************/
Programme **courseGetProgrammes(Course *course, int *number){
  if(course != NULL){
    (*number) = course->numOfProgramme;
    return course->programme;
  }
}

/****************************************************************************
 *  Function name : programmeGetName
 *  Inputs        : Programme *programme
 *  Output/return : *char nameOfProgramme
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to return the programme's
 *                  name.
 *****************************************************************************/
char *programmeGetName(Programme *programme){
  if(programme != NULL)
    return programme->programmeName;
  
}

/****************************************************************************
 *  Function name : getIndexInList
 *  Inputs        : void *data, char type
 *  Output/return : int indexOfDataInList
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to return the data's index
 *                  as declare in the list.
 *                  It is able to return the index for courseList, lecturerList,
 *                  groupList, programmeList and venueList
 *****************************************************************************/
int getIndexInList(void *data, char type){
  
  int *addressOfData = (int*)data;
  int *addressOfFirstIndex = 0;
  int index = 0, sizeOfType;
  
  switch(type){
    case 'c':
      addressOfFirstIndex = (int*)(&courseList[0]);
      sizeOfType = sizeof(Course);
      break;
      
    case 'l':
      addressOfFirstIndex = (int*)(&lecturerList[0]);
      sizeOfType = sizeof(Lecturer);
      break;
      
    case 'g':
      addressOfFirstIndex = (int*)(&groupList[0]);
      sizeOfType = sizeof(Group);
      break;
      
    case 'p':
      addressOfFirstIndex = (int*)(&programmeList[0]);
      sizeOfType = sizeof(Programme);
      break;
      
    case 'v':
      addressOfFirstIndex = (int*)(&venueList[0]);
      sizeOfType = sizeof(Venue);
      break;
      
    default:
      Throw(ERR_INVALID_TYPE);
      break;
  }
  
  //mutiply 4 because 1 = 4 bits
  index = ((addressOfData-addressOfFirstIndex)*4)/sizeOfType;
  
  return index;
  
}

/****************************************************************************
 *  Function name : indexForward
 *  Inputs        : ClassIndex *classIndex
 *  Output/return : NONE
 *  Destroy       : classIndex->venue, classIndex->day, classIndex->time
 *  Description   : The purpose of this function is to perform 
 *                  3-Dimensional array index incremental. index will
 *                  reset to 0,0,0 when overload
 *****************************************************************************/
void indexForward(ClassIndex *classIndex){

  if(classIndex->venue < 0 || classIndex->day < 0 || classIndex->time < 0)
    Throw(ERR_EXCEEDED_INDEX);
  if(classIndex->venue >= MAX_VENUE || classIndex->day >= MAX_DAY || classIndex->time >= MAX_TIME_SLOT)
    Throw(ERR_EXCEEDED_INDEX);

  (classIndex->time)++;
  
  if(classIndex->time >= MAX_TIME_SLOT){
    classIndex->time = 0;
    (classIndex->day)++;
  }
  if(classIndex->day >= MAX_DAY){
    classIndex->day = 0;
    (classIndex->venue)++;
  }
  if(classIndex->venue >= MAX_VENUE)
    classIndex->venue = 0;
}

/****************************************************************************
 *  Function name : indexBackward
 *  Inputs        : ClassIndex *classIndex
 *  Output/return : NONE
 *  Destroy       : classIndex->venue, classIndex->day, classIndex->time
 *  Description   : The purpose of this function is to perform 
 *                  3-Dimensional array index decremental. index will
 *                  reset to max value of each index when less than 0,0,0
 *****************************************************************************/
void indexBackward(ClassIndex *classIndex){
  
  if(classIndex->venue < 0 || classIndex->day < 0 || classIndex->time < 0)
    Throw(ERR_EXCEEDED_INDEX);
  if(classIndex->venue >= MAX_VENUE || classIndex->day >= MAX_DAY || classIndex->time >= MAX_TIME_SLOT)
    Throw(ERR_EXCEEDED_INDEX);
  
  (classIndex->time)--;
  
  if(classIndex->time < 0){
    classIndex->time = MAX_TIME_SLOT - 1;
    (classIndex->day)--;
  }
  if(classIndex->day < 0){
    classIndex->day = MAX_DAY - 1;
    (classIndex->venue)--;
  }
  if(classIndex->venue < 0)
    classIndex->venue = MAX_VENUE - 1;
}

/****************************************************************************
 *  Function name : initClassCounter
 *  Inputs        : NONE
 *  Output/return : NONE
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to initialize the classCount
 *                  by malloc according to the amount of course, and groups
 *****************************************************************************/
void initClassCounter(){
  int i, j;
  int courseSize = getCourseSize();
  int groupSize = getGroupSize();
  
  classCount = calloc(courseSize+1, sizeof(ClassCounter));
  
  
  for(i = 0 ; i < courseSize+1 ; i++){
    classCount[i].groupCounter = calloc(groupSize, sizeof(ClassGroupCounter));
  }
  
 
}

/****************************************************************************
 *  Function name : updateEmptyCounterFromClass
 *  Inputs        : int emptyIndex, int totalEmptySlots
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[emptyIndex].forEmptyClasses
 *  Description   : The purpose of this function is to plot the amount of empty
 *                  classes had scan through
 *****************************************************************************/
int updateEmptyCounterFromClass(int emptyIndex, int totalEmptySlots){
  if(classCount[emptyIndex].forEmptyClasses < totalEmptySlots){
    classCount[emptyIndex].forEmptyClasses++;
    return 1;
  }
  else
    return 0;
}

/****************************************************************************
 *  Function name : updateGroupLectureCounterFromClass
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].lectureCounter
 *  Description   : The purpose of this function is to plot the histogram of 
 *                  each group to keep track the Lecture classes taken by them
 *****************************************************************************/
int updateGroupLectureCounterFromClass(Class *classToCheck){
  int gSize, cgSize, courseIndex, groupIndex, i, j;
  Group **receivedGroup;
  cgSize = courseGetNumberOfCombinedGroups(classToCheck->course);
  
  
  for(i = 0 ; i < cgSize ; i++){
    receivedGroup = courseGetCombinedGroups(classToCheck->course, i, &gSize);
    courseIndex = getIndexInList(classToCheck->course, 'c');
 
    for(j = 0 ; j < gSize ; j++){
      groupIndex = getIndexInList(receivedGroup[j], 'g');
      if(classCount[courseIndex].groupCounter[groupIndex].lectureCounter < courseList[courseIndex].hoursOfLecture)
        classCount[courseIndex].groupCounter[groupIndex].lectureCounter++;
      else
        return 0;
      
    }
  }
  
  return 1;
}

/****************************************************************************
 *  Function name : updateGroupTutorialCounterFromClass
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].tutorialCounter
 *  Description   : The purpose of this function is to plot the histogram of 
 *                  each group to keep track the Tutorial classes taken by them
 *****************************************************************************/
int updateGroupTutorialCounterFromClass(Class *classToCheck){
  int gSize, courseIndex, groupIndex, i;
  Group **receivedGroup;
  
  receivedGroup = courseGetCombinedGroups(classToCheck->course, classToCheck->groupIndexInClass, &gSize);
  courseIndex = getIndexInList(classToCheck->course, 'c');
    
  for(i = 0 ; i < gSize ; i++){
      groupIndex = getIndexInList(receivedGroup[i], 'g');
      if(classCount[courseIndex].groupCounter[groupIndex].tutorialCounter < courseList[courseIndex].hoursOfTutorial)
        classCount[courseIndex].groupCounter[groupIndex].tutorialCounter++;
      else
        return 0;
      
    }
  
  return 1;
}

/****************************************************************************
 *  Function name : updateGroupPracticalCounterFromClass
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].practicalCounter
 *  Description   : The purpose of this function is to plot the histogram of 
 *                  each group to keep track the practical classes taken by them
 *****************************************************************************/
int updateGroupPracticalCounterFromClass(Class *classToCheck){
  int gSize, courseIndex, groupIndex, i;
  Group **receivedGroup;
  
  receivedGroup = courseGetCombinedGroups(classToCheck->course, classToCheck->groupIndexInClass, &gSize);
  courseIndex = getIndexInList(classToCheck->course, 'c');
    
  for(i = 0 ; i < gSize ; i++){
      groupIndex = getIndexInList(receivedGroup[i], 'g');
      if(classCount[courseIndex].groupCounter[groupIndex].practicalCounter < courseList[courseIndex].hoursOfPractical)
        classCount[courseIndex].groupCounter[groupIndex].practicalCounter++;
      else
        return 0;
      
    }
  
  return 1;
}
    
/****************************************************************************
 *  Function name : updateGroupCounterFromClass
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if valid to extract, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to plot the histogram of 
 *                  each group to keep track of classes taken by them
 *****************************************************************************/
int updateGroupCounterFromClass(Class *classToCheck){
  int i;
  int size = getCourseSize();
  int emptyIndex = size;
  int emptyClasses = (MAX_VENUE*MAX_DAY*MAX_TIME_SLOT) - getClazzListSize();
  int returnValue;
  
  if(classIsNull(classToCheck))
    returnValue = updateEmptyCounterFromClass(emptyIndex, emptyClasses);
  
  else if(classToCheck->typeOfClass == Lecture)
    returnValue = updateGroupLectureCounterFromClass(classToCheck);
  
  else if(classToCheck->typeOfClass == Tutorial)
    returnValue = updateGroupTutorialCounterFromClass(classToCheck);
  
  else if(classToCheck->typeOfClass == Practical)
    returnValue = updateGroupPracticalCounterFromClass(classToCheck);
  
  return returnValue;
}

/****************************************************************************
 *  Function name : randomIndex
 *  Inputs        : ClassIndex *classIndex
 *  Output/return : NONE
 *  Destroy       : classIndex
 *  Description   : The purpose of this function is to randomize the
 *                  values of venue,day and time index to pick an offset
 *                  for crossover purpose
 *****************************************************************************/
void randomIndex(ClassIndex *classIndex){
  classIndex->venue = randomVenue();
  classIndex->day = randomDay();
  classIndex->time = randomTime();
}