#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

void initStack(Stack *s) {
    s->count = 0;
}

Stack createStack() {
    Stack s;
    
    s.count = 0;
    
    return s;
}

bool isEmpty(Stack s) {
    return s.count == 0;
}

bool isFull(Stack s) {
    return s.count >= MAX;
}

void visualize(Stack s) {
    printf("List {");
    for(int i=0; i < s.count; ++i) {
        printf("%d", s.elem[i]);
        if(i < s.count - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool push(Stack *s, int item) {
    if(!isFull(*s)) {
        s->elem[(s->count)++] = item;
        return true;
    }
    return false;
}

bool pop(Stack *s) {
    if(!isEmpty(*s)) {
        (s->count)--;
        return true;
    }
    return false;
}

int peek(Stack s) {
    return s.elem[s.count - 1];
}

bool isFound(Stack s, int item) {
    bool found = false;
    
    while(!isEmpty(s)) {
        if(peek(s) == item) {
            return true;
        }
        pop(&s);
    }
    
    return found;
}

Stack removeEven(Stack *s) {
    Stack temp, new;
    initStack(&temp);
    initStack(&new);
    
    while(!isEmpty(*s)){
        if(peek(*s) % 2 == 0){
            push(&new, peek(*s));
        }
        else{
            push(&temp, peek(*s));
        }
        pop(s);
    }
    
    while(!isEmpty(temp)){
        push(s, peek(temp));
        pop(&temp);
    }
    
    return new;
}