#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Crossover.h"
#include "Structure.h"
#include "Random.h"


#define offpringLeftArr     offpringLeft.venue][offpringLeft.day][offpringLeft.time
#define offpringRightArr    offpringRight.venue][offpringRight.day][offpringRight.time
#define toRightIndexArr     toRightIndex.venue][toRightIndex.day][toRightIndex.time
#define toLeftIndexArr      toLeftIndex.venue][toLeftIndex.day][toLeftIndex.time
#define counterCourseIndex  classToCheck.course->courseIndex
#define Lecture             'l'
#define Tutorial            't'
#define Practical           'p'


ClassCounter *classCount;

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
 *  Function name : updateEmptyCounter
 *  Inputs        : int emptyIndex, int totalEmptySlots
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[emptyIndex].forEmptyClasses
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of empty classes in the timetable
 *****************************************************************************/
int updateEmptyCounter(int emptyIndex, int totalEmptySlots){
  if(classCount[emptyIndex].forEmptyClasses < totalEmptySlots){
    classCount[emptyIndex].forEmptyClasses++;
    return 1;
  }
  else
    return 0;
}

/****************************************************************************
 *  Function name : updateLectureCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].lectureCounter
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of lecture classes for particular course in the timetable
 *****************************************************************************/
int updateLectureCounter(Class *classToCheck){
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
 *  Function name : updateTutorialCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].tutorialCounter
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of tutorial classes for particular course in the timetable
 *****************************************************************************/
int updateTutorialCounter(Class *classToCheck){
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
 *  Function name : updatePracticalCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].practicalCounter
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of practical classes for particular course in the timetable
 *****************************************************************************/
int updatePracticalCounter(Class *classToCheck){
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
 *  Function name : updateCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if valid to extract, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to compare whether
 *                  two different classes have the same elements
 *****************************************************************************/
int updateCounter(Class *classToCheck){
  int i;
  int size = getCourseSize();
  int emptyIndex = size;
  int emptyClasses = (MAX_VENUE*MAX_DAY*MAX_TIME_SLOT) - getClazzListSize();
  int returnValue;
  
  if(classIsNull(classToCheck))
    returnValue = updateEmptyCounter(emptyIndex, emptyClasses);
  
  else if(classToCheck->typeOfClass == Lecture)
    returnValue = updateLectureCounter(classToCheck);
  
  else if(classToCheck->typeOfClass == Tutorial)
    returnValue = updateTutorialCounter(classToCheck);
  
  else if(classToCheck->typeOfClass == Practical)
    returnValue = updatePracticalCounter(classToCheck);
  
  return returnValue;
}


/****************************************************************************
 *  Function name : performCrossover
 *  Inputs        : Class Father[][MAX_DAY][MAX_TIME_SLOT], 
 *                  Class Mother[][MAX_DAY][MAX_TIME_SLOT], 
 *                  Class Offspring[][MAX_DAY][MAX_TIME_SLOT],
 *                  int totalVenue
 *  Output/return : NONE
 *  Destroy       : Offspring[][][]
 *  Description   : The purpose of this function is to perform crossover
 *                  on 2 candidates Father&Mother. Crossover extracts the
 *                  elements from the parents in certain order and sort
 *                  nicely according to the order to create an offspring
 *****************************************************************************/
 void performCrossover(Class father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue){
int stopIndexLeft = 0, stopIndexRight = 0, i = 0;
ClassIndex toLeftIndex;
ClassIndex toRightIndex;
ClassIndex offpringLeft;
ClassIndex offpringRight;

randomIndex(&toLeftIndex);
randomIndex(&toRightIndex);
getMidPoint(&offpringLeft,&offpringRight,totalVenue);

for( i = 0 ; i < (totalVenue*MAX_DAY*MAX_TIME_SLOT) ; i++){
  if(stopIndexLeft != 1){
    if(updateCounter(&father[toLeftIndexArr])){
      offspring[offpringLeftArr] = father[toLeftIndexArr];
      indexBackward(&offpringLeft);
    }
    else
      updateStopFlag(&stopIndexLeft, &stopIndexRight);
    
    indexBackward(&toLeftIndex);
  }
  if(stopIndexRight != 1){
    if(updateCounter(&mother[toRightIndexArr])){
      offspring[offpringRightArr] = mother[toRightIndexArr];
      indexForward(&offpringRight);
		}
    else
      updateStopFlag(&stopIndexRight, &stopIndexLeft);
    
    indexForward(&toRightIndex);
  }
}

             
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

/****************************************************************************
 *  Function name : getMidPoint
 *  Inputs        : ClassIndex *classIndexLeft,\
                    ClassIndex *classIndexRight,\
                    int totalVenue
 *  Output/return : NONE
 *  Destroy       : classIndexLeft,classIndexRight
 *  Description   : The purpose of this function is to get the midpoint
 *                  of the 3D timetable array for offSpring offset
 *****************************************************************************/
void getMidPoint(ClassIndex *classIndexLeft,\
                 ClassIndex *classIndexRight,\
                 int totalVenue){
  int mid = (totalVenue*MAX_DAY*MAX_TIME_SLOT) / 2;
  int i;
  classIndexLeft->venue = 0;
  classIndexLeft->day = 0;
  classIndexLeft->time = 0;
  classIndexRight->venue = 0;
  classIndexRight->day = 0;
  classIndexRight->time= 0;
  
  for(i = 0 ; i < mid ; i++){
    indexForward(classIndexLeft);
    indexForward(classIndexRight);
  }
  indexForward(classIndexRight);
}

/****************************************************************************
 *  Function name : updateStopFlag
 *  Inputs        : int *currentSide, int *oppositeSide
 *  Output/return : NONE
 *  Destroy       : currentSide
 *  Description   : The purpose of this function is to update the flag
 *                  everytime performing crossover to indicates which
 *                  side should stop extracting elements.
 *****************************************************************************/
void updateStopFlag(int *currentSide, int *oppositeSide){
  if(*oppositeSide == 0)
    *currentSide = 1;
}
