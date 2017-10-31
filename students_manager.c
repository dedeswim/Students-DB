//
// 30_10_class_alt - students_manager.c
// Created by Edoardo Debenedetti on 30/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//

// MACROS
#define MAX_NAME 16
#define MAX_STRING 32 + 2

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "students_manager.h"
#include "hash_tables.h"


// GLOBAL VARS
LIST* students;
HASH_TABLE_DESCR* studentsHashTable;

// FUNCTIONS
void importStudents(char* filename) {
    FILE *studentsFile = fopen(filename, "r");
    if (!studentsFile) {
        fprintf(stderr, "ERROR: can't open the file \"%s\".\n", filename);
        exit(EXIT_FAILURE);
    }
    students = initList();
    char string[MAX_STRING];
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int ID;
    while (fgets(string, MAX_STRING, studentsFile)) {
        sscanf(string, "%d %s %s", &ID, name, surname);
        insertElement(students, ID, name, surname);
    }
    // printList(students);
    insertionSort(students);
    printList(students);
}
void hashTableStudents(void) {
    int size = HASH_SIZE;
    int listSize = countList(students);
    studentsHashTable = createHashTable(studentsHashTable, size);
    LIST* ptr = next(students);
    for (int t = 0; t < listSize; ++t) {
        insert(studentsHashTable, nodeName(ptr), nodeSurname(ptr), ptr);
        ptr = next(ptr);
    }
}
void printStudentsTable(void) {
    printTable(studentsHashTable);
}
void readStudent(char* completeName) {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    sscanf(completeName, "%s %s", name, surname);
    if(search(name, surname, studentsHashTable) == 0) {
        printf("Student \"%s\" not found.\n", completeName);
    }
}