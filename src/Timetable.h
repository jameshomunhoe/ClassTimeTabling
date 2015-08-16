#ifndef Timetable_H
#define Timetable_H

#define FOR_TEST
#include "Structure.h"
#include "Node.h"

extern Node *root;

int fillClassIntoTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], \
                           ClassIndex *classIndex, Class *classToFill);
                           
void createTimeTable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]);

int successfulAddWithoutConstraint(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], \
                                   ClassIndex *ttIndex, int numOfClass, int tolerance);
                                   
TTPopulation *createSinglePopulation(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]);

void insertPopulationIntoRBT(TTPopulation *onePopulation);
void createPopulationsOfTimeTable(int numOfPopulations);
#endif // Timetable_H
