#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "hash.h"

//resize max | rehashing
//katong if sa last index, ibalik sa 0

void initDictionary(StudDictionary *d) {
    d->count = 0;
    d->max = 10;
    d->data = malloc(sizeof(Student) * (d->max));
    
    for(int i=0; i < (d->max); ++i) {
        d->data[i].studID = 0;
    }
}

int getHash(Student s) {
    int hash = 0;
    int n = 1;
    
    for(int i=0; i < 31; ++i) {
        if((s.studID >> i) & 1) {
            hash += n;
        }
        n++;
    }
    
    return hash;
}

bool insertStudent(StudDictionary *d, Student s) {
    int hash = getHash(s);
    int density = d->max * 0.8;
    int i;
    if(d->count < density) {
        for(i=hash; d->data[i].studID != 0 && d->data[i].studID != -1; i=(i + 1) % d->max){}
        d->data[i] = s;
        (d->count)++;
        return true;
    }

    return false;
}

void visualize(StudDictionary d) {
    for(int i=0; i < d.max; ++i) {
        printf("Index %d:\n", i);
        printf("ID: %d - %s\n\n", d.data[i].studID, d.data[i].studName);
    }
}

bool removeStudent(StudDictionary *d, Student s) {
    
}
