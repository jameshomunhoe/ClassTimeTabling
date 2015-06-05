#ifndef Structure_H
#define Structure_H

#ifdef FOR_TEST
  #define MAX_DAY       3
  #define MAX_TIME_SLOT 6
  #define MAX_VENUE     2

#else
  #define MAX_DAY       6
  #define MAX_TIME_SLOT 8
  #define MAX_VENUE     5
#endif //TEST


/************************************************************************
 *  The 3 dimensions of the TimeTable will be venue, day, and time
 *
 *  Example: class[venue][time][day]
 *  
 *  (venue 1)
 *  Day/Time Time Time Time Time Time
 *  Day
 *  Day
 *  Day
 *  Day
 *
 *  (venue 2)
 *  Day/Time Time Time Time Time Time
 *  Day
 *  Day
 *  Day
 *  Day
 *
 ************************************************************************/



/************************************************************************
 *	The enum used to indicates the DAY in the timetable
 ************************************************************************/
typedef enum
{
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} Days;


/************************************************************************
 *	The enum used to indicates the TIME in the timetable
 ************************************************************************/
typedef enum
{
  _8_to_9am,
  _9_to_10am,
  _10_to_11am,
  _11_to_12pm,
  _12_to_1pm,
  _1_to_2pm,
  _2_to_3pm,
  _3_to_4pm,
  _4_to_5pm
} Time;

/************************************************************************
 *	type define for each structure of the elements of timetable
 ************************************************************************/
typedef struct Course Course;
typedef struct Lecturer Lecturer;
typedef struct Group Group;
typedef struct Programme Programme;
typedef struct Venue Venue;
typedef struct Class Class;

/************************************************************************
 *	Struct of Venue
 ************************************************************************/
struct Venue
{
  char *nameOfVenue;
  int sizeOfVenue;
  char venueType;
};

/************************************************************************
 *	Struct of Lecturer
 ************************************************************************/
struct Lecturer
{
  char *lecturerName;
  char *department;
};

/************************************************************************
 *	Struct of Group
 ************************************************************************/
struct Group
{
  char *groupName;
  int groupSize;
};

/************************************************************************
 *	Struct of Programme
 ************************************************************************/
struct Programme
{
  char *programmeName;
  Group *group[5];
};

/************************************************************************
 *	Struct of Course
 ************************************************************************/
struct Course
{
  char *courseCode;
  char *courseName;
  int hoursOfLecture;
  int hoursOfTutorial;
  int hoursOfPractical;
  Programme *programme[5];

};

/************************************************************************
 *	Struct of Class
 ************************************************************************/
struct Class 
{
  Course *course;
  Lecturer *lecturer;
  char typeOfClass;
  Group *group[5];
};

extern Venue venueList[];
extern Lecturer lecturerList[];
extern Group groupList[];
extern Programme programmeList[];
extern Course courseList[];
extern Class clazzList[];
extern int getGroupSize();
extern int getLecturerSize();

#endif // Structure_H
