#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Database.h"
#include "HashTable.h"

Database* Database_init(){
  Database* db = (Database*)malloc(sizeof(Database));
  db->CSG = HashTable_new(5);
  db->SNAP = HashTable_new(5);
  db->CP = HashTable_new(5);
  db->CR = HashTable_new(5);
  db->CDH = HashTable_new(5);
  //printf("%s\n", "database initialized");
  return db;
}

void insert_CSG(CSG* data, Database* db){
  int key = getKey(data->course)+data->studentId;
  HashTable_put(db->CSG,key,data);
  printf("%s (%s, %d, %s) \n","Inserting value: ", data->course,data->studentId,data->grade);
}
void remove_CSG(CSG* tuple, Database* db){
  int key = getKey(tuple->course)+tuple->studentId;
  HashTable_remove(db->CSG,key,tuple);
  printf("%s %p\n", "Removing: ",tuple);
}
CSG* lookup_csg(CSG* tuple, Database* db){
  CSG* relation;
  int key = getKey(tuple->course)+tuple->studentId;
  if (strcmp(tuple->course,"*") == 0) {//wildcard element of tuple
  }
  if (tuple->studentId == -1) {//wildcard element for int val of tuple
  }
  if (strcmp(tuple->grade,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup(db->CSG,key,tuple);
  if (relation == NULL)
    relation = CSG_new("NULL",-1,"NULL");//returning a "NULL" makes for easier debugging
  return relation;
}

void insert_SNAP(SNAP* data, Database* db){
  int key = data->studentId;//only 1 copy of each student in this structure
  HashTable_put(db->SNAP,key,data);
  printf("%s (%d, %s, %s, %s) \n","Inserting value: ", data->studentId,data->name,data->address,data->phone);
}
SNAP* lookup_SNAP(SNAP* tuple, Database* db){
  SNAP* relation;
  int key = tuple->studentId;
  if (strcmp(tuple->name,"*") == 0) {//wildcard element of tuple
  }
  if (tuple->studentId == -1) {//wildcard element for int val of tuple
  }
  if (strcmp(tuple->address,"*") == 0) {//wildcard element of tuple
  }
  if (strcmp(tuple->phone,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup(db->SNAP,key,tuple);
  if (relation == NULL)
    relation = SNAP_new(-1,"NULL","NULL","NULL");//returning a "NULL" makes for easier debugging
  return relation;
}
void remove_SNAP(SNAP* tuple, Database* db){
  int key = tuple->studentId;
  HashTable_remove(db->SNAP, key, tuple);
  printf("%s %p\n", "Removing: ",tuple);
}

void insert_CP(CP* data, Database* db){
  int key = getKey(data->course);
  HashTable_put(db->CP,key,data);
  printf("%s (%s, %s) \n","Inserting value: ", data->course,data->prereq);
}
void remove_CP(CP* tuple, Database* db){
  int key = getKey(tuple->course);
  HashTable_remove(db->CP,key,tuple);
  printf("%s %p\n", "Removing: ",tuple);
}
CP* lookup_CP(CP* tuple, Database* db){
  CP* relation;
  int key = getKey(tuple->course);
  if (strcmp(tuple->course,"*") == 0) {//wildcard element of tuple
  }
  if (strcmp(tuple->prereq,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup(db->CP,key,tuple);
  if (relation == NULL)
    relation = CP_new("NULL","NULL");//returning a "NULL" makes for easier debugging
  return relation;
}

void insert_CR(CR* data, Database* db){
  int key = getKey(data->course);
  HashTable_put(db->CR,key,data);
  printf("%s (%s, %s) \n","Inserting value: ", data->course,data->room);
}
void remove_CR(CR* tuple, Database* db){
  int key = getKey(tuple->course);
  HashTable_remove(db->CR,key,tuple);
  printf("%s %p\n", "Removing: ",tuple);
}
CR* lookup_CR(CR* tuple, Database* db){
  CR* relation;
  int key = getKey(tuple->course);
  if (strcmp(tuple->course,"*") == 0) {//wildcard element of tuple
  }
  if (strcmp(tuple->room,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup(db->CR,key,tuple);
  if (relation == NULL)
    relation = CR_new("NULL","NULL");//returning a "NULL" makes for easier debugging
  return relation;
}

void insert_CDH(CDH* data, Database* db){
  int key = getKey(data->course)+getKey(data->day)+getKey(data->hour);
  HashTable_put(db->CDH,key,data);
  printf("%s (%s, %s, %s) \n","Inserting value: ", data->course,data->day,data->hour);
}
void remove_CDH(CDH* tuple, Database* db){
  int key = getKey(tuple->course)+getKey(tuple->day)+getKey(tuple->hour);
  HashTable_remove(db->CDH,key,tuple);
  printf("%s %p\n", "Removing: ",tuple);
}
CDH* lookup_CDH(CDH* tuple, Database* db){
  CDH* relation;
  int key = getKey(tuple->course)+getKey(tuple->day)+getKey(tuple->hour);
  if (strcmp(tuple->course,"*") == 0) {//wildcard element of tuple
  }
  if (strcmp (tuple->day, "*")==0) {//wildcard element for int val of tuple
  }
  if (strcmp(tuple->hour,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup(db->CDH,key,tuple);
  if (relation == NULL)
    relation = CDH_new("NULL","NULL","NULL");//returning a "NULL" makes for easier debugging
  return relation;
}
