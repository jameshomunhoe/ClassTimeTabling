#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Constraints.h"
#include "Structure.h"

//  Formula to get totalVenue
//  (sizeof(exampleClass)/sizeof(Class))/(sizeof(exampleClass[0])/sizeof(Class)));



int studyHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, \
                        int totalVenue)
{

 int i, j, time, venue;
 int violation = 0;
 int groupSize = getGroupSize();
 int groupCounter[groupSize];
 
 if(dayToCheck >= MAX_DAY)
  return -1;
 
 for( i = 0; i < groupSize; i++){
  groupCounter[i] = 0;
 }

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

int lecturerInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue)
{

 int i, venue;
 int violation = 0;
 int lecturerSize = getLecturerSize();
 int lecturerCounter[lecturerSize];

 if(timeToCheck >= MAX_TIME_SLOT || dayToCheck >= MAX_DAY)
  return -1;
  
 for( i = 0; i < lecturerSize; i++){
  lecturerCounter[i] = 0;
 }
 
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
