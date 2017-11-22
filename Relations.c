#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Relations.h"


CSG* CSG_new(char course[5], int studentId, char grade[2]){
  //printf("%s\n", "starting csg init");
  CSG* relation = (CSG*)malloc(sizeof(CSG));
  strcpy(relation->course,course);
  strcpy(relation->grade,grade);
  relation->studentId = studentId;
  //printf("%s\n", "relation initialized");
  return relation;
}

SNAP* SNAP_new(int studentId, char name[15], char address[15], char phone[9]){
  SNAP* relation = (SNAP*)malloc(sizeof(SNAP));
  relation->studentId = studentId;
  strcpy(relation->name, name);
  strcpy(relation->address, address);
  strcpy(relation->phone, phone);
  return relation;
}

CP* CP_new(char course[5], char prereq[5]){
  CP* relation = (CP*)malloc(sizeof(CP));
  strcpy(relation->course, course);
  strcpy(relation->prereq, prereq);
  return relation;
}

CR* CR_new(char course[5], char room[15]){
  CR* relation = (CR*)malloc(sizeof(CR));
  strcpy(relation->course, course);
  strcpy(relation->room, room);
  return relation;
}

CDH* CDH_new(char course[5], char day[2], char hour[4]){
  CDH* relation = (CDH*)malloc(sizeof(CDH));
  strcpy(relation->course,course);
  strcpy(relation->day,day);
  strcpy(relation->hour,hour);
  return relation;
}
