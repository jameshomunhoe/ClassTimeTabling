#include <stdio.h>
#include "Structure.h"
#include "CException.h"
#include "ErrorCode.h"

#define FOR_TEST

/************************************************************************
 *  List of Venue
 ************************************************************************/
 Venue venueList[] = {{ .nameOfVenue = "D300",
                        .sizeOfVenue = 25,
                        .venueType = 'p'
                      },
                      { .nameOfVenue = "K102",
                        .sizeOfVenue = 30,
                        .venueType = 't'
                      }};

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
                                .group[0] = &groupList[0],
                                .group[1] = &groupList[1],
                                .group[2] = NULL
                              },
                              { .programmeName = "DMI1",
                                .group[0] = &groupList[2],
                                .group[1] = &groupList[3],
                                .group[2] = NULL
                              },
                              { .programmeName = "DMK2",
                                .group[0] = &groupList[4],
                                .group[1] = &groupList[5],
                                .group[2] = NULL
                              }};
                      
/************************************************************************
 *  List of Course
 ************************************************************************/
 Course courseList[] = {{ .courseCode = "AAMP1234",
                          .courseName = "ENGLISH",
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 1,
                          .hoursOfPractical = 0,
                          .programme[0] = &programmeList[0],
                          .programme[1] = &programmeList[1],
                          .programme[1] = NULL
                        },
                        { .courseCode = "AAMP4321",
                          .courseName = "Mathematics",
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 2,
                          .hoursOfPractical = 0,
                          .programme[0] = &programmeList[1],
                          .programme[1] = &programmeList[2],
                          .programme[2] = NULL
                        },
                        { .courseCode = "MDFK9413",
                          .courseName = "ControlSystem",
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 1,
                          .hoursOfPractical = 1,
                          .programme[0] = &programmeList[0],
                          .programme[1] = &programmeList[2],
                          .programme[2] = NULL
                        }};
                        
/************************************************************************
 *  List of Class
 ************************************************************************/
 Class clazzList[] = {{ .course = &courseList[0],
                         .lecturer = &lecturerList[0],
                         .typeOfClass = 'l',
                         .group[0] = &groupList[0],
                         .group[1] = &groupList[1],
                         .group[2] = &groupList[2],
                         .group[3] = &groupList[3],
                         .group[4] = NULL
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 'l',
                          .group[0] = &groupList[0],
                          .group[1] = &groupList[1],
                          .group[2] = &groupList[2],
                          .group[3] = &groupList[3],
                          .group[4] = NULL
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .group[0] = &groupList[0],
                          .group[1] = &groupList[1],
                          .group[2] = &groupList[2],
                          .group[3] = &groupList[3],
                          .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 'l',
                          .group[0] = &groupList[2],
                          .group[1] = &groupList[3],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 'l',
                          .group[0] = &groupList[2],
                          .group[1] = &groupList[3],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .group[0] = &groupList[2],
                          .group[1] = &groupList[3],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .group[0] = &groupList[2],
                          .group[1] = &groupList[3],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'l',
                          .group[0] = &groupList[0],
                          .group[1] = &groupList[1],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'l',
                          .group[0] = &groupList[0],
                          .group[1] = &groupList[1],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 't',
                          .group[0] = &groupList[0],
                          .group[1] = &groupList[1],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'p',
                          .group[0] = &groupList[0],
                          .group[1] = &groupList[1],
                          .group[2] = &groupList[4],
                          .group[3] = &groupList[5],
                          .group[4] = NULL
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
  for(i = 0 ; i < 5 ; i++){
    sourceClass.group[i] = NULL;
  }
  
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
  int i;
  if(newClass.course == NULL && newClass2.course == NULL)
    return 1;
  
  if(newClass.course == newClass2.course){
    if(newClass.lecturer == newClass2.lecturer){
      if(newClass.typeOfClass == newClass2.typeOfClass){
        for(i = 0 ; i < 5 ; i++){
          if(newClass.group[i] == newClass2.group[i]);
          else
            return 0;
        }
      }
      else
        return 0;
    }
    else
      return 0;
  }
  else
    return 0;
    
  return 1;
}

void indexForward(int *venue, int *day, int *time){

  if(*venue < 0 || *day < 0 || *time < 0)
    Throw(ERR_EXCEEDED_INDEX);
  if(*venue >= MAX_VENUE || *day >= MAX_DAY || *time >= MAX_TIME_SLOT)
    Throw(ERR_EXCEEDED_INDEX);

  (*time)++;
  
  if(*time >= MAX_TIME_SLOT){
    *time = 0;
    (*day)++;
  }
  if(*day >= MAX_DAY){
    *day = 0;
    (*venue)++;
  }
  if(*venue >= MAX_VENUE)
    *venue = 0;
}

void indexBackward(int *venue, int *day, int *time){
  
  if(*venue < 0 || *day < 0 || *time < 0)
    Throw(ERR_EXCEEDED_INDEX);
  if(*venue >= MAX_VENUE || *day >= MAX_DAY || *time >= MAX_TIME_SLOT)
    Throw(ERR_EXCEEDED_INDEX);
  
  (*time)--;
  
  if(*time < 0){
    *time = MAX_TIME_SLOT - 1;
    (*day)--;
  }
  if(*day < 0){
    *day = MAX_DAY - 1;
    (*venue)--;
  }
  if(*venue < 0)
    *venue = MAX_VENUE - 1;
}