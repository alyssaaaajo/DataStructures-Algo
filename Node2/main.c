#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"

int main() {
    
    NodePtr list = NULL;

    insertRear(&list, 10);
    insertRear(&list, 20);
    insertFront(&list, 5);
    insertAt(&list, 15, 2);

    display(list);

    removeFront(&list);
    display(list);

    removeRear(&list);
    display(list);

    removeItem(&list, 15);
    display(list);

    insertRear(&list, 20);
    insertRear(&list, 10);
    removeAllItem(&list, 10);
    display(list);
    
    return 0;
}