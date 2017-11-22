#include <stdio.h>
#include <stdlib.h>

#ifndef _RelationsH_
#define _RelationsH_

typedef struct CSG {//course-student-grade relation
char course[5];
int studentId;
char grade[2];
}CSG;

typedef struct SNAP {//studentID-name-address-phone relation
int studentId;
char name[15];
char address[15];
char phone[9];
}SNAP;

typedef struct CP {//course-prerequesite relation
char course[5];
char prereq[5];
}CP;

typedef struct CR {//course-room relation
char course[5];
char room[15];
}CR;

typedef struct CDH {//course-day-hour relation
char course[5];
char day[2];
char hour[4];
}CDH;

CSG* CSG_new(char course[], int studentId, char grade[]);
SNAP* SNAP_new(int studentId, char name[], char address[], char phone[]);
CP* CP_new(char course[], char prereq[]);
CR* CR_new(char course[], char room[]);
CDH* CDH_new(char course[], char day[], char hour[]);



#endif
