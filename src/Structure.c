#include <stdio.h>
#include "Structure.h"
#include "CException.h"
#include "ErrorCode.h"
#include "malloc.h"

#define FOR_TEST

/************************************************************************
 *  List of Venue
 ************************************************************************/
 Venue venueList[] = {{ .nameOfVenue = "D300",
                        .sizeOfVenue = 55,
                        .venueType = 'p'
                      },
                      { .nameOfVenue = "K102",
                        .sizeOfVenue = 80,
                        .venueType = 'l'
                      },
                      { .nameOfVenue = "Q301",
                        .sizeOfVenue = 50,
                        .venueType = 't'
                      }
                      };

/************************************************************************
 *  List of Lecturer
 ************************************************************************/
 Lecturer lecturerList[] = {{ .lecturerName = "LeeFhyanSeng",
                              .department = "Pelita"
                            },
                            { .lecturerName = "ChiewXingBuan",
                              .department = "FAMA"
                            },
                            { .lecturerName = "YapMenKun",
                              .department = "FCBK"
                            }};
                            
/************************************************************************
 *  List of Group
 ************************************************************************/
 Group groupList[] = {{ .groupName = "JJ1",
                        .groupSize = 25
                      },
                      { .groupName = "JJ2",
                        .groupSize = 7
                      },
                      { .groupName = "M1",
                        .groupSize = 30
                      },
                      { .groupName = "M2",
                        .groupSize = 10
                      },
                      { .groupName = "K1",
                        .groupSize = 10
                      },
                      { .groupName = "K2",
                        .groupSize = 10
                      }};
                      
/************************************************************************
 *  List of Programme
 ************************************************************************/

 Programme programmeList[] = {{ .programmeName = "RMB3",
                                .numOfGroup = 2
                              },
                              { .programmeName = "DMI1",
                                .numOfGroup = 2
                              },
                              { .programmeName = "DMK2",
                                .numOfGroup = 2
                              }};
                              

                      
/************************************************************************
 *  List of Course
 ************************************************************************/
 Course courseList[] = {{ .courseCode = "AAMP1234",
                          .courseName = "ENGLISH",
                          .courseIndex = 0,
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 1,
                          .hoursOfPractical = 0,
                          .numOfProgramme = 2,
                          .numOfCombinedGroups = 2
                        },
                        { .courseCode = "AAMP4321",
                          .courseName = "Mathematics",
                          .courseIndex = 1,
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 2,
                          .hoursOfPractical = 0,
                          .numOfProgramme = 2,
                          .numOfCombinedGroups = 2
                        },
                        { .courseCode = "MDFK9413",
                          .courseName = "ControlSystem",
                          .courseIndex = 2,
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 1,
                          .hoursOfPractical = 1,
                          .numOfProgramme = 2,
                          .numOfCombinedGroups = 2
                        }};
                        
/************************************************************************
 *  List of Class
 ************************************************************************/
 Class clazzList[] = {{ .course = &courseList[0],
                         .lecturer = &lecturerList[0],
                         .typeOfClass = 'l',
                         .groupIndexInClass = 0
                         // .numOfGroup = 4
                         // .group[0] = &groupList[0],
                         // .group[1] = &groupList[1],
                         // .group[2] = &groupList[2],
                         // .group[3] = &groupList[3],
                         // .group[4] = NULL
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[2],
                          // .group[3] = &groupList[3],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[2],
                          // .group[3] = &groupList[3],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[2],
                          // .group[3] = &groupList[3],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[2],
                          // .group[1] = &groupList[3],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[2],
                          // .group[1] = &groupList[3],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[2],
                          // .group[1] = &groupList[3],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[2],
                          // .group[1] = &groupList[3],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[2],
                          // .group[1] = &groupList[3],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[2],
                          // .group[1] = &groupList[3],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'p',
                          .groupIndexInClass = 0
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'p',
                          .groupIndexInClass = 1
                          // .numOfGroup = 4
                          // .group[0] = &groupList[0],
                          // .group[1] = &groupList[1],
                          // .group[2] = &groupList[4],
                          // .group[3] = &groupList[5],
                          // .group[4] = NULL
                        }};
                        
                        
/****************************************************************************
 * Functions
 *****************************************************************************/
 
/****************************************************************************
 *  Function name : getGroupSize
 *  Inputs        : NONE
 *  Output/return : array size of groupList[]
 *  Destroy       : NONE
 *  Description   : The purpose of this function return the array size of groupList
 *****************************************************************************/         
int getGroupSize(){
  return (sizeof(groupList)/sizeof(Group));
}

/****************************************************************************
 *  Function name : getLecturerSize
 *  Inputs        : NONE
 *  Output/return : array size of lecturerList[]
 *  Destroy       : NONE
 *  Description   : The purpose of this function return the array size of lecturerList
 *****************************************************************************/
int getLecturerSize(){
  return (sizeof(lecturerList)/sizeof(Lecturer));
}

/****************************************************************************
 *  Function name : getCourseSIze
 *  Inputs        : NONE
 *  Output/return : array size of courseList[]
 *  Destroy       : NONE
 *  Description   : The purpose of this function return the array size of courseList
 *****************************************************************************/
int getCourseSize(){
  return (sizeof(courseList)/sizeof(Course));
}

/****************************************************************************
 *  Function name : getClazzListSize
 *  Inputs        : NONE
 *  Output/return : array size of clazzList[]
 *  Destroy       : NONE
 *  Description   : The purpose of this function return the array size of clazzList
 *****************************************************************************/
int getClazzListSize(){
  return (sizeof(clazzList)/sizeof(Class));
}

/****************************************************************************
 *  Function name : clearClass
 *  Inputs        : Class sourceClass
 *  Output/return : NONE
 *  Destroy       : Class sourceClass
 *  Description   : The purpose of this function is to clear particular slot in class[][][]
 *****************************************************************************/
Class clearClass(Class sourceClass){
  int i;
  
  sourceClass.course = NULL;
  sourceClass.lecturer = NULL;
  sourceClass.typeOfClass = 0;
  sourceClass.groupIndexInClass = 0;
  sourceClass.groupInClass = NULL;
  
  return sourceClass;
}

/****************************************************************************
 *  Function name : clearTimeTable
 *  Inputs        : Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS]
 *  Output/return : NONE
 *  Destroy       : Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS]
 *  Description   : The purpose of this function is to clear a class[][][]
 *****************************************************************************/
void clearTimeTable(Class sourceClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOT]){
  int venue, day, time;
  
  for( venue = 0 ; venue < MAX_VENUE ; venue++ ){
    for( day = 0 ; day < MAX_DAY ; day++ ){
      for( time = 0 ; time < MAX_TIME_SLOT ; time++ ){
        sourceClass[venue][day][time] = clearClass(sourceClass[venue][day][time]);
      }
    }
  }
}

/****************************************************************************
 *  Function name : checkEqualClass
 *  Inputs        : Class sourceClass, Class classToCompare
 *  Output/return : 1 if equal, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to compare whether
 *                  two different classes have the same elements
 *****************************************************************************/
int checkEqualClass(Class newClass, Class newClass2){

  if(newClass.course == NULL && newClass2.course == NULL)
    return 1;
  
  if(newClass.course != newClass2.course)
    return 0;
  
  if(newClass.lecturer != newClass2.lecturer)
    return 0;
  
  if(newClass.typeOfClass != newClass2.typeOfClass)
    return 0;
  
  if(newClass.groupIndexInClass != newClass2.groupIndexInClass)
    return 0;
  
  if(newClass.groupInClass || newClass2.groupInClass){
    if(newClass.groupInClass != newClass2.groupInClass)
      return 0;
  }

    
  return 1;
}

/****************************************************************************
 *  Function name : indexForward
 *  Inputs        : ClassIndex *classIndex
 *  Output/return : NONE
 *  Destroy       : classIndex->venue, classIndex->day, classIndex->time
 *  Description   : The purpose of this function is to perform 
 *                  3-Dimensional array index incremental. index will
 *                  reset to 0,0,0 when overload
 *****************************************************************************/
void indexForward(ClassIndex *classIndex){

  if(classIndex->venue < 0 || classIndex->day < 0 || classIndex->time < 0)
    Throw(ERR_EXCEEDED_INDEX);
  if(classIndex->venue >= MAX_VENUE || classIndex->day >= MAX_DAY || classIndex->time >= MAX_TIME_SLOT)
    Throw(ERR_EXCEEDED_INDEX);

  (classIndex->time)++;
  
  if(classIndex->time >= MAX_TIME_SLOT){
    classIndex->time = 0;
    (classIndex->day)++;
  }
  if(classIndex->day >= MAX_DAY){
    classIndex->day = 0;
    (classIndex->venue)++;
  }
  if(classIndex->venue >= MAX_VENUE)
    classIndex->venue = 0;
}


/****************************************************************************
 *  Function name : indexBackward
 *  Inputs        : ClassIndex *classIndex
 *  Output/return : NONE
 *  Destroy       : classIndex->venue, classIndex->day, classIndex->time
 *  Description   : The purpose of this function is to perform 
 *                  3-Dimensional array index decremental. index will
 *                  reset to max value of each index when less than 0,0,0
 *****************************************************************************/
void indexBackward(ClassIndex *classIndex){
  
  if(classIndex->venue < 0 || classIndex->day < 0 || classIndex->time < 0)
    Throw(ERR_EXCEEDED_INDEX);
  if(classIndex->venue >= MAX_VENUE || classIndex->day >= MAX_DAY || classIndex->time >= MAX_TIME_SLOT)
    Throw(ERR_EXCEEDED_INDEX);
  
  (classIndex->time)--;
  
  if(classIndex->time < 0){
    classIndex->time = MAX_TIME_SLOT - 1;
    (classIndex->day)--;
  }
  if(classIndex->day < 0){
    classIndex->day = MAX_DAY - 1;
    (classIndex->venue)--;
  }
  if(classIndex->venue < 0)
    classIndex->venue = MAX_VENUE - 1;
}

/****************************************************************************
 *  Function name : classIsNull
 *  Inputs        : Class sourceClass
 *  Output/return : 1 if class is NULL, 0 otherwise
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to perform 
 *                  class checking to make sure it is NULL or contains data
 *****************************************************************************/
int classIsNull(Class sourceClass){
  
  if(sourceClass.course != NULL)
    return 0;
  if(sourceClass.lecturer != NULL)
    return 0;
  if(sourceClass.typeOfClass != 0)
    return 0;
  if(sourceClass.groupIndexInClass != 0)
    return 0;
  if(sourceClass.groupInClass != NULL)
    return 0;
  
  return 1;
}

/****************************************************************************
 *  Function name : classGetTotalStudent
 *  Inputs        : Class classToCheck
 *  Output/return : totalStudents
 *  Destroy       : NONE
 *  Description   : The purpose of this function is to perform 
 *                  class checking and return the total students in the class
 *****************************************************************************/
int classGetTotalStudent(Class classToCheck){
  int combinedGroupSize, totalCombinedGroups, i;
  int totalStudents = 0;
  Group **groups;
  
  if(classIsNull(classToCheck))
    return 0;
  
  if(classToCheck.groupInClass == NULL){
    totalStudents = classGetTotalStudentInLecture(classToCheck);
    return totalStudents;
  }
  else{
    groups = courseGetCombinedGroups(classToCheck.course,classToCheck.groupIndexInClass, &combinedGroupSize);
  
    for(i = 0 ; i < combinedGroupSize ; i++){
      totalStudents += groups[i]->groupSize;
    }
  }
  return totalStudents;
}

int classGetTotalStudentInLecture(Class classToCheck){
  int combinedGroups, combinedGroupSize, i, j;
  int totalStudents = 0;
  Group **groups;
  
  combinedGroups = courseGetNumberOfCombinedGroups(classToCheck.course);

  for(i = 0 ; i < combinedGroups ; i++){
    groups = courseGetCombinedGroups(classToCheck.course,i, &combinedGroupSize);
  
    for(j = 0 ; j < combinedGroupSize ; j++){
      totalStudents += groups[j]->groupSize;
    }
  }
  return totalStudents;
}

void initProgrammeList(){
  
  programmeList[0].group = malloc(programmeList[0].numOfGroup*sizeof(Group*));
  programmeList[0].group[0] = &groupList[0];
  programmeList[0].group[1] = &groupList[1];

  programmeList[1].group = malloc((sizeof(Group *))* (programmeList[1].numOfGroup));
  programmeList[1].group[0] = &groupList[2];
  programmeList[1].group[1] = &groupList[3];

  programmeList[2].group = malloc((sizeof(Group *))* (programmeList[2].numOfGroup));
  programmeList[2].group[0] = &groupList[4];
  programmeList[2].group[1] = &groupList[5];
}

void initCourseList(){
  courseList[0].programme = malloc(courseList[0].numOfProgramme*sizeof(Course*));
  courseList[0].programme[0] = &programmeList[0];
  courseList[0].programme[1] = &programmeList[1];
  courseList[0].combinedGroups = malloc(courseList[0].numOfCombinedGroups*sizeof(CombinedGroups));
  courseList[0].combinedGroups[0].size = 2;
  courseList[0].combinedGroups[1].size = 2;
  courseList[0].combinedGroups[0].groups = malloc(courseList[0].combinedGroups[0].size*sizeof(Group*));
  courseList[0].combinedGroups[1].groups = malloc(courseList[0].combinedGroups[1].size*sizeof(Group*));
  courseList[0].combinedGroups[0].groups[0] = &groupList[0];
  courseList[0].combinedGroups[0].groups[1] = &groupList[1];
  courseList[0].combinedGroups[1].groups[0] = &groupList[2];
  courseList[0].combinedGroups[1].groups[1] = &groupList[3];
  
  courseList[1].programme = malloc(courseList[1].numOfProgramme*sizeof(Course*));
  courseList[1].programme[0] = &programmeList[1];
  courseList[1].programme[1] = &programmeList[2];
  courseList[1].combinedGroups = malloc(courseList[1].numOfCombinedGroups*sizeof(CombinedGroups));
  courseList[1].combinedGroups[0].size = 2;
  courseList[1].combinedGroups[1].size = 2;
  courseList[1].combinedGroups[0].groups = malloc(courseList[1].combinedGroups[0].size*sizeof(Group*));
  courseList[1].combinedGroups[1].groups = malloc(courseList[1].combinedGroups[1].size*sizeof(Group*));
  courseList[1].combinedGroups[0].groups[0] = &groupList[2];
  courseList[1].combinedGroups[0].groups[1] = &groupList[3];
  courseList[1].combinedGroups[1].groups[0] = &groupList[4];
  courseList[1].combinedGroups[1].groups[1] = &groupList[5];
  
  courseList[2].programme = malloc(courseList[2].numOfProgramme*sizeof(Course*));
  courseList[2].programme[0] = &programmeList[0];
  courseList[2].programme[1] = &programmeList[2];
  courseList[2].combinedGroups = malloc(courseList[2].numOfCombinedGroups*sizeof(CombinedGroups));
  courseList[2].combinedGroups[0].size = 2;
  courseList[2].combinedGroups[1].size = 2;
  courseList[2].combinedGroups[0].groups = malloc(courseList[2].combinedGroups[0].size*sizeof(Group*));
  courseList[2].combinedGroups[1].groups = malloc(courseList[2].combinedGroups[1].size*sizeof(Group*));
  courseList[2].combinedGroups[0].groups[0] = &groupList[0];
  courseList[2].combinedGroups[0].groups[1] = &groupList[1];
  courseList[2].combinedGroups[1].groups[0] = &groupList[4];
  courseList[2].combinedGroups[1].groups[1] = &groupList[5];
}

void initClassList(){
  //English
  clazzList[0].groupInClass = NULL;
  clazzList[1].groupInClass = NULL;
  clazzList[2].groupInClass = &(clazzList[2].course->combinedGroups[clazzList[2].groupIndexInClass]);
  clazzList[3].groupInClass = &(clazzList[3].course->combinedGroups[clazzList[3].groupIndexInClass]);
  
  //Mathematics
  clazzList[4].groupInClass = NULL;
  clazzList[5].groupInClass = NULL;
  clazzList[6].groupInClass = &(clazzList[6].course->combinedGroups[clazzList[6].groupIndexInClass]);
  clazzList[7].groupInClass = &(clazzList[7].course->combinedGroups[clazzList[7].groupIndexInClass]);
  clazzList[8].groupInClass = &(clazzList[8].course->combinedGroups[clazzList[8].groupIndexInClass]);
  clazzList[9].groupInClass = &(clazzList[9].course->combinedGroups[clazzList[9].groupIndexInClass]);
  
  //Control System
  clazzList[10].groupInClass = NULL;
  clazzList[11].groupInClass = NULL;
  clazzList[12].groupInClass = &(clazzList[12].course->combinedGroups[clazzList[12].groupIndexInClass]);
  clazzList[13].groupInClass = &(clazzList[13].course->combinedGroups[clazzList[13].groupIndexInClass]);
  clazzList[14].groupInClass = &(clazzList[14].course->combinedGroups[clazzList[14].groupIndexInClass]);
  clazzList[15].groupInClass = &(clazzList[15].course->combinedGroups[clazzList[15].groupIndexInClass]);
  
}

int courseGetNumberOfCombinedGroups(Course *course){
  if(course != NULL)
    return course->numOfCombinedGroups;
  else
    return 0;
}

Group **courseGetCombinedGroups(Course *course, int index, int *number){
  
  if(course == NULL)
    Throw(ERR_EMPTY_COURSE);
  
  if(index >= course->numOfCombinedGroups)
    Throw(ERR_EXCEEDED_INDEX);
  
  (*number) = course->combinedGroups[index].size;
  
  return (course->combinedGroups[index].groups);
}

char *combinedGroupsGetName(CombinedGroups *combinedGroups, int index){
  if(index >= combinedGroups->size)
    Throw(ERR_EXCEEDED_INDEX);
  
  if(combinedGroups->groups[index])
    return combinedGroups->groups[index]->groupName;
}


Programme **courseGetProgrammes(Course *course, int *number){
  if(course != NULL){
    (*number) = course->numOfProgramme;
    return course->programme;
  }
}

char *programmeGetName(Programme *programme){
  if(programme != NULL)
    return programme->programmeName;
  
}