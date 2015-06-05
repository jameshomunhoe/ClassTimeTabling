#ifndef Constraints_H
#define Constraints_H

#define FOR_TEST
#include "Structure.h"

//function prototype
int studyHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, \
                        int totalVenue);
                        
int lecturerInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int timeToCheck, int dayToCheck, \
                        int totalVenue);
#endif // Constraints_H
