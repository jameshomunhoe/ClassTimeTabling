#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Constraints.h"
#include "Structure.h"

//  Formula to get totalVenue
//  (sizeof(exampleClass)/sizeof(Class))/(sizeof(exampleClass[0])/sizeof(Class)));



int studyHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int day, \
                        int totalVenue){

 int i, j, time, venue;
 int violation = 0;
 int groupSize = getGroupSize();
 int groupCounter[groupSize];
 
 for( i = 0; i < groupSize; i++){
  groupCounter[i] = 0;
 }

 for(venue = 0 ; venue < totalVenue ; venue++){
  for(time = 0 ; time < MAX_TIME_SLOT ; time++){
   for(i = 0 ; newClass[venue][day][time].group[i] != NULL ; i++){
		for(j = 0 ; j < groupSize ; j++){
     if(newClass[venue][day][time].group[i] != NULL && newClass[venue][day][time].group[i] == &groupList[j]){
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
