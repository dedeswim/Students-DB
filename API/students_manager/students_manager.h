//
// 30_10_class_alt - students_manager.h
// Created by Edoardo Debenedetti on 30/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//
#ifndef INC_30_10_CLASS_ALT_STUDENTS_MANAGER_H
#define INC_30_10_CLASS_ALT_STUDENTS_MANAGER_H

#include "../double_linked_lists/double_linked_lists.h"
// STRUCTS

// PROTOS
void importStudents(char* filename);
void hashTableStudents(void);
void printStudentsTable(void);
void readStudent(char* completeName);

#endif //INC_30_10_CLASS_ALT_STUDENTS_MANAGER_H