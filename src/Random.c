#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Structure.h"
#include "Random.h"

/****************************************************************************
 *  Function name : randomVenue
 *  Inputs        : NONE
 *  Output/return : random number that less than MAX_VENUE
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to randomize a number for
 *                  genetic algorithm, this function randomize venue index
 *****************************************************************************/
int randomVenue(){
  int randomVenue = rand() % MAX_VENUE;
  return randomVenue;
}

/****************************************************************************
 *  Function name : randomDay
 *  Inputs        : NONE
 *  Output/return : random number that less than MAX_DAY
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to randomize a number for
 *                  genetic algorithm, this function randomize day index
 *****************************************************************************/
int randomDay(){
  int randomDay = rand() % MAX_DAY;
  return randomDay;
}

/****************************************************************************
 *  Function name : randomTime
 *  Inputs        : NONE
 *  Output/return : random number that less than MAX_TIME_SLOT
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to randomize a number for
 *                  genetic algorithm, this function randomize time index
 *****************************************************************************/
int randomTime(){
  int randomTime = rand() % MAX_TIME_SLOT;
  return randomTime;
}