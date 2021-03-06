#include <stdio.h>
#include "TestStructure.h"
#include "CException.h"
#include "ErrorCode.h"
#include "malloc.h"

#define FOR_TEST

#define Lecture             'l'
#define Tutorial            't'
#define Practical           'p'

/************************************************************************
 *  List of Venue
 ************************************************************************/
 Venue venueList[] = {{ .nameOfVenue = "D300",
                        .sizeOfVenue = 55,
                        .venueType = 'p',
                        .numOfSpecificCourse = 1
                      },
                      { .nameOfVenue = "K102",
                        .sizeOfVenue = 95,
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
                              .department = "CDED"
                            },
                            { .lecturerName = "AuLheeCiang",
                              .department = "EG"
                            },
                            { .lecturerName = "YapMenKun",
                              .department = "LGD"
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
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 1,
                          .hoursOfPractical = 0,
                          .numOfProgramme = 2,
                          .numOfCombinedGroups = 2
                        },
                        { .courseCode = "AAMP4321",
                          .courseName = "Mathematics",
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 2,
                          .hoursOfPractical = 0,
                          .numOfProgramme = 2,
                          .numOfCombinedGroups = 2
                        },
                        { .courseCode = "MDFK9413",
                          .courseName = "ControlSystem",
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 1,
                          .hoursOfPractical = 1,
                          .numOfProgramme = 2,
                          .numOfCombinedGroups = 2
                        },
                        {
                          .courseCode = "ROLF4854",
                          .courseName = "TamadunIslam",
                          .hoursOfLecture = 2,
                          .hoursOfTutorial = 2,
                          .hoursOfPractical = 0,
                          .numOfProgramme = 3,
                          .numOfCombinedGroups = 3
                        }};
                        
/************************************************************************
 *  List of Class
 ************************************************************************/
 // class[0]  = group 0,1,2,3. lecturer = 0. lecture. size = 72
 // class[1]  = group 0,1,2,3. lecturer = 0. lecture. size = 72
 // class[2]  = group 0,1.     lecturer = 0. lecture. size = 32
 // class[3]  = group 2,3.     lecturer = 0. lecture. size = 40
 // class[4]  = group 2,3,4,5. lecturer = 1. lecture. size = 60
 // class[5]  = group 2,3,4,5. lecturer = 1. lecture. size = 60
 // class[6]  = group 2,3.     lecturer = 1. lecture. size = 40
 // class[7]  = group 2,3.     lecturer = 1. lecture. size = 40
 // class[8]  = group 4,5.     lecturer = 1. lecture. size = 20
 // class[9]  = group 4,5.     lecturer = 1. lecture. size = 20
 // class[10] = group 0,1,4,5. lecturer = 2. lecture. size = 52
 // class[11] = group 0,1,4,5. lecturer = 2. lecture. size = 52
 // class[12] = group 0,1.     lecturer = 2. lecture. size = 32
 // class[13] = group 4,5.     lecturer = 2. lecture. size = 20
 // class[14] = group 0,1.     lecturer = 2. lecture. size = 32
 // class[15] = group 4,5.     lecturer = 2. lecture. size = 20
 
 Class clazzList[] = {{ .course = &courseList[0],
                         .lecturer = &lecturerList[0],
                         .typeOfClass = 'l',
                         .groupIndexInClass = 0
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[0],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[1],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'p',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[2],
                          .lecturer = &lecturerList[2],
                          .typeOfClass = 'p',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 'l',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[0],
                          .typeOfClass = 't',
                          .groupIndexInClass = 0
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 1
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 2
                        },
                        { .course = &courseList[3],
                          .lecturer = &lecturerList[1],
                          .typeOfClass = 't',
                          .groupIndexInClass = 2
                        }};
                        
                        
/****************************************************************************
 *  Initialization of structures
 *****************************************************************************/
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
  courseList[0].programme = malloc(courseList[0].numOfProgramme*sizeof(Programme*));
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
  
  courseList[1].programme = malloc(courseList[1].numOfProgramme*sizeof(Programme*));
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
  
  courseList[2].programme = malloc(courseList[2].numOfProgramme*sizeof(Programme*));
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
  
  courseList[3].programme = malloc(courseList[3].numOfProgramme*sizeof(Programme*));
  courseList[3].programme[0] = &programmeList[0];
  courseList[3].programme[1] = &programmeList[1];
  courseList[3].programme[2] = &programmeList[2];
  courseList[3].combinedGroups = malloc(courseList[3].numOfCombinedGroups*sizeof(CombinedGroups));
  courseList[3].combinedGroups[0].size = 2;
  courseList[3].combinedGroups[1].size = 2;
  courseList[3].combinedGroups[2].size = 2;
  courseList[3].combinedGroups[0].groups = malloc(courseList[3].combinedGroups[0].size*sizeof(Group*));
  courseList[3].combinedGroups[1].groups = malloc(courseList[3].combinedGroups[1].size*sizeof(Group*));
  courseList[3].combinedGroups[2].groups = malloc(courseList[3].combinedGroups[2].size*sizeof(Group*));
  courseList[3].combinedGroups[0].groups[0] = &groupList[0];
  courseList[3].combinedGroups[0].groups[1] = &groupList[1];
  courseList[3].combinedGroups[1].groups[0] = &groupList[2];
  courseList[3].combinedGroups[1].groups[1] = &groupList[3];  
  courseList[3].combinedGroups[2].groups[0] = &groupList[4];
  courseList[3].combinedGroups[2].groups[1] = &groupList[5];
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
  
  //Tamadun Islam
  clazzList[16].groupInClass = NULL;
  clazzList[17].groupInClass = NULL;
  clazzList[18].groupInClass = &(clazzList[18].course->combinedGroups[clazzList[18].groupIndexInClass]);
  clazzList[19].groupInClass = &(clazzList[19].course->combinedGroups[clazzList[19].groupIndexInClass]);
  clazzList[20].groupInClass = &(clazzList[20].course->combinedGroups[clazzList[20].groupIndexInClass]);
  clazzList[21].groupInClass = &(clazzList[21].course->combinedGroups[clazzList[21].groupIndexInClass]);
  clazzList[22].groupInClass = &(clazzList[22].course->combinedGroups[clazzList[22].groupIndexInClass]);
  clazzList[23].groupInClass = &(clazzList[23].course->combinedGroups[clazzList[23].groupIndexInClass]);
  
}           

void initVenueList(){
  venueList[0].course = malloc(venueList[0].numOfSpecificCourse*sizeof(Course*)); 
  venueList[0].course[0] = &courseList[2];
}

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