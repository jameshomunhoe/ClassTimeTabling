#ifndef Crossover_H
#define Crossover_H

#define FOR_TEST
#include "Structure.h"

typedef struct ClassCounter ClassCounter;

struct ClassCounter
{
  int lectureCounter;
  int tutorialCounter;
  int practicalCounter;
  int forEmptyClasses;
};

extern ClassCounter classCount[4];
int updateCounter(Class classToCheck);
int performCrossover(Class Father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class Mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class Offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue);

#endif // Crossover_H
