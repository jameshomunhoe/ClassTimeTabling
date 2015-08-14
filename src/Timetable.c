#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Constraints.h"
#include "Crossover.h"
#include "Structure.h"
#include "TestStructure.h"
#include "Timetable.h"
#include "CException.h"
#include "ErrorCode.h"
#include "Random.h"
#include "malloc.h"

/****************************************************************************
 *  Function name : fillClassIntoTimetable
 *  Inputs        : Class timeTable[][][], ClassIndex *index, Class *classToFill
 *  Output/return : return 1 if filled successfully 
 *  Destroy       : timeTable[][][]
 *  Description   : The purpose of this function is to fill in a class into
 *                  the timeTable.
 *****************************************************************************/
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

/****************************************************************************
 *  Function name : successfulAddWithoutConstraint
 *  Inputs        : Class timeTable[][][], ClassIndex *index, 
 *                  Class *classToFill, int tolerance
 *  Output/return : return 1 if filled successfully without high constraints
 *  Destroy       : timeTable[][][]
 *  Description   : The purpose of this function is to fill in a class into
 *                  the timeTable without constraints. In worst case, the 
 *                  function will allow low constraint violation
 *****************************************************************************/
int successfulAddWithoutConstraint(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], \
                                   ClassIndex *ttIndex, int numOfClass, int tolerance)
{
  if(fillClassIntoTimetable(timeTable, ttIndex, &clazzList[numOfClass]) == 1){
    if(possibleConstraintsInIndex(timeTable, ttIndex) <= tolerance)
      return 1;
    else{
      clearClass(&timeTable[ttIndex->venue][ttIndex->day][ttIndex->time]);
      return 0;
    }   
  }
    
  else
    return 0;
  
}

/****************************************************************************
 *  Function name : createTimeTable
 *  Inputs        : Class timeTable[][][]
 *  Output/return : Fill in the classList into timeTable
 *  Destroy       : timeTable[][][]
 *  Description   : The purpose of this function is to fill all the class
 *                  From the list into the timeTable with violation control
 *****************************************************************************/
void createTimeTable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  ClassIndex ttIndex = {0,0,0};
  clearTimeTable(timeTable);
  int clazzListSize = getClazzListSize();
  int i = 0, tolerance = 0, loopEffort = 0;
  
  while(i < clazzListSize){
    randomIndex(&ttIndex);
    
    if(successfulAddWithoutConstraint(timeTable, &ttIndex, i, tolerance))
      i++;
    
    if(loopEffort++ > MAX_VENUE*MAX_DAY*MAX_TIME_SLOT){
      tolerance++;
      loopEffort = 0;
    }
  }
  initClassCounter();
}
  

  