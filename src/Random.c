#define FOR_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Structure.h"
#include "Random.h"
#include "Time.h"



int randomVenue(){
  int randomVenue = rand() % MAX_VENUE;
  return randomVenue;
}

int randomDay(){
  int randomDay = rand() % MAX_DAY;
  return randomDay;
}

int randomTime(){
  int randomTime = rand() % MAX_TIME_SLOT;
  return randomTime;
}