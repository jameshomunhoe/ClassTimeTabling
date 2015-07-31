#ifndef Timetable_H
#define Timetable_H

#define FOR_TEST
#include "Structure.h"


void fillClassIntoTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT], \
                            ClassIndex *classIndex);

#endif // Timetable_H
