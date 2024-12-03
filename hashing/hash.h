#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

typedef struct {
    int studID;
    char studName[16];
    char program[8];
    bool sex; //true - male, false - female
    int level;
} Student;

typedef struct {
    Student *data;
    int count;
    int max;
} StudDictionary;

//id = 0 Empty, id = -1 Deleted

void initDictionary(StudDictionary *d);
bool insertStudent(StudDictionary *d, Student s);
bool removeStudent(StudDictionary *d, Student s);
int getHash(Student s);
void visualize(StudDictionary d);


#endif