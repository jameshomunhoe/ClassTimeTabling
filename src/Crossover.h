#ifndef Crossover_H
#define Crossover_H

#define FOR_TEST
#include "Structure.h"

typedef struct ClassCounter ClassCounter;
typedef struct ClassGroupCounter ClassGroupCounter;



struct ClassCounter
{
  ClassGroupCounter *groupCounter;
  int forEmptyClasses;
};

struct ClassGroupCounter
{
  int lectureCounter;
  int tutorialCounter;
  int practicalCounter;
};

extern ClassCounter *classCount;

int updateCounter(Class *classToCheck);
void performCrossover(Class father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue);
void randomIndex(ClassIndex *classIndex);
void getMidPoint(ClassIndex *classIndexLeft,\
                 ClassIndex *classIndexRight,\
                 int totalVenue);
void updateStopFlag(int *currentSide, int *oppositeSide);
int updateEmptyCounter(int emptyIndex, int totalEmptySlots);
int updateLectureCounter(Class *classToCheck);
int updateTutorialCounter(Class *classToCheck);
int updatePracticalCounter(Class *classToCheck);
#endif // Crossover_H
