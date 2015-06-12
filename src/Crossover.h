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
};

extern ClassCounter classCount[12];
int updateCounter(Class classToCheck);

#endif // Crossover_H
