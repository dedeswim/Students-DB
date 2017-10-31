//
// double_linked_lists - double_linked_lists.c
// Created by Edoardo Debenedetti on 15/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "double_linked_lists.h"


// STRUCTS
typedef struct _LIST {
    int ID; // data
    char* name;
    char* surname;
    struct _LIST* next;
    struct _LIST* prior;
} LIST;

// FUNCTIONS
LIST* initList(void) {
    LIST* head = (LIST*)malloc(sizeof(LIST));
    LIST* tail = (LIST*)malloc(sizeof(LIST));
    head->next = tail;
    head->prior = NULL;
    tail->next = NULL;
    tail->prior = head;
    return head;
}
int countList (LIST* head) {
    LIST* ptr = head;
    int t;
    for (t = 0; ptr->next != NULL; ++t) {
        ptr = ptr->next;
    }
    return t - 1;
}
int emptyList (LIST* head) {
    if (countList(head) == 0) {
        return 1;
    }
    return 0;
}
void insertElement(LIST* head, int ID, char* name, char* surname) {
    LIST* new = (LIST*)malloc(sizeof(LIST));
    new->ID = ID;
    new->name = (char*)malloc(strlen(name)* sizeof(char));
    if (!new->name) exit(EXIT_FAILURE);
    strcpy(new->name, name);
    new->surname = (char*)malloc(strlen(surname)* sizeof(char));
    if (!new->surname) exit(EXIT_FAILURE);
    strcpy(new->surname, surname);
    new->next = head->next;
    head->next->prior = new;
    head->next = new;
    new->prior = head;
}
int printList (LIST* head) {
    if (emptyList(head)) {
        fprintf(stderr, "ERROR: the list is empty.\n");
        return 1;
    }
    LIST* ptr = head->next;
    printf("STUDENTS:\n");
    while (ptr->next != NULL) {
        printf("ID: %d, NAME: %s, SURNAME: %s.\n", ptr->ID, ptr->name, ptr->surname);
        ptr = ptr->next;
    }
    return 0;
}
int removeElement(LIST* head, int pos) {
    if (pos > countList(head)) {
        fprintf(stderr, "ERROR: The index is bigger than the list's dimension.\n");
        return 1;
    }
    LIST* ptr = head;
    for (int t = 0; t < pos - 1; ++t) ptr = ptr->next;
    LIST* toRemove = ptr->next;
    ptr->next->next->prior = ptr;
    ptr->next = ptr->next->next;
    free(toRemove);
    printf("Element removed successfully.\n");
    return 0;
}
LIST* clearList(LIST* head) {
    while(!emptyList(head)) {
        LIST* ptr = head->next;
        ptr->next->prior = head;
        head->next = ptr->next;
        free(ptr);
    }
    printf("List cleared successfully.\n");
    return head;
}
void destroyList(LIST* head) {
    clearList(head);
    free(head->next);
    free(head);
    printf("List destroyed successfully\n");
}

// INSERTIONSORT FUNCTION
void insertionSort(LIST* head) {
    int size = countList(head);
    LIST* key = (LIST*)malloc(sizeof(LIST));
    LIST* tPtr = head->next->next;
    for (int t = 1; t < size; ++t) {
        key->ID = tPtr->ID;
        key->name = (char*)malloc(sizeof(char)*(strlen(tPtr->name)+1));
        if (!key->name) exit(EXIT_FAILURE);
        key->surname = (char*)malloc(sizeof(char)*(strlen(tPtr->surname)+1));
        if (!key->surname) exit(EXIT_FAILURE);
        strcpy(key->name, tPtr->name);
        strcpy(key->surname, tPtr->surname);
        int s = t - 1;
        LIST* sPtr = tPtr->prior;
        while (s >= 0 && sPtr->ID > key->ID) {
            sPtr->next->ID = sPtr->ID;
            strcpy(sPtr->next->name, sPtr->name);
            strcpy(sPtr->next->surname, sPtr->surname);
            --s;
            sPtr = sPtr->prior;
        }
        sPtr->next->ID = key->ID;
        sPtr->next->name = key->name;
        sPtr->next->surname = key->surname;
        tPtr = tPtr->next;
    }
}

// FUNCTIONS TO RETURN STRUCT ELEMENTS
LIST* next(LIST* ptr) {
    return ptr->next;
}
char* nodeName(LIST* ptr) {
    return ptr->name;
}
char* nodeSurname(LIST* ptr) {
    return ptr->surname;
}
int nodeID(LIST* ptr) {
    return ptr->ID;
}