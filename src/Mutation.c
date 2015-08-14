#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Mutation.h"
#include "Constraints.h"
#include "Structure.h"
#include "TestStructure.h"
#include "Timetable.h"
#include "Random.h"


/****************************************************************************
 *  Function name : performMutation
 *  Inputs        : Class timeTable[][][], int effort
 *  Output/return : NONE
 *  Destroy       : timeTable[][][]
 *  Description   : The purpose of this function is to swap to random classes
 *                  to reduce the constraints, the number of performing will
 *                  decided by the user
 *****************************************************************************/
void performMutation(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], int effort){
  int i;
  
  for(i = 0 ; i < effort ; i++){
    mutationSwapOnce(classToMutate);
  }
  
}

/****************************************************************************
 *  Function name : mutationSwapOnce
 *  Inputs        : Class timeTable[][][]
 *  Output/return : NONE
 *  Destroy       : timeTable[][][]
 *  Description   : The purpose of this function is to swap to random classes
 *                  to reduce the constraints 
 *****************************************************************************/
void mutationSwapOnce(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  
  ClassIndex source;
  ClassIndex goal;
  int constraintsBefore = 0, constraintsAfter = 0;
  int fitnessBefore = 0, fitnessAfter = 0;
  int totalViolationBefore = 0, totalViolationAfter = 0;
  
  randomIndex(&source);
  randomIndex(&goal);
  
  totalViolationBefore = getTotalViolationsFromTwoClass(classToMutate, &source, &goal, \
                                                       &constraintsBefore, &fitnessBefore);
  
  swapTwoClassesInTimetable(classToMutate, &source, &goal);
  
  totalViolationAfter = getTotalViolationsFromTwoClass(classToMutate, &source, &goal, \
                                                       &constraintsAfter, &fitnessAfter);
  
  if(!shouldMutate(constraintsBefore, constraintsAfter, totalViolationBefore, totalViolationAfter))
    swapTwoClassesInTimetable(classToMutate, &source, &goal);
}


/****************************************************************************
 *  Function name : getTotalViolationsFromTwoClass
 *  Inputs        : Class timeTable[][][], \
 *                  ClassIndex *source, ClassIndex *goal, \
 *                  int *constraints, int *fitness
 *  Output/return : totalViolation (add both fitness and violation from both)
 *  Destroy       : *constraints, *fitness
 *  Description   : The purpose of this function is to get the possible total
 *                  violation caused by two classes
 *****************************************************************************/
int getTotalViolationsFromTwoClass(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT],\
                                   ClassIndex *source, ClassIndex *goal, \
                                   int *constraints, int *fitness)
{
  int totalViolation;
  
  *constraints += possibleConstraintsInIndex(classToMutate, source);
  *constraints += possibleConstraintsInIndex(classToMutate, goal);
  *fitness += possibleFitnessLossInIndex(classToMutate, source);
  *fitness += possibleFitnessLossInIndex(classToMutate, goal);
  totalViolation = *constraints + *fitness;
  
  return totalViolation;
}

/****************************************************************************
 *  Function name : shouldMutate
 *  Inputs        : int constraintBefore, int constraintAfter,\
 *                  int totalBefore, int totalAfter
 *  Output/return : 1 if should swap, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to decide whether to swap
 *                  after evaluating the constraints and totalViolation
 *****************************************************************************/
int shouldMutate(int constraintBefore, int constraintAfter,\
                 int totalBefore, int totalAfter)
{
  if(constraintAfter < constraintBefore)
    return 1;
  
  else if(constraintAfter == constraintBefore && totalAfter <= totalBefore)
    return 1;
  
  else
    return 0;
}

