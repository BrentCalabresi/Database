#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "HashTable.h"
//#include "Relations.h"

#ifndef _DatabaseH_
#define _DatabaseH_

typedef struct Database{
  HashTable *CSG,*SNAP,*CP,*CR,*CDH; //one hashtable for each possible type of relation

}Database;

Database* Database_init();

void insert_CSG(CSG* csg, Database* db);
CSG* lookup_csg(CSG* tuple, Database* db);
void remove_CSG(CSG* tuple, Database* db);

void insert_SNAP(SNAP* data, Database* db);
SNAP* lookup_SNAP(SNAP* tuple, Database* db);
void remove_SNAP(SNAP* tuple, Database* db);
#endif
