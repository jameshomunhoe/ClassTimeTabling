#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Crossover.h"
#include "Structure.h"
#include "TestStructure.h"
#include "Timetable.h"
#include "CException.h"
#include "ErrorCode.h"
#include "Random.h"
#include "malloc.h"


int fillClassIntoTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], \
                           ClassIndex *classIndex, Class *classToFill){
  
  if(classIndex->venue >= MAX_VENUE || classIndex->venue < 0)
    Throw(ERR_EXCEEDED_VENUE_INDEX);
  else if(classIndex->day >= MAX_DAY || classIndex->day < 0)
    Throw(ERR_EXCEEDED_DAY_INDEX);
  else if(classIndex->time >= MAX_TIME_SLOT || classIndex->time < 0)
    Throw(ERR_EXCEEDED_TIME_INDEX);
  
  if(classIsNull(&(timeTable[classIndex->venue][classIndex->day][classIndex->time]))){
    timeTable[classIndex->venue][classIndex->day][classIndex->time] = *classToFill;
    return 1;
  }
  else
    return 0;
}


void createTimeTable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  ClassIndex ttIndex = {0,0,0};
  clearTimeTable(timeTable);
  int clazzListSize = getClazzListSize();
  int i = 0;
  
  while(i < clazzListSize){
    
    randomIndex(&ttIndex);
    
    if(fillClassIntoTimetable(timeTable, &ttIndex, &clazzList[i]) == 1)
      i++;
  }
}