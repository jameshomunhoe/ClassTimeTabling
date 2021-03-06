#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Constraints.h"
#include "Structure.h"
#include "Random.h"
#include "TestStructure.h"
#include "CException.h"
#include "ErrorCode.h"

#define Lecture             'l'
#define Tutorial            't'
#define Practical           'p'


/****************************************************************************
 *  Function name : clearCounter
 *  Inputs        : int size, int counter[size]
 *  Output/return : NONE
 *  Destroy       : counter[]
 *  Description   : The purpose of this function is to initialize the counter
 *                  to have all 0 in each array to make sure the counter is clean
 *****************************************************************************/
void clearCounter(int size, int counter[size]){
  int i;
  for( i = 0; i < size; i++){
    counter[i] = 0;
  }
}

/****************************************************************************
 *  Function name : groupCounterUpdateNumOfAppearing
 *  Inputs        : int size, int counter[size]
 *  Output/return : NONE
 *  Destroy       : counter[]
 *  Description   : The purpose of this function is to initialize the counter
 *                  to have all 0 in each array to make sure the counter is clean
 *****************************************************************************/
void groupCounterUpdateNumOfAppearing(int size, int counter[size]){
  int i,j;
  
  for( i = 0; i < getCourseSize(); i++){
    for(j = 0 ; j < size ; j ++){
      counter[j] += classCount[i].groupCounter[j].lectureCounter;
      counter[j] += classCount[i].groupCounter[j].tutorialCounter;
      counter[j] += classCount[i].groupCounter[j].practicalCounter;
      // printf("group %d = %d",j,counter[j]);
    }
  }
}

/****************************************************************************
 *  Function name : generateViolationFromCounter
 *  Inputs        : int size, int counter[size], int limit
 *  Output/return : number of violations
 *  Destroy       : i, violation
 *  Description   : The purpose of this function is to tabulate the total
 *                  violation according to the input counter
 *****************************************************************************/
int generateViolationFromCounter(int size, int counter[size], int limit){
  int i,violation = 0;
  
  for( i = 0; i < size ; i++){
    if(counter[i] > limit)
    violation += counter[i] - limit;
 }
 return violation;
}

/****************************************************************************
 *  Function name : lecturerInMultipleVenue
 *  Inputs        : Class sourceClass[][][], dayToCheck, timeToCheck, totalVenue
 *  Output/return : number of violation
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  violation of same lecturer appeared in same class during
 *                  particular day and hour.
 *****************************************************************************/
int lecturerInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue)
{

 int venue, lecturerIndex;
 int violation = 0;
 int lecturerSize = getLecturerSize();
 int lecturerCounter[lecturerSize];
 clearCounter(lecturerSize,lecturerCounter);

 if(timeToCheck >= MAX_TIME_SLOT || dayToCheck >= MAX_DAY)
  Throw(ERR_EXCEEDED_INDEX); 
 
 for(venue = 0 ; venue < totalVenue ; venue++){
   if(classIsNull(&(newClass[venue][dayToCheck][timeToCheck])) == 0){
    lecturerIndex = getIndexInList(newClass[venue][dayToCheck][timeToCheck].lecturer, 'l');
    lecturerCounter[lecturerIndex]++;
   }
 }
  
  violation = generateViolationFromCounter(lecturerSize, lecturerCounter, 1);
 
  return violation;
}

/****************************************************************************
 *  Function name : groupInMultipleVenue
 *  Inputs        : Class sourceClass[][][], dayToCheck, timeToCheck, totalVenue
 *  Output/return : number of violation
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  violation of same group appeared in same class during
 *                  particular day and hour.
 *****************************************************************************/
int groupInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue)
{
  int i, j, venue;
  int violation = 0;
  int groupSize = getGroupSize();
  int groupCounter[groupSize];
  clearCounter(groupSize,groupCounter);
  initClassCounter();
  if(timeToCheck >= MAX_TIME_SLOT || dayToCheck >= MAX_DAY)
    Throw(ERR_EXCEEDED_INDEX);
 
  for(venue = 0 ; venue < totalVenue ; venue++){
    updateGroupCounterFromClassWithSignal(&(newClass[venue][dayToCheck][timeToCheck]));
  }
  
  groupCounterUpdateNumOfAppearing(groupSize, groupCounter);
  
  violation = generateViolationFromCounter(groupSize, groupCounter, 1);
return violation;
}

/****************************************************************************
 *  Function name : venueOverloaded
 *  Inputs        : Class classToCheck, int venueIndex(venueList)
 *  Output/return : 1 if there is violation, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to check whether
 *                  whether the amount of students in the class can
 *                  fit into the venue
 *****************************************************************************/
int venueOverloaded(Class *classToCheck, int venue){
  
  int numOfStudent = classGetTotalStudent(classToCheck);

  if(numOfStudent > venueList[venue].sizeOfVenue)
    return numOfStudent - venueList[venue].sizeOfVenue;
  else
    return 0;
    
}

/****************************************************************************
 *  Function name : wrongVenueType
 *  Inputs        : Class classToCheck, int venueIndex(venueList)
 *  Output/return : 1 if there is violation, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to check whether
 *                  whether the class suitable with the typeOfClass of
 *                  the class
 *****************************************************************************/
int wrongVenueType(Class *classToCheck, int venue){
  
  if(classIsNull(classToCheck))
    return 0;
  else if(classToCheck->typeOfClass == Practical && venueList[venue].venueType != Practical)
    return 1;
  else
    return 0;
}

/****************************************************************************
* Fitness functions
****************************************************************************/

/****************************************************************************
 *  Function name : studyHourOverloaded
 *  Inputs        : Class sourceClass[][][], dayToCheck, totalVenue
 *  Output/return : number of violation
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  violation of same group of student study more than 6 hours
 *                  a day(for test, 4 hours)
 *****************************************************************************/
int studyHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, \
                        int totalVenue)
{

  int time, venue;
  int violation = 0;
  int groupSize = getGroupSize();
  int groupCounter[groupSize];
  clearCounter(groupSize,groupCounter);
  initClassCounter();

  if(dayToCheck >= MAX_DAY)
    Throw(ERR_EXCEEDED_INDEX);
 
  for(venue = 0 ; venue < totalVenue ; venue++){
    for(time = 0 ; time < MAX_TIME_SLOT ; time++){
      updateGroupCounterFromClassWithSignal(&(newClass[venue][dayToCheck][time]));
    }
  }

  groupCounterUpdateNumOfAppearing(groupSize, groupCounter);
  violation = generateViolationFromCounter(groupSize, groupCounter, studyHourLimit);
  initClassCounter();
return violation;
}

/****************************************************************************
 *  Function name : teachingHourOverloaded
 *  Inputs        : Class sourceClass[][][], dayToCheck, totalVenue
 *  Output/return : number of violation
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  violation of same lecturer teach more than 6 hours
 *                  a day(for test, 4 hours)
 *****************************************************************************/
int teachingHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                           int dayToCheck, \
                           int totalVenue)
{

  int time, venue, lecturerIndex;
  int violation = 0;
  int lecturerSize = getLecturerSize();
  int lecturerCounter[lecturerSize];
  clearCounter(lecturerSize,lecturerCounter);

  if(dayToCheck >= MAX_DAY)
    Throw(ERR_EXCEEDED_INDEX);
 
  for(venue = 0 ; venue < totalVenue ; venue++){
    for(time = 0 ; time < MAX_TIME_SLOT ; time++){
      if(classIsNull(&(newClass[venue][dayToCheck][time]))==0){
        lecturerIndex = getIndexInList(newClass[venue][dayToCheck][time].lecturer, 'l');
        lecturerCounter[lecturerIndex]++;
      }
    }
  }

  violation = generateViolationFromCounter(lecturerSize, lecturerCounter, teachingHourLimit);
return violation;
}

