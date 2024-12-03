#include <stdio.h>
#include <stdbool.h>
#include "Static.h"


void display(SArrayList s) {
    printf("{");
    for(int i=0; i< s.count; ++i){
        printf("%d", s.items[i]);
        if(i < s.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

bool insertFront(SArrayList *s, int item) {
    if(s->count == 0) {
        s->items[0] = item;
        (s->count)++;
        return true;
    }
    
    if(s->count < MAX){
        for(int i = s->count; i > 0; --i){
            s->items[i] = s->items[i - 1];
        }
        s->items[0] = item;
        (s->count)++;
        return true;
    }
    return false;
}

bool insertRear(SArrayList *s, int item) {
    if(s->count < MAX){
        s->items[(s->count)++] = item;
        return true;
    }
    return false;
}

bool insertAt(SArrayList *s, int item, int pos) {
    if(s->count < MAX){
        for(int i = s->count; i > pos; --i){
            s->items[i] = s->items[i - 1];
        }
        s->items[pos] = item;
        (s->count)++;
        return true;
    }
    return false;
}

bool removeFront(SArrayList *s) {
    if(s->count > 0){
        int count = s->count - 1;
        for(int i = 0; i < count; ++i){
            s->items[i] = s->items[i+1];
        }
        (s->count)--;
        return true;
    }
    return false;
}

bool removeRear(SArrayList *s) {
    if(s->count > 0){
        (s->count)--;
        return true;
    }
    return false;
}

bool removeItem(SArrayList *s, int item) {
    if(s->count > 0){
        for(int i=0; i < s->count; ++i){
            if(s->items[i] == item){
                for(int j=i; j < s->count - 1; ++j){
                    s->items[j] = s->items[j+1];
                }
                (s->count)--;
                return true;
            }
        }
    }
    return false;
}

bool removeAllItem(SArrayList *s, int item) {
    if(s->count > 0){
        for(int i=0; i < s->count; ++i){
            if(s->items[i] == item){
                for(int j=i; j < s->count - 1; ++j){
                    s->items[j] = s->items[j+1];
                }
                (s->count)--;
            }
        }
        return true;
    }
    return false;
}
