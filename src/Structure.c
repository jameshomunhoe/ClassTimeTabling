#include <stdio.h>
#include "Structure.h"

// typedef struct Venue Venue;
// typedef struct Lecturer Lecturer;
// typedef struct Group Group;
// typedef struct Programme Programme;
// typedef struct Course Course;
// typedef struct Class Class;

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
                      
// Pending course and class to add