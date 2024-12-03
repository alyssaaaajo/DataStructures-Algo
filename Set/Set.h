#ifndef SET_H
#define SET_H
#include <stdbool.h>
#define MAX 100

typedef struct {
    int elems[MAX];
    int count;
} Set;

Set createSet();
bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symetricDifferenceSet(Set a, Set b); //(A-B)U(B-A)
int cardinality(Set s); //total ka element
bool isElement(Set s, int item); //


#endif