#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <stdbool.h>

#define MAX 10

typedef struct {
    int *items;
    int count;
    int max;
} DArrayList;


void display(DArrayList s);
bool insertFront(DArrayList *s, int item);
bool insertRear(DArrayList *s, int item);
bool insertAt(DArrayList *s, int item, int pos);
bool removeFront(DArrayList *s);
bool removeRear(DArrayList *s);
bool removeItem(DArrayList *s, int item);
bool removeAllItem(DArrayList *s, int item);


#endif