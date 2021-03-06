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
void* HashTable_lookup(HashTable* table, int key, void* relation);
void HashTable_remove(HashTable* table, int key, void* relation);

SNAP* HashTable_lookup_SNAP(HashTable* table, SNAP* relation);
void Hashtable_remove_SNAP(HashTable* table, SNAP* relation);

int getKey(char* string);
void HashTable_print(HashTable* table);

#endif
