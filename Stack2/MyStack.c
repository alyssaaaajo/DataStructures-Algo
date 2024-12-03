#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "MyStack.h"

void initStack(Stack *s) {
    s->count = 0;
}

Stack createStack() {
    Stack s;
    
    s.count = 0;
    
    return s;
}

Name createName(String fname, String mname, String lname) {
    Name n;
    
    strcpy(n.fname, fname);
    strcpy(n.mname, mname);
    strcpy(n.lname, lname);
    
    return n;
}

Student createStudent(int studID, Name studName, String program, int year) {
    Student s;
    
    s.studID = studID;
    s.studName = studName;
    strcpy(s.program, program);
    s.year = year;
    
    return s;
}

bool isEmpty(Stack s) {
    return s.count == 0;
}

bool isFull(Stack s) {
    return s.count >= MAX;
}

void visualize(Stack s) {
    printf("Student List:\n");
    for(int i=0; i < s.count; ++i) {
        printf("ID: %d\n", s.elem[i].studID);
        printf("Name: %s %s %s\n", s.elem[i].studName.fname, s.elem[i].studName.mname, s.elem[i].studName.lname);
        printf("Program: %s\n", s.elem[i].program);
        printf("Year: %d\n\n", s.elem[i].year);
    }
}

bool push(Stack *s, Student stud) {
    if(!isFull(*s)) {
        s->elem[(s->count)++] = stud;
        return true;
    }
    return false;
}

bool pop(Stack *s) {
    if(!isEmpty(*s)) {
        (s->count)--;
        return true;
    }
    return false;
}

Student peek(Stack s) {
    return s.elem[s.count - 1];
}

bool isFound(Stack s, String lastname) {
    bool found = false;
    
    while(!isEmpty(s)) {
        if(strcmp(peek(s).studName.lname, lastname) == 0) {
            return true;
        }
        pop(&s);
    }
    
    return found;
}

Name getStudentInProgram(Stack s, String program) {
    Name n = {"", "", ""};
    
    for(int i=0; i < s.count; ++i){
        if(strcmp(s.elem[i].program, program) == 0){
            n = s.elem[i].studName;
            return n;
        }
    }
    
    return n;
}