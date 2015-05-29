#define FOR_TEST
//in FOR_TEST, the MAX_DAY and MAX_TIME will become 3,6

#include "unity.h"
#include "Constraints.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_structure(void)
{
  Class exampleClass[2][3][6];
	studyHourOverloaded(exampleClass, 5);
}
