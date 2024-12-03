#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
//#include "MyHeader.h"
#define MAX 5

typedef struct {
    int elem[MAX]; //e change ang int into student
    int count;
} Stack;

void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, int item); // change int item to Student stud
bool pop(Stack *s);
int peek(Stack s);

bool isFound(Stack s, int item); // echange ang int item to String lastname
Stack removeEven(Stack *s); // change to Name getStudentInProgram(Stack s, String program);

#endif