#ifndef TestStructure_H
#define TestStructure_H

#include "Structure.h"

//extern of List(s)
extern Venue venueList[];
extern Lecturer lecturerList[];
extern Group groupList[];
extern Programme programmeList[];
extern Course courseList[];
extern Class clazzList[];

//functions that returns List's size
extern int getGroupSize();
extern int getLecturerSize();
extern int getCourseSize();
extern int getClazzListSize();
#endif // TestStructure_H
