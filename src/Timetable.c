#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Structure.h"
#include "Timetable.h"
#include "CException.h"
#include "ErrorCode.h"
#include "Random.h"
#include "malloc.h"


int fillClassIntoTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], ClassIndex *classIndex){
  
  if(classIndex->venue >= MAX_VENUE || classIndex->venue < 0)
    Throw(ERR_EXCEEDED_VENUE_INDEX);
  else if(classIndex->day >= MAX_DAY || classIndex->day < 0)
    Throw(ERR_EXCEEDED_DAY_INDEX);
  else if(classIndex->time >= MAX_TIME_SLOT || classIndex->time < 0)
    Throw(ERR_EXCEEDED_TIME_INDEX);
  
  
  
}