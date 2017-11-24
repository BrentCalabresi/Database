#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Database.h"

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
}
void remove_CSG(CSG* tuple, Database* db){
  Hashtable_remove_CSG(db->CSG,tuple);
  printf("%s %p\n", "Removing: ",tuple);
}
CSG* lookup_csg(CSG* tuple, Database* db){//tuple's key will be calculated in hashtable
  CSG* relation;
  if (strcmp(tuple->course,"*") == 0) {//wildcard element of tuple
  }
  if (tuple->studentId == -1) {//wildcard element for int val of tuple
  }
  if (strcmp(tuple->grade,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup_CSG(db->CSG,tuple);
  if (relation == NULL)
    relation = CSG_new("NULL",-1,"NULL");//returning a "NULL" makes for easier debugging
  return relation;
}

void insert_SNAP(SNAP* data, Database* db){
  int key = data->studentId;//only 1 copy of each student in this structure
  HashTable_put(db->SNAP,key,data);
}
SNAP* lookup_SNAP(SNAP* tuple, Database* db){//tuple's key will be calculated in hashtable
  SNAP* relation;
  if (strcmp(tuple->name,"*") == 0) {//wildcard element of tuple
  }
  if (tuple->studentId == -1) {//wildcard element for int val of tuple
  }
  if (strcmp(tuple->address,"*") == 0) {//wildcard element of tuple
  }
  if (strcmp(tuple->phone,"*") == 0) {//wildcard element of tuple
  }
  relation = HashTable_lookup_SNAP(db->SNAP,tuple);
  if (relation == NULL)
    relation = SNAP_new(-1,"NULL","NULL","NULL");//returning a "NULL" makes for easier debugging
  return relation;
}
void remove_SNAP(SNAP* tuple, Database* db){
  Hashtable_remove_SNAP(db->CSG,tuple);
  printf("%s %p\n", "Removing: ",tuple);
}
