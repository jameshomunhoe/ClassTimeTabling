#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Constraints.h"
#include "Structure.h"
#include "CException.h"
#include "ErrorCode.h"

//  Formula to get totalVenue
//  (sizeof(exampleClass)/sizeof(Class))/(sizeof(exampleClass[0])/sizeof(Class)));


/****************************************************************************
 *	Function name	:	studyHourOverloaded
 *	Inputs				: Class sourceClass[][][], dayToCheck, totalVenue
 *	Output/return	: number of violation
 *	Destroy				:	NONE
 *	Description		:	The purpose of this function is to calculate the
 *                  violation of same group of student study more than 4 hours
 *                  a day
 *****************************************************************************/
int studyHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, \
                        int totalVenue)
{

 int i, j, time, venue;
 int violation = 0;
 int groupSize = getGroupSize();
 int groupCounter[groupSize];
 clearCounter(groupSize,groupCounter);
 
 if(dayToCheck >= MAX_DAY)
  Throw(ERR_EXCEEDED_INDEX);
 
 for(venue = 0 ; venue < totalVenue ; venue++){
  for(time = 0 ; time < MAX_TIME_SLOT ; time++){
   for(i = 0 ; newClass[venue][dayToCheck][time].group[i] != NULL ; i++){
		for(j = 0 ; j < groupSize ; j++){
     if(newClass[venue][dayToCheck][time].group[i] != NULL && newClass[venue][dayToCheck][time].group[i] == &groupList[j]){
      groupCounter[j]++;
     }
    }
   }
  }
 }
 
 for( i = 0; i < groupSize ; i++){
  if(groupCounter[i] > 4)
   violation += groupCounter[i] - 4;
 }
 
return violation;
}

/****************************************************************************
 *	Function name	:	lecturerInMultipleVenue
 *	Inputs				: Class sourceClass[][][], dayToCheck, timeToCheck, totalVenue
 *	Output/return	: number of violation
 *	Destroy				:	NONE
 *	Description		:	The purpose of this function is to calculate the
 *                  violation of same lecturer appeared in same class during
 *                  particular day and hour.
 *****************************************************************************/
int lecturerInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue)
{

 int i, venue;
 int violation = 0;
 int lecturerSize = getLecturerSize();
 int lecturerCounter[lecturerSize];
 clearCounter(lecturerSize,lecturerCounter);

 if(timeToCheck >= MAX_TIME_SLOT || dayToCheck >= MAX_DAY)
  Throw(ERR_EXCEEDED_INDEX); 
 
 for(venue = 0 ; venue < totalVenue ; venue++){
	for(i = 0 ; i < lecturerSize ; i++){
   if(newClass[venue][dayToCheck][timeToCheck].lecturer != NULL \
      && newClass[venue][dayToCheck][timeToCheck].lecturer == &lecturerList[i])
    lecturerCounter[i]++;
  }
 }
 
 for( i = 0; i < lecturerSize ; i++){
  if(lecturerCounter[i] > 1)
   violation += lecturerCounter[i] - 1;
 }
  
return violation;
}

int groupInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue)
{
  int i,j,venue;
  int violation = 0;
  int groupSize = getGroupSize();
  int groupCounter[groupSize];
  clearCounter(groupSize,groupCounter);

  if(timeToCheck >= MAX_TIME_SLOT || dayToCheck >= MAX_DAY)
    Throw(ERR_EXCEEDED_INDEX);
 
  for(venue = 0 ; venue < totalVenue ; venue++){
    for(i = 0 ; i < groupSize ; i++){
      for(j = 0 ; j < groupSize ; j++){
        if(newClass[venue][dayToCheck][timeToCheck].group[i] != NULL \
          && newClass[venue][dayToCheck][timeToCheck].group[i] == &groupList[j])
          groupCounter[j]++;
      }
    }
  }
 
  for( i = 0; i < groupSize ; i++){
    if(groupCounter[i] > 1)
    violation += groupCounter[i] - 1;
  }
  
return violation;
}


void clearCounter(int size, int counter[size]){
  int i;
  for( i = 0; i < size; i++){
    counter[i] = 0;
  }
}