#ifndef Timetable_H
#define Timetable_H

#define FOR_TEST
#include "Structure.h"


int fillClassIntoTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], \
                           ClassIndex *classIndex, Class *classToFill);

#endif // Timetable_H
