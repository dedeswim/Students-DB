//
// hash - hash.h
// Created by Edoardo Debenedetti on 26/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//
#ifndef HASH_HASH_H
#define HASH_HASH_H

#include "double_linked_lists.h"

#define HASH_SIZE 71

// MACROS
#define TABLE_SIZE 71

// STRUCTS
typedef struct _HASH_TABLE_DESCR HASH_TABLE_DESCR;
typedef char* key_type;
typedef int value_type;

// PROTOS
HASH_TABLE_DESCR* createHashTable(HASH_TABLE_DESCR* descriptor, int size);
void printTable(HASH_TABLE_DESCR* descriptor);
int insert(HASH_TABLE_DESCR* descriptor, char* name, char* surname, LIST* element);
value_type search(char* name, char* surname, HASH_TABLE_DESCR* descriptor);
int delete(key_type key, HASH_TABLE_DESCR* descriptor);
void freeHashTable(HASH_TABLE_DESCR* descriptor);

#endif //HASH_HASH_H