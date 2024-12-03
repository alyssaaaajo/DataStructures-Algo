#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Set.h"

Set createSet() {
    Set s;
    
    for(int i=0; i < MAX; ++i){
        s.elems[i] = 0;
    }
    s.count = 0;
    
    return s;
}

bool addElement(Set *s, int item) {
    if(s->elems[item] == 0 && item < MAX) {
        s->elems[item] = item;
        (s->count)++;
        return true;
    }
    return false;
}

bool removeElement(Set *s, int item) {
    if(s->elems[item] != 0 && item < MAX) {
        s->elems[item] = 0;
        (s->count)--;
        return true;
    }
    return false;
}

void displaySet(Set s) {
    for(int i=0; i < MAX; ++i) {
        if(s.elems[i] != 0){
            printf("%d, ", i);
        }
    }
    printf("\n");
}

Set unionSet(Set a, Set b) {
    Set s;
    for(int i=0; i < MAX; ++i){
        if(a.elems[i] != 0){
            s.elems[i] = a.elems[i];
        }
        if(b.elems[i] != 0){
            s.elems[i] = b.elems[i];
        }
    }
    return s;
}

Set intersectionSet(Set a, Set b) {

}

Set differenceSet(Set a, Set b) {
    
}

Set symetricDifferenceSet(Set a, Set b); //(A-B)U(B-A)
int cardinality(Set s) {
    return s.count;
}
bool isElement(Set s, int item); //check whether that element is in that set


