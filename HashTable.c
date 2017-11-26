#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "Database.h"
#include "LinkedList.c"


HashTable* HashTable_new(int size){
  HashTable* table = (HashTable*)calloc(size,sizeof(HashTable));
  table->size = size;
  for(int i=0;i<size;i++){
    //printf("%p\n",table->buckets[i]);
    table->buckets[i] = LinkedList_new();//we need to call "new" function for proper setup
  }
  return table;
}

void HashTable_put(HashTable* table, int key, void* value){
  int h = hash(table, key);
  //printf("%s %s\n","Inserting value: ", value);
  LinkedList_add_at_end(table->buckets[h], value);
  //printf("%s\n", "List after insert:");
  //LinkedList_print_string_list(table->buckets[h]);
}
void HashTable_print(HashTable* table){
  printf("\n%s\n", "Hashtable: ");
  for (int i=0;i < table->size;i++) {
    LinkedList_print_string_list(table->buckets[i]);
  }
  printf("\n");
}

void* HashTable_lookup(HashTable* table, int key, void* relation){
  //int key = getKey(relation->course)+relation->studentId;
  //printf("%s %d\n","lookup key: ",key );
  LinkedList* possibleBucket = table->buckets[hash(table, key)];
  //LinkedList_print_string_list(possibleBucket);

  for (LinkedListNode *node=possibleBucket->first; node != NULL; node=node->next){
    //printf("%s\n", "made it into loop");
    if (node->data == relation)
      return node->data;
  }
  return NULL;
}

void HashTable_remove(HashTable* table, int key, void* relation){
  //int key = atoi(relation->course)+relation->studentId;
  //int key = getKey(relation->course)+relation->studentId;
  LinkedList* possibleBucket = table->buckets[hash(table, key)];

  for (LinkedListNode *node=possibleBucket->first; node != NULL; node=node->next){
    //printf("%s\n", "made it into loop");
    if (node->data == relation){
      //printf("%s\n", "found tuple to delete");
      LinkedList_remove(possibleBucket,relation);
    }
  }
}

int getKey(char* string){//generic function to convert string into int
  int key = -1;
  for(int i=0;i<strlen(string);i++){
    key += (int)string[i];
  }

  return key;
}

int hash(HashTable* t, int key){//returns index of bucket to hash to
  key *= 479;
  //printf("%s %d\n","key: ",key);
  int size = t->size;
  key = key%size;
  //printf("%s %d\n","array loc (modded to): ",key);
  return key;
}
