#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Relations.h"
#include "HashTable.h"
#include "Database.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

int main(){
  Database* database = Database_init();
  CSG* test = CSG_new("CSC",2991,"A-");
  CSG* test2 = CSG_new("ECE",2991,"B");
  insert_CSG(test2,database);
  insert_CSG(test,database);
  HashTable_print(database->CSG);
  printf("Student 2991's grade in CSC: %s\n", lookup_csg(test, database)->grade);
  remove_CSG(test, database);
  printf("Student 2991's grade in CSC: %s\n", lookup_csg(test, database)->grade);
  printf("Student 2991's grade in ECE: %s\n", lookup_csg(test2, database)->grade);
  HashTable_print(database->CSG);

  //SNAP* jon = SNAP_new(2991,"Jon Smith","516 Maple st.","453-321-9801");
  SNAP* jane = SNAP_new(2993,"Jane King","263 Willow st.","123-472-9328");
  //insert_SNAP(jon,database);
  insert_SNAP(jane,database);
  HashTable_print(database->SNAP);
  remove_SNAP(jane,database);
  //printf("Student 2991's name: %s\n", lookup_SNAP(jon, database)->name);
  printf("Student 3662's name: %s\n", lookup_SNAP(jane, database)->name);
}
