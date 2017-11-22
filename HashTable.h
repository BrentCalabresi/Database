#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef _HashTableH_
#define _HashTableH_


typedef struct HashTable{
  int size;
  LinkedList* buckets[];//array of linkedlist* buckets

}HashTable;

HashTable* HashTable_new(int size);
void HashTable_put(HashTable* table, int key, void* value);
int hash(HashTable* t, int key);
void* HashTable_lookup(HashTable* table, int key);

#endif