/****************************************************************************
 *  Function name : possibleConstraintsInIndex
 *  Inputs        : Class sourceClass[][][], ClassIndex *index
 *  Output/return : possible violation caused by the class of this index
 *  Destroy       : violations
 *  Description   : The purpose of this function is to calculate the
 *                  possible violation caused by the class at this index
 *****************************************************************************/
int possibleConstraintsInIndex(Class timeTable[][MAX_DAY][MAX_TIME_SLOT], \
                               ClassIndex *classIndex)
{
  int violations = 0;
  
  if(classIsNull(&(timeTable[classIndex->venue][classIndex->day][classIndex->time])))
    return 0;
  
  violations += lecturerInMultipleVenue(timeTable, classIndex->day, classIndex->time, MAX_VENUE);
  violations += groupInMultipleVenue(timeTable, classIndex->day, classIndex->time, MAX_VENUE);
  violations += venueOverloaded(&(timeTable[classIndex->venue][classIndex->day][classIndex->time]), classIndex->venue);
  violations += wrongVenueType(&(timeTable[classIndex->venue][classIndex->day][classIndex->time]), classIndex->venue);

  return violations;
}

/****************************************************************************
 *  Function name : possibleFitnessLossInIndex
 *  Inputs        : Class sourceClass[][][], ClassIndex *index
 *  Output/return : possible violation caused by the class of this index
 *  Destroy       : violations
 *  Description   : The purpose of this function is to calculate the
 *                  possible fitness loss caused by the class at this index
 *****************************************************************************/
int possibleFitnessLossInIndex(Class timeTable[][MAX_DAY][MAX_TIME_SLOT], \
                               ClassIndex *classIndex)
{
  int violations = 0;
  
  if(classIsNull(&(timeTable[classIndex->venue][classIndex->day][classIndex->time])))
    return 0;
  
  violations += studyHourOverloaded(timeTable, classIndex->day, MAX_VENUE);
  violations += teachingHourOverloaded(timeTable, classIndex->day, MAX_VENUE);
                        
  return violations;
}

/****************************************************************************
 *  Function name : calculateTotalConstraintsInTimetable
 *  Inputs        : Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]
 *  Output/return : total constraints in the timeTable
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  total constraints in the timeTable
 *****************************************************************************/
int calculateTotalConstraintsInTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  
  int constraints = 0, i;
  ClassIndex index = {0,0,0};
  
  for( i = 0 ; i < (MAX_VENUE)*(MAX_DAY)*(MAX_TIME_SLOT) ; i++){
    constraints += venueOverloaded(&timeTable[index.venue][index.day][index.time], index.venue);
    constraints += wrongVenueType(&timeTable[index.venue][index.day][index.time], index.venue);
    
    if(index.venue == 0){
      constraints += lecturerInMultipleVenue(timeTable, index.day, index.time, MAX_VENUE);
      constraints += groupInMultipleVenue(timeTable, index.day, index.time, MAX_VENUE);
    }
    
    indexForward(&index);
  }
  return constraints;
}

/****************************************************************************
 *  Function name : calculateTotalFitnessInTimetable
 *  Inputs        : Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]
 *  Output/return : total fitness in the timeTable
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  total fitness in the timeTable
 *****************************************************************************/
int calculateTotalFitnessInTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  int constraints = 0, day;
  
  for( day = 0 ; day < MAX_DAY ; day++){
    constraints += studyHourOverloaded(timeTable, day, MAX_VENUE);
    constraints += teachingHourOverloaded(timeTable, day, MAX_VENUE);
  }
  return constraints;
}

/****************************************************************************
 *  Function name : calculateTotalFitnessInTimetable
 *  Inputs        : Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]
 *  Output/return : total violation in the timeTable(constraints + fitness)
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to calculate the
 *                  total violation in the timeTable
 *****************************************************************************/
int calculateTotalViolationInTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  int constraints = 0;
  
  constraints += calculateTotalConstraintsInTimetable(timeTable);
  constraints += calculateTotalFitnessInTimetable(timeTable);
  
  return constraints;
}