//
// hash - hash.c
// Created by Edoardo Debenedetti on 26/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

// STRUCTS
typedef struct _HASH_EL {
    LIST* element;
    struct _HASH_EL* next;
} HASH_EL;

typedef struct _HASH_TABLE_DESCR {
    int size;
    int elements;
    HASH_EL** table;
} HASH_TABLE_DESCR;

// PROTOS FOR INTERNAL FUNCTIONS
HASH_EL* createLinkedList (HASH_EL* head);
int hash(char* name, char* surname, HASH_TABLE_DESCR* descriptor);

// FUNCTIONS
int hash(char* name, char* surname, HASH_TABLE_DESCR* descriptor) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        sum += name[i]; // sums all the key chars with the ASCII code
    }
    for (int i = 0; surname[i] != '\0'; ++i) {
        sum += surname[i]; // sums all the key chars with the ASCII code
    }
    return sum % descriptor->size;
}
HASH_TABLE_DESCR* createHashTable(HASH_TABLE_DESCR* descriptor, int size) {
    descriptor = (HASH_TABLE_DESCR*)malloc(sizeof(HASH_TABLE_DESCR));
    descriptor->size = size;
    descriptor->table = (HASH_EL**)malloc(sizeof(HASH_EL)*size);
    for (int i = 0; i < descriptor->size; ++i) {
       descriptor->table[i] = NULL; // initializes all the elements of the array to NULL
    }
    descriptor->elements = 0;
    return descriptor;
}
void printTable(HASH_TABLE_DESCR* descriptor) { // prints the table
    for (int i = 0; i < descriptor->size; ++i) {
        if (descriptor->table[i] != NULL) { // goes in the list only if has been initialized
            HASH_EL* ptr = descriptor->table[i]->next; // creates the pointer used to go through the list
            while (ptr->next) {
                printf("ID: %d, NAME: %s, SURNAME: %s;\n", nodeID(ptr->element), nodeName(ptr->element), nodeSurname(ptr->element));
                ptr = ptr->next;
            }
        }
    }
}
int insert(HASH_TABLE_DESCR* descriptor, char* name, char* surname, LIST* element) {
    HASH_EL* new = (HASH_EL*)malloc(sizeof(HASH_EL));
    int hash_number = hash(name, surname, descriptor); // hashes the element
    printf("The hash for \"%s %s\" is %d;\n", name, surname, hash_number);
    if (descriptor->table[hash_number] == NULL) { // if the list hasn't been initialized, initializes it
        descriptor->table[hash_number] = createLinkedList(descriptor->table[hash_number]);
    }
    new->element = element;
    new->next = descriptor->table[hash_number]->next;
    descriptor->table[hash_number]->next = new;
    ++descriptor->elements;
    return 0;
}
HASH_EL* createLinkedList (HASH_EL* head) { // initializes the linked list when required
    head = (HASH_EL*)malloc(sizeof(HASH_EL));
    if (!head) exit(EXIT_FAILURE);
    HASH_EL* tail = (HASH_EL*)malloc(sizeof(HASH_EL));
    if (!tail) exit(EXIT_FAILURE);
    tail->next = NULL;
    head->next = tail;
    return head;
}
value_type search(char* name, char* surname, HASH_TABLE_DESCR* descriptor) { // searches the element in the hash table
    int hash_number = hash(name, surname, descriptor); // hashes the key
    if (!descriptor->table[hash_number]) { // if the hash-th list has not been initialized, exits
        return 0; // not found
    }
    HASH_EL* ptr = descriptor->table[hash_number]->next; // pointer to go through the list
    while (ptr->next) {
        if (strcmp(nodeName(ptr->element), name) == 0 && strcmp(nodeSurname(ptr->element), surname) == 0) { // searches through the list
            printf("ID: %d\nName: %s\nSurname: %s\n", nodeID(ptr->element), nodeName(ptr->element), nodeSurname(ptr->element));
            return 1; // found
        }
        ptr = ptr->next;
    }
    return  0; // not found
}
/* int delete(key_type key, HASH_TABLE_DESCR* descriptor) {
    int hash_number = hash(key, descriptor); // hashes the key
    if (!descriptor->table[hash_number]) { // if the hash-th list has not been initialized, exits
        return 0;
    }
    HASH_EL* ptr = descriptor->table[hash_number]->next; // pointer to go through the list
    int flag = 0; // flag, if 0 not found, if 1 found
    while (!flag && ptr->next) {
        if (strcmp(ptr->next->key, key) == 0) { // searches through the list
            flag = 1; // exits when finds the element
        } else {
            ptr = ptr->next;
        }
    }
    if (flag == 1) {
        HASH_EL* toBeFreed = ptr->next;
        ptr->next = toBeFreed->next;
        free(toBeFreed);
        --descriptor->elements;
        return 1;
    }
    return  0;
} */