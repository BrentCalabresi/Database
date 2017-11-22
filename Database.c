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
  int key = atoi(data->course)+data->studentId;//convert string into int for easier key calculation
  HashTable_put(db->CSG,key,data);
}
void delete(){
}
CSG* lookup_csg(CSG* tuple, Database* db){
  CSG* relation;
  if (strcmp(tuple->course,"*") == 0) {//wildcard element of tuple
  }
  if (tuple->studentId == -1) {//wildcard element for int val of tuple
  }
  if (strcmp(tuple->grade,"*") == 0) {//wildcard element of tuple
  }
  //printf("%s\n", "made it");
  relation = HashTable_lookup(db->CSG,(int) *tuple->course+tuple->studentId);

  return relation;
}
