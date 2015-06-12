#include "unity.h"
#include <stdio.h>
#include "Crossover.h"
#include "Structure.h"

void setUp(void){}
void tearDown(void){}

void test_updateCounter_should_return_0_with_empty_class(){
  
  Class newClass;
  
  newClass = clazzList[0];
  
  updateCounter(newClass);
  
  TEST_ASSERT_EQUAL(1, classCount[0].lectureCounter);
}

