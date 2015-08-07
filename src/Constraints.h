#ifndef Constraints_H
#define Constraints_H

#define FOR_TEST
#include "Structure.h"

//function prototype
void clearCounter(int size, int counter[size]);
void groupCounterUpdateNumOfAppearing(int size, int counter[size]);
int generateViolationFromCounter(int size, int counter[size], int limit);

//constraints                        
int lecturerInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue);

int groupInMultipleVenue(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, int timeToCheck, \
                        int totalVenue);

int venueOverloaded(Class *classToCheck, int venue);
int wrongVenueType(Class *classToCheck, int venue);

//fitness
int studyHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, \
                        int totalVenue);

int teachingHourOverloaded(Class newClass[][MAX_DAY][MAX_TIME_SLOT], \
                        int dayToCheck, \
                        int totalVenue);
                        
                        

//possible violation caused by one class                        
int possibleConstraintsInIndex(Class timeTable[][MAX_DAY][MAX_TIME_SLOT], \
                               ClassIndex *classIndex);
                               
int possibleFitnessLossInIndex(Class timeTable[][MAX_DAY][MAX_TIME_SLOT], \
                               ClassIndex *classIndex);
#endif // Constraints_H
