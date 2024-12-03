#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Static.h"

int main() {
    
    SArrayList s;
    s.count = 0;
    
    insertRear(&s, 5);
    display(s);
    insertFront(&s, 2);
    display(s);
    insertRear(&s, 6);
    display(s);
    insertFront(&s, 5);
    display(s);
    insertFront(&s, 5);
    display(s);
    insertAt(&s, 1, 2);
    display(s);
    removeFront(&s);
    display(s);
    removeRear(&s);
    display(s);
    removeItem(&s, 1);
    display(s);
    removeAllItem(&s, 5);
    display(s);
    
    return 0;
}