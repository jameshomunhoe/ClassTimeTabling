#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Crossover.h"
#include "Structure.h"

ClassCounter classCount[12] = {0};

/**
* Required functions for aiding crossover
* - Compare class (doing)
* - Compare obtained with classList
* - Swapping elements between two different chromosome
*
**/

//return 0 if no clashes
//return 1 if clashes
int updateCounter(Class classToCheck){
  int i;
  int size = getCourseSize();
  
  for( i = 0 ; i < size ; i++){
    if( classToCheck.course == &courseList[i])
      classCount[i]++;
      printf("Hi %d\n",i);
  }
  
  return 1;
}