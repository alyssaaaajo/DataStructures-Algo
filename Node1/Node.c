#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"


void display(NodePtr s) {
    NodePtr temp = s;
    while (temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->link;
    }
    printf("\n");
}

bool insertFront(NodePtr *s, int item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        return false;
    }
    newNode->item = item;
    newNode->link = *s;
    *s = newNode;
    return true;
}

bool insertRear(NodePtr *s, int item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        return false;
    }
    newNode->item = item;
    newNode->link = NULL;

    if (*s == NULL) {
        *s = newNode;
    } else {
        NodePtr temp = *s;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    return true;
}

bool insertAt(NodePtr *s, int item, int pos) {
    if (pos < 0) {
        printf("Invalid position!\n");
        return false;
    }

    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        return false;
    }
    newNode->item = item;

    if (pos == 0) {
        newNode->link = *s;
        *s = newNode;
    } else {
        NodePtr temp = *s;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of bounds!\n");
                free(newNode);
                return false;
            }
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    return true;
}

bool removeFront(NodePtr *s) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }
    NodePtr temp = *s;
    *s = temp->link;
    free(temp);
    return true;
}

bool removeRear(NodePtr *s) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }
    if ((*s)->link == NULL) {
        free(*s);
        *s = NULL;
    } else {
        NodePtr temp = *s;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
    return true;
}

bool removeItem(NodePtr *s, int item) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }

    NodePtr temp = *s;
    NodePtr prev = NULL;

    if (temp != NULL && temp->item == item) {
        *s = temp->link;
        free(temp);
        return true;
    }

    while (temp != NULL && temp->item != item) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Item not found!\n");
        return false;
    }
    
    prev->link = temp->link;
    free(temp);
    return true;
}

bool removeAllItem(NodePtr *s, int item) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }

    NodePtr temp = *s;
    NodePtr prev = NULL;
    bool removed = false;

    while (temp != NULL) {
        if (temp->item == item) {
            if (prev == NULL) {
                *s = temp->link;
                free(temp);
                temp = *s;
            } else {
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
            removed = true;
        } else {
            prev = temp;
            temp = temp->link;
        }
    }

    if (!removed) {
        printf("Item not found!\n");
    }

    return removed;
}

