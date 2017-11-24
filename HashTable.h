#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Relations.h"

#ifndef _HashTableH_
#define _HashTableH_


typedef struct HashTable{
  int size;
  LinkedList* buckets[];//array of linkedlist* buckets

}HashTable;

HashTable* HashTable_new(int size);
void HashTable_put(HashTable* table, int key, void* value);
int hash(HashTable* t, int key);
CSG* HashTable_lookup_CSG(HashTable* table, CSG* relation);
void Hashtable_remove_CSG(HashTable* table, CSG* relation);

SNAP* HashTable_lookup_SNAP(HashTable* table, SNAP* relation);
void Hashtable_remove_SNAP(HashTable* table, SNAP* relation);

int getKey(char* string);
void HashTable_print(HashTable* table);

#endif
