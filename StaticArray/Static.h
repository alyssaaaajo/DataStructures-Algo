#ifndef STATIC_H
#define STATIC_H
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} SArrayList;

void display(SArrayList s);
bool insertFront(SArrayList *s, int item);
bool insertRear(SArrayList *s, int item);
bool insertAt(SArrayList *s, int item, int pos);
bool removeFront(SArrayList *s);
bool removeRear(SArrayList *s);
bool removeItem(SArrayList *s, int item);
bool removeAllItem(SArrayList *s, int item);

#endif