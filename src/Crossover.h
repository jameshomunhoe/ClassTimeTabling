#ifndef Crossover_H
#define Crossover_H

#define FOR_TEST
#include "Structure.h"

void performCrossover(Class father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue);
// extern void randomIndex(ClassIndex *classIndex);
void getMidPoint(ClassIndex *classIndexLeft,\
                 ClassIndex *classIndexRight,\
                 int totalVenue);
void updateStopFlag(int *currentSide, int *oppositeSide);

#endif // Crossover_H
