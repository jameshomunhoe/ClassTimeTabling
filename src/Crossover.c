#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Crossover.h"
#include "Structure.h"
#include "Random.h"

ClassCounter classCount[4] = {0};

/**
* Required functions for aiding crossover
* - Compare class (doing)
* - Compare obtained with classList
* - Swapping elements between two different chromosome
*
**/

//return 0 if no clashes
//return 1 if clashes
int updateCounter(Class classToCheck){
  int i;
  int size = getCourseSize();
  int emptyClasses = (MAX_VENUE*MAX_DAY*MAX_TIME_SLOT) - getClazzListSize();

  
  if(classToCheck.course == NULL){
    if(classCount[size].forEmptyClasses < emptyClasses)
     classCount[size].forEmptyClasses++;
    else
     return 0;
  }
  else{
    for( i = 0 ; i < size ; i++){
      if( strcmp(classToCheck.course->courseName, courseList[i].courseName) == 0){
        if(classToCheck.typeOfClass == 'l'){
          if(classCount[i].lectureCounter < courseList[i].hoursOfLecture){
            classCount[i].lectureCounter++;
            return 1;
          }
          else
            return 0;
        }
        if(classToCheck.typeOfClass == 't'){
          if(classCount[i].tutorialCounter < courseList[i].hoursOfTutorial){
            classCount[i].tutorialCounter++;
            return 1;
          }
          else
            return 0;
        }
        if(classToCheck.typeOfClass == 'p'){
          if(classCount[i].practicalCounter < courseList[i].hoursOfPractical){
            classCount[i].practicalCounter++;
            return 1;
          }
          else
            return 0;
        }
      }
    } 
  }
  
  return 1;
}

int performCrossover(Class Father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class Mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class Offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue){
int stopIndexLeft = 0, stopIndexRight = 0, i = 0;
int venueToLeft = totalVenue - 1, dayToLeft =  MAX_DAY - 1, timeToLeft = MAX_TIME_SLOT -1;
int venueToRight = 0, dayToRight = 0, timeToRight = 0;
int venueOSLeft = totalVenue - 1, dayOSLeft = MAX_DAY - 1, timeOSLeft = MAX_TIME_SLOT -1;
int venueOSRight = 0, dayOSRight = 0, timeOSRight = 0;


for( i = 0 ; i < (totalVenue*MAX_DAY*MAX_TIME_SLOT) ; i++){
  if(stopIndexLeft != 1){
		if(updateCounter(Father[venueToLeft][dayToLeft][timeToLeft])){
			Offspring[venueOSLeft][dayOSLeft][timeOSLeft] = copyClassSlot(Father[venueToLeft][dayToLeft][timeToLeft]);
      indexBackward(&venueOSLeft,&dayOSLeft,&timeOSLeft);
    }
    else{
      if(stopIndexRight == 0)
        stopIndexLeft = 1;
    }
    indexBackward(&venueToLeft,&dayToLeft,&timeToLeft);	
  }
  if(stopIndexRight != 1){
    if(updateCounter(Mother[venueToRight][dayToRight][timeToRight])){
      Offspring[venueOSRight][dayOSRight][timeOSRight] = copyClassSlot(Mother[venueToRight][dayToRight][timeToRight]);
      indexForward(&venueOSRight,&dayOSRight,&timeOSRight);
		}
    else{
      if(stopIndexLeft == 0)
        stopIndexRight = 1;
    }
    indexForward(&venueToRight,&dayToRight,&timeToRight);
  }
}
                     
}