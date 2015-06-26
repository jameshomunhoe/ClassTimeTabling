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
int performCrossover(Class father[][MAX_DAY][MAX_TIME_SLOT], \
                     Class mother[][MAX_DAY][MAX_TIME_SLOT], \
                     Class offspring[][MAX_DAY][MAX_TIME_SLOT],\
                     int totalVenue);
void randomIndex(int *venue, int *day, int *time);
void getMidPoint(int *venueLeft, int *dayLeft, int *timeLeft,\
                 int *venueRight, int *dayRight, int *timeRight,\
                 int totalVenue);
void updateStopFlag(int *currentSide, int *oppositeSide);
int updateEmptyCounter(Class classToCheck, int emptyIndex, int totalEmptySlots);
int updateLectureCounter(Class classToCheck);
int updateTutorialCounter(Class classToCheck);
int updatePracticalCounter(Class classToCheck);
#endif // Crossover_H
