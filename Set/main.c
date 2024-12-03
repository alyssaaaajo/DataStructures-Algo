#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Set.h"

//SET A = 1, 2, 6, 7, 9
//SET B = 2, 3, 4, 5, 6
//A-B = 1, 7, 9
//B-A = 3, 4, 5
//(A-B)U(B-A) = 1, 3, 4, 5, 7, 9

int main() {
    
    Set s1 = createSet();
    Set s2 = createSet();

    addElement(&s1, 6);
    addElement(&s1, 2);
    addElement(&s1, 1);
    addElement(&s1, 7);
    addElement(&s1, 9);
    printf("Set A: ");
    displaySet(s1);
    
    addElement(&s2, 3);
    addElement(&s2, 2);
    addElement(&s2, 4);
    addElement(&s2, 5);
    addElement(&s2, 6);
    printf("Set B: ");
    displaySet(s2);
    
    Set setUnion = unionSet(s1, s2);
    printf("Union Set: ");
    displaySet(setUnion);
    
    Set setIntersection = intersectionSet(s1, s2);
    printf("Intersection Set: ");
    displaySet(setIntersection);
    
    return 0;
}




