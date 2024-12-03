#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#define MAX 10

typedef struct node {
    int item;
    struct node *prev, *next;
} NodeType, *NodePtr, *List;

void display(NodePtr s);
bool insertFront(NodePtr *s, int item);
bool insertRear(NodePtr *s, int item);
bool insertAt(NodePtr *s, int item, int pos);
bool removeFront(NodePtr *s);
bool removeRear(NodePtr *s);
bool removeItem(NodePtr *s, int item);
bool removeAllItem(NodePtr *s, int item);


#endif