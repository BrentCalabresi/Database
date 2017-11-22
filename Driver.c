#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Relations.h"
#include "HashTable.h"
#include "Database.h"

int main(){
  Database* database = Database_init();
  CSG* test = CSG_new("CSC",2991,"A-");
  insert_CSG(test,database);
  lookup_csg(test, database);

}
