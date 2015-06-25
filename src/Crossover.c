#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Crossover.h"
#include "Structure.h"
#include "Random.h"

#define backwardIndexParam  &venueToLeft,&dayToLeft,&timeToLeft
#define forwardIndexParam   &venueToRight,&dayToRight,&timeToRight
#define backwardIndex       venueToLeft][dayToLeft][timeToLeft
#define forwardIndex        venueToRight][dayToRight][timeToRight
#define backwardOSParam     &venueOSLeft,&dayOSLeft,&timeOSLeft
#define forwardOSParam      &venueOSRight,&dayOSRight,&timeOSRight
#define backwardOSIndex     venueOSLeft][dayOSLeft][timeOSLeft
#define forwardOSIndex      venueOSRight][dayOSRight][timeOSRight
#define counterCourseIndex  classToCheck.course->courseIndex
#define Lecture             'l'
#define Tutorial            't'
#define Practical           'p'


ClassCounter classCount[4] = {0};

/****************************************************************************
 *  Function name : updateEmptyCounter
 *  Inputs        : Class classToCheck, int emptyIndex, int totalEmptySlots
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[emptyIndex].forEmptyClasses
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of empty classes in the timetable
 *****************************************************************************/
int updateEmptyCounter(Class classToCheck, int emptyIndex, int totalEmptySlots){
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
int updateLectureCounter(Class classToCheck){
  if(classCount[counterCourseIndex].lectureCounter < courseList[counterCourseIndex].hoursOfLecture){
    classCount[counterCourseIndex].lectureCounter++;
    return 1;
  }
  else
    return 0;
}

/****************************************************************************
 *  Function name : updateTutorialCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].tutorialCounter
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of tutorial classes for particular course in the timetable
 *****************************************************************************/
int updateTutorialCounter(Class classToCheck){
  if(classCount[counterCourseIndex].tutorialCounter < courseList[counterCourseIndex].hoursOfTutorial){
    classCount[counterCourseIndex].tutorialCounter++;
    return 1;
  }
  else
    return 0;
}

/****************************************************************************
 *  Function name : updatePracticalCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if able to update counter, 0 otherwise
 *  Destroy       : classCount[courseIndex].practicalCounter
 *  Description   : The purpose of this function is to update the scratch pad
 *                  of practical classes for particular course in the timetable
 *****************************************************************************/
int updatePracticalCounter(Class classToCheck){
  if(classCount[counterCourseIndex].practicalCounter < courseList[counterCourseIndex].hoursOfPractical){
    classCount[counterCourseIndex].practicalCounter++;
    return 1;
  }
  else
    return 0;
}
    
/****************************************************************************
 *  Function name : updateCounter
 *  Inputs        : Class classToCheck
 *  Output/return : 1 if valid to extract, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to compare whether
 *                  two different classes have the same elements
 *****************************************************************************/
int updateCounter(Class classToCheck){
  int i;
  int size = getCourseSize();
  int emptyIndex = size;
  int emptyClasses = (MAX_VENUE*MAX_DAY*MAX_TIME_SLOT) - getClazzListSize();
  int returnValue;
  
  if(classIsNull(classToCheck))
    returnValue = updateEmptyCounter(classToCheck, emptyIndex, emptyClasses);
  
  else if(classToCheck.typeOfClass == Lecture)
    returnValue = updateLectureCounter(classToCheck);
  
  else if(classToCheck.typeOfClass == Tutorial)
    returnValue = updateTutorialCounter(classToCheck);
  
  else if(classToCheck.typeOfClass == Practical)
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
int performCrossover(Class Father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class Mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class Offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue){
int stopIndexLeft = 0, stopIndexRight = 0, i = 0;
int venueToLeft, dayToLeft, timeToLeft;
int venueToRight, dayToRight, timeToRight;
int venueOSLeft = totalVenue - 1, dayOSLeft = MAX_DAY - 1, timeOSLeft = MAX_TIME_SLOT -1;
int venueOSRight = 0, dayOSRight = 0, timeOSRight = 0;

randomIndex(backwardIndexParam);
randomIndex(forwardIndexParam);

for( i = 0 ; i < (totalVenue*MAX_DAY*MAX_TIME_SLOT) ; i++){
  if(stopIndexLeft != 1){
    if(updateCounter(Father[backwardIndex])){
      Offspring[backwardOSIndex] = Father[backwardIndex];
      indexBackward(backwardOSParam);
    }
    else
      updateStopFlag(&stopIndexLeft, &stopIndexRight);
    
    indexBackward(backwardIndexParam);	
  }
  if(stopIndexRight != 1){
    if(updateCounter(Mother[forwardIndex])){
      Offspring[forwardOSIndex] = Mother[forwardIndex];
      indexForward(forwardOSParam);
		}
    else
      updateStopFlag(&stopIndexRight, &stopIndexLeft);
    
    indexForward(forwardIndexParam);
  }
}
                     
}


/****************************************************************************
 *  Function name : randomIndex
 *  Inputs        : int *venue, int *day, int *time
 *  Output/return : NONE
 *  Destroy       : venue,day,time
 *  Description   : The purpose of this function is to randomize the
 *                  values of venue,day and time index to pick an offset
 *                  for crossover purpose
 *****************************************************************************/
void randomIndex(int *venue, int *day, int *time){
  *venue = randomVenue();
  *day = randomDay();
  *time = randomTime();
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
