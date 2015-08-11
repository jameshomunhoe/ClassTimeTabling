#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Mutation.h"
#include "Constraints.h"
#include "Structure.h"
#include "TestStructure.h"
#include "Random.h"


void mutationSwapOnce(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  
  ClassIndex source;
  ClassIndex goal;
  int constraintsBefore = 0, constraintsAfter = 0;
  int fitnessBefore = 0, fitnessAfter = 0;
  int totalWeaknessBefore = 0, totalWeaknessAfter = 0;
  
  
  randomIndex(&source);
  randomIndex(&goal);
  
  
  constraintsBefore += possibleConstraintsInIndex(classToMutate, &source);
  constraintsBefore += possibleConstraintsInIndex(classToMutate, &goal);
  fitnessBefore += possibleFitnessLossInIndex(classToMutate, &source);
  fitnessBefore += possibleFitnessLossInIndex(classToMutate, &goal);
  totalWeaknessBefore = constraintsBefore + fitnessBefore;
  
  printf("fitness score before : %d\n", totalWeaknessBefore);
  
  swapTwoClassesInTimetable(classToMutate, &source, &goal);
  
  
  constraintsAfter += possibleConstraintsInIndex(classToMutate, &source);
  constraintsAfter += possibleConstraintsInIndex(classToMutate, &goal);
  fitnessAfter += possibleFitnessLossInIndex(classToMutate, &source);
  fitnessAfter += possibleFitnessLossInIndex(classToMutate, &goal);
  totalWeaknessAfter = constraintsAfter + fitnessAfter;
  printf("fitness score after : %d\n", totalWeaknessAfter);
  
  if(!shouldMutate(constraintsBefore, constraintsAfter, totalWeaknessBefore, totalWeaknessAfter))
    swapTwoClassesInTimetable(classToMutate, &source, &goal);
  
}

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

