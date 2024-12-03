#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

//remove all even and return all the remove even as a new stack

int main() {
    Stack stackA;
    
    initStack(&stackA);
    
    visualize(stackA);
    push(&stackA, 10);
    visualize(stackA);
    push(&stackA, 5);
    visualize(stackA);
    push(&stackA, 2);
    visualize(stackA);
    push(&stackA, 12);
    visualize(stackA);
    push(&stackA, 88);
    visualize(stackA);
    push(&stackA, 69);
    
    int x= 3;
    printf("Is %d in the stack? %d.\n", x, isFound(stackA, x));
    
    // for(int i= 0; i < 10; ++i) {
    //     pop(&stackA);
    //     visualize(stackA);
    // }
    
    Stack evenStack = removeEven(&stackA);
    
    printf("Odd Stack: ");
    visualize(stackA);
    printf("Even Stack: ");
    visualize(evenStack);
    
    return 0;
}