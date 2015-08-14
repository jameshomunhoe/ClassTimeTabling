#ifndef Mutation_H
#define Mutation_H

#define FOR_TEST
#include "Structure.h"


void performMutation(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], int effort);
void mutationSwapOnce(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]);
int shouldMutate(int constraintBefore, int constraintAfter,\
                        int totalBefore, int totalAfter);

int getTotalViolationsFromTwoClass(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT],\
                                   ClassIndex *source, ClassIndex *goal, \
                                   int *constraints, int *fitness);
#endif // Mutation_H
