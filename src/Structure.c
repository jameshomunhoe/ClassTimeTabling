#include <stdio.h>
#include "Structure.h"


/************************************************************************
 *	List of Venue
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
 *	List of Lecturer
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
 *	List of Group
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
 *	List of Programme
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
 *	List of Course
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
 *	List of Class
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
                        
                        
int getGroupSize(){
  int i, counter = 0;
  for(i = 0; groupList[i].groupName != NULL; i++){
    counter++;
  }
  return counter;
}