#ifndef Mutation_H
#define Mutation_H

#define FOR_TEST
#include "Structure.h"

void mutationSwapOnce(Class classToMutate[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]);
int shouldMutate(int constraintBefore, int constraintAfter,\
                        int totalBefore, int totalAfter);


#endif // Mutation_H
