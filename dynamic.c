#include <stdio.h>
#include <stdbool.h>
#include "dynamic.h"


void display(DArrayList s) {
    printf("{");
    for(int i=0; i < s.count; ++i){
        printf("%d", s.items[i]);
        if(i < s.count - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool insertFront(DArrayList *s, int item) {
    if(s->count < MAX) {
        for (int i = s->count; i > 0; i--) {
            s->items[i] = s->items[i - 1];
        }
        s->items[0] = item;
        s->count++;
        return true;
    }
    return false;
}

bool insertRear(DArrayList *s, int item) {
    if(s->count < MAX){
        s->items[s->count] = item;
        s->count++;
        return true;
    }
    return false;
}

bool insertAt(DArrayList *s, int item, int pos) {
    if(pos < 0 || pos > s->count) {
        printf("Invalid position!\n");
        return false;
    }
    for(int i = s->count; i > pos; i--) {
        s->items[i] = s->items[i - 1];
    }
    s->items[pos] = item;
    s->count++;
    return true;
}

bool removeFront(DArrayList *s) {
    if (s->count == 0) {
        printf("List is empty!\n");
        return false;
    }
    for (int i = 0; i < s->count - 1; i++) {
        s->items[i] = s->items[i + 1];
    }
    s->count--;
    return true;
}

bool removeRear(DArrayList *s) {
    if (s->count == 0) {
        printf("List is empty!\n");
        return false;
    }
    s->count--;
    return true;
}

bool removeItem(DArrayList *s, int item) {
    if (s->count == 0) {
        printf("List is empty!\n");
        return false;
    }
    for (int i = 0; i < s->count; i++) {
        if (s->items[i] == item) {
            for (int j = i; j < s->count - 1; j++) {
                s->items[j] = s->items[j + 1];
            }
            s->count--;
            return true;
        }
    }
    printf("Item not found!\n");
    return false;
}

bool removeAllItem(DArrayList *s, int item) {
    bool removed = false;
    if (s->count == 0) {
        printf("List is empty!\n");
        return false;
    }
    for (int i = 0; i < s->count; i++) {
        if (s->items[i] == item) {
            for (int j = i; j < s->count - 1; j++) {
                s->items[j] = s->items[j + 1];
            }
            s->count--;
            i--;
            removed = true;
        }
    }
    if (!removed) {
        printf("Item not found!\n");
    }
    return removed;
}


