#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "MyStack.h"



int main() {
    Stack stackA;
    
    initStack(&stackA);
    
    Name name1 = createName("Chiska", "Gayle", "Ouano");
    Student stud1 = createStudent(1, name1, "Information Technology", 2);
    push(&stackA, stud1);

    Name name2 = createName("Joel", "Liv", "Mondragon");
    Student stud2 = createStudent(2, name2, "Computer Science", 3);
    push(&stackA, stud2);

    visualize(stackA);
    
    String searchProgram = "English";
    Name fName = getStudentInProgram(stackA, searchProgram);
    
    if (strcmp(fName.fname, "") != 0) {
        printf("Found student in program %s: %s %s %s\n", searchProgram, 
               fName.fname, fName.mname, fName.lname);
    } else {
        printf("No student found in program %s.\n", searchProgram);
    }
    
    return 0;
}