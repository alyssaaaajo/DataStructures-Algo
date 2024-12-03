#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
#define MAX 5


typedef char String[20];

typedef struct {
    String fname, mname, lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    String program;
    int year;
} Student;

typedef struct {
    Student elem[MAX]; //e change ang int into student
    int count;
} Stack;

Name createName(String fname, String mname, String lname);
Student createStudent(int studID, Name studName, String program, int year);

void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);

bool isFound(Stack s, String lastname);
Name getStudentInProgram(Stack s, String program);

#endif