
#include "API/students_manager/students_manager.h"

int main() {
    importStudents("../res/students.txt");
    hashTableStudents();
    // printStudentsTable();
    readStudent("Peter Griffin");
    readStudent("Edoardo Debenedetti");
    return 0;
}