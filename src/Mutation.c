#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Mutation.h"
#include "Constraints.h"
#include "Structure.h"
#include "TestStructure.h"
#include "Random.h"


void performMutation(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  
  ClassIndex source;
  ClassIndex goal;
  int constraintsBefore = 0, constraintsAfter = 0;
  int fitnessBefore = 0, fitnessAfter = 0;
  int totalWeaknessBefore = 0, totalWeaknessAfter = 0;
  
  
  randomIndex(&source);
  randomIndex(&goal);
  
  printf("%s\n",classToMutate[0][0][0].course->courseName);
  constraintsBefore = possibleConstraintsInIndex(classToMutate, &source);
  fitnessBefore = possibleFitnessLossInIndex(classToMutate, &source);
  totalWeaknessBefore = constraintsBefore + fitnessBefore;
  constraintsBefore = possibleConstraintsInIndex(classToMutate, &goal);
  fitnessBefore = possibleFitnessLossInIndex(classToMutate, &goal);
  totalWeaknessBefore += constraintsBefore + fitnessBefore;
  printf("fitness score before : %d\n", totalWeaknessBefore);
  
  swapTwoClassesInTimetable(classToMutate, &source, &goal);
  
  
  constraintsAfter = possibleConstraintsInIndex(classToMutate, &source);
  fitnessAfter = possibleFitnessLossInIndex(classToMutate, &source);
  totalWeaknessAfter = constraintsBefore + fitnessBefore;
  constraintsAfter = possibleConstraintsInIndex(classToMutate, &goal);
  fitnessAfter = possibleFitnessLossInIndex(classToMutate, &goal);
  totalWeaknessAfter += constraintsBefore + fitnessBefore;
  printf("fitness score after : %d\n", totalWeaknessAfter);
  
  
}

