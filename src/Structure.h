#ifndef Structure_H
#define Structure_H

#define FOR_TEST

#ifdef FOR_TEST
  #define MAX_VENUE         2
  #define MAX_DAY           3
  #define MAX_TIME_SLOT     6
  #define studyHourLimit    4
  #define teachingHourLimit 4

#else
  #define MAX_VENUE     5
  #define MAX_DAY       5
  #define MAX_TIME_SLOT 9
  #define studyHourLimit    6
  #define teachingHourLimit 6
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
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
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
typedef struct ClassIndex ClassIndex;
typedef struct CombinedGroups CombinedGroups;
typedef struct ClassCounter ClassCounter;
typedef struct ClassGroupCounter ClassGroupCounter;

/************************************************************************
 *	Struct of Venue
 ************************************************************************/
struct Venue
{
  char *nameOfVenue;
  int sizeOfVenue;
  char venueType;
  int numOfSpecificCourse;
  Course  **course;
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
  int numOfGroup;
  Group **group;
  // Group *group[5];
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
  int numOfProgramme;
  Programme **programme;
  int numOfCombinedGroups;
  CombinedGroups *combinedGroups;
  // Programme *programme[5];

};

/************************************************************************
 *	Struct of Class
 ************************************************************************/
struct Class 
{
  Course *course;
  Lecturer *lecturer;
  char typeOfClass;
  int groupIndexInClass;
  CombinedGroups *groupInClass;
  
};

/************************************************************************
 *	Struct of index
 ************************************************************************/
struct ClassIndex 
{
  int venue;
  int day;
  int time;
};

/************************************************************************
 *	Struct of index
 ************************************************************************/
struct CombinedGroups 
{
  int size;
  Group **groups;
};

/************************************************************************
 *	Struct of ClassCounter
 ************************************************************************/
struct ClassCounter
{
  ClassGroupCounter *groupCounter;
  int forEmptyClasses;
};

/************************************************************************
 *	Struct of ClassGroupCounter
 ************************************************************************/
struct ClassGroupCounter
{
  int lectureCounter;
  int tutorialCounter;
  int practicalCounter;
};

//extern of classCount
extern ClassCounter *classCount;

//functions of class
extern void clearClass(Class *sourceClass);
extern void clearTimeTable(Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]);
extern int checkEqualClass(Class *newClass, Class *newClass2);
extern int classIsNull(Class *sourceClass);
extern int classGetTotalStudent(Class *classToCheck);
extern int classGetTotalStudentInLecture(Class *classToCheck); //sub-function
extern void swapTwoClassesInTimetable(Class timeTable[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT],\
                              ClassIndex *source, ClassIndex *goal);

//functions of course & programme
extern int courseGetNumberOfCombinedGroups(Course *course);
extern Group **courseGetCombinedGroups(Course *course, int index, int *number);
extern char *combinedGroupsGetName(CombinedGroups *combinedGroups, int index);
extern Programme **courseGetProgrammes(Course *course, int *number);
extern char *programmeGetName(Programme *programme);

//function to get index from list
extern int getIndexInList(void *data, char type);
extern void randomIndex(ClassIndex *classIndex);

//function to perform 3D array index increment/decrement
extern void indexForward(ClassIndex *classIndex);
extern void indexBackward(ClassIndex *classIndex);

//Histogram of groups in the classes
extern void initClassCounter();
extern int updateGroupCounterFromClassWithSignal(Class *classToCheck);
extern int updateEmptyCounterFromClassWithSignal(int emptyIndex, int totalEmptySlots); //sub-function
extern int updateGroupLectureCounterFromClassWithSignal(Class *classToCheck); //sub-function
extern int updateGroupTutorialCounterFromClassWithSignal(Class *classToCheck); //sub-function
extern int updateGroupPracticalCounterFromClassWithSignal(Class *classToCheck); //sub-function


#endif // Structure_H
