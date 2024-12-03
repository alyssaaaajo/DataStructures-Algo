#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"


void display(NodePtr s) {
    NodePtr temp = s;
    while (temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

bool insertFront(NodePtr *s, int item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        return false;
    }
    newNode->item = item;
    newNode->prev = NULL;
    newNode->next = *s;

    if (*s != NULL) {
        (*s)->prev = newNode;
    }
    *s = newNode;
    return true;
}

bool insertRear(NodePtr *s, int item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        return false;
    }
    newNode->item = item;
    newNode->next = NULL;

    if (*s == NULL) {
        newNode->prev = NULL;
        *s = newNode;
    } else {
        NodePtr temp = *s;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
        newNode->prev = NULL;
        newNode->next = *s;
        if (*s != NULL) {
            (*s)->prev = newNode;
        }
        *s = newNode;
    } else {
        NodePtr temp = *s;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of bounds!\n");
                free(newNode);
                return false;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return true;
}

bool removeFront(NodePtr *s) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }
    NodePtr temp = *s;
    *s = temp->next;
    if (*s != NULL) {
        (*s)->prev = NULL;
    }
    free(temp);
    return true;
}

bool removeRear(NodePtr *s) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }
    NodePtr temp = *s;
    if (temp->next == NULL) {
        *s = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    free(temp);
    return true;
}

bool removeItem(NodePtr *s, int item) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }

    NodePtr temp = *s;
    
    while (temp != NULL && temp->item != item) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item not found!\n");
        return false;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *s = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return true;
}

bool removeAllItem(NodePtr *s, int item) {
    if (*s == NULL) {
        printf("List is empty!\n");
        return false;
    }

    NodePtr temp = *s;
    bool removed = false;

    while (temp != NULL) {
        if (temp->item == item) {
            NodePtr toDelete = temp;
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *s = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            free(toDelete);
            removed = true;
        } else {
            temp = temp->next;
        }
    }

    if (!removed) {
        printf("Item not found!\n");
    }

    return removed;
}

