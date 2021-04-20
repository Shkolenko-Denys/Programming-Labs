#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next; /* next in list */
};
/* newitem: create new item from name and value */
Nameval *newitem(char *name, int value) {
    Nameval *newp;
    newp = (Nameval *) malloc(sizeof(Nameval));
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}
/* addfront: add newp to front of listp */
Nameval *addfront(Nameval *listp, Nameval *newp) {
    newp->next = listp;
    return newp;
}
/* addend: add newp to end of listp */
Nameval *addend(Nameval *listp, Nameval *newp) {
    if (listp == NULL)
        return newp;
    Nameval *p;
    for (p = listp; p->next != NULL; p = p->next);
    p->next = newp;
    return listp;
}
int counter(Nameval *listp) {
    int count = 0;
    for ( ; listp != NULL; listp = listp->next) {
        count++;
    }
    return count;
}
void printall(Nameval *listp) {
    for ( ; listp != NULL; listp = listp->next) {
        printf("%s %d\n", listp->name, listp->value);
    }
}

void freeall(Nameval *listp) {
    Nameval *next;
    for ( ; listp != NULL; listp = next) {
        next = listp->next;
        free(listp);
    }
}

int main(void) {
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("data1", 10));
    nvlist = addend(nvlist, newitem("data2", 45));
    nvlist = addend(nvlist, newitem("data3", 65));
    printf("Count: %d\n", counter(nvlist));
    printall(nvlist);
    freeall(nvlist);
    return 0;
}