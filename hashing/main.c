#include <stdio.h>
#include <string.h>
#include "hash.h"

// typedef struct {
//     int studID;
//     char studName[16];
//     char pgroam[8];
//     bool sex; //true - male, false - female
//     int level;
// } Student;

// typedef struct {
//     Student *data;
//     int count;
//     int max;
// } StudDictionary;

// //id = 0 Empty, id = -1 Deleted

// void initDictionary(StudDictionary *d);
// bool insertStudent(StudDictionary *d, Student s);
// bool removeStudent(StudDictionary *d, Student s);
// int getHash(Student s);
// void visualize(StudDictionary d);


int main() {
    StudDictionary d;
    initDictionary(&d);
    
    Student s1 = {5, "Cheska", "BSIT", false, 2};
    Student s2 = {7, "Joel", "BSCS", false, 2};
    Student s3 = {3, "Jomar", "BSCS", true, 2};
    Student s4 = {6, "Sam", "BSID", false, 2};
    Student s5 = {129, "Uary", "BSCS", false, 2};
    
    insertStudent(&d, s1);
    insertStudent(&d, s2);
    insertStudent(&d, s3);
    insertStudent(&d, s4);
    insertStudent(&d, s5);


    visualize(d);
    return 0;
}


