//
// double_linked_lists - double_linked_lists.h
// Created by Edoardo Debenedetti on 15/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//
#ifndef DOUBLE_LINKED_LISTS_DOUBLE_LINKED_LISTS_H
#define DOUBLE_LINKED_LISTS_DOUBLE_LINKED_LISTS_H

// STRUCTS
typedef struct _LIST LIST;

// FUNCTIONS
LIST* initList(void);
void insertElement(LIST* head, int ID, char* name, char* surname);
int countList (LIST* head);
int emptyList (LIST* head);
int printList(LIST* head);
int removeElement(LIST* head, int pos);
int getElement(LIST* head, int pos);
LIST* clearList(LIST* head);
void destroyList(LIST* head);

// INSERTIONSORT FUNCTION
void insertionSort(LIST* list);

// FUNCTIONS TO RETURN STRUCT ELEMENTS
LIST* next(LIST* ptr);
LIST* prior(LIST* ptr);
char* nodeName(LIST* ptr);
char* nodeSurname(LIST* ptr);
int nodeID(LIST* ptr);

#endif //DOUBLE_LINKED_LISTS_DOUBLE_LINKED_LISTS_H
