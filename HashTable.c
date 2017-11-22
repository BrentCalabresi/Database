#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
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
  //printf("%d\n",key );
  int h = hash(table, key);
  LinkedList_add_at_end(table->buckets[h], value);
}

void* HashTable_lookup(HashTable* table, int key){//search based on key
  LinkedList* possibleBucket = table->buckets[hash(table, key)];
  printf("%s %d\n","list equals null?: ",possibleBucket == NULL );
  printf("%p\n",possibleBucket->first);
  LinkedList_print_string_list(possibleBucket);
  for (LinkedListNode* tuple = possibleBucket->first; tuple->next != NULL; tuple = tuple->next){
    printf("%s\n", "made it into loop");
    //if (tuple->data == key)//TODO fix comparison
      return tuple->data;
  }
  return NULL;
}

int hash(HashTable* t, int key){//returns index of bucket to hash to
  key *= 479;
  printf("%s %d\n","key: ",key);
  int size = t->size;
  //printf("%d %s %d %s %d\n",key,"mod",size,"=",key%size);
  key = key%size;
  printf("%s %d\n","array loc (modded to): ",key);
  return key;
}
