#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Relations.h"
#include "HashTable.h"
#include "Database.h"
void manual_tests(Database* database);

int main(){
  Database* database = Database_init();
  manual_tests(database);
}


// manually built debugging tests
void manual_tests(Database* database){

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


  printf("%s\n","-----------------------" );
  SNAP* jon = SNAP_new(2991,"Jon Smith","516 Maple st.","453-321-9801");
  SNAP* jane = SNAP_new(2993,"Jane King","263 Willow st.","123-472-9328");
  insert_SNAP(jon,database);
  insert_SNAP(jane,database);
  HashTable_print(database->SNAP);
  remove_SNAP(jane,database);
  HashTable_print(database->SNAP);
  printf("Student 2991's name: %s\n", lookup_SNAP(jon, database)->name);
  printf("Student 3662's name: %s\n", lookup_SNAP(jane, database)->name);

  printf("%s\n\n","-----------------------" );
  CP* csc1 = CP_new("CSC12","CSC11");
  CP* ece1 = CP_new("ECE12","ECE11");
  insert_CP(csc1,database);
  insert_CP(ece1,database);
  HashTable_print(database->CP);
  printf("CSC102 has prereq: %s\n", lookup_CP(csc1, database)->prereq);
  remove_CP(csc1, database);
  printf("CSC102 has prereq: %s\n", lookup_CP(csc1, database)->prereq);
  printf("ECE102 has prereq: %s\n", lookup_CP(ece1, database)->prereq);
  HashTable_print(database->CP);

  printf("%s\n\n","-----------------------" );
  CR* csc = CR_new("CSC12","Room 121");
  CR* ece = CR_new("ECE12","Room 322");
  insert_CR(csc,database);
  insert_CR(ece,database);
  HashTable_print(database->CR);
  printf("CSC102 is in room: %s\n", lookup_CR(csc, database)->room);
  remove_CR(csc, database);
  printf("CSC102 is in room: %s\n", lookup_CR(csc, database)->room);
  printf("ECE102 is in room: %s\n", lookup_CR(ece, database)->room);
  HashTable_print(database->CR);

  printf("%s\n\n","-----------------------" );
  CDH* csc_CDH = CDH_new("CSC12","M","1800");
  CDH* ece_CDH = CDH_new("ECE12","M","1140");
  insert_CDH(csc_CDH,database);
  insert_CDH(ece_CDH,database);
  HashTable_print(database->CDH);
  printf("CSC102 meets at: %s\n", lookup_CDH(csc_CDH, database)->day);
  remove_CDH(csc_CDH, database);
  printf("CSC102 meets at: %s\n", lookup_CDH(csc_CDH, database)->day);
  printf("ECE102 meets at: %s\n", lookup_CDH(ece_CDH, database)->day);
  HashTable_print(database->CDH);
}
