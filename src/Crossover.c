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
