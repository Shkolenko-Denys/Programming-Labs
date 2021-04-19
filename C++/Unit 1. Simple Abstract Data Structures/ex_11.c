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
Nameval *lookup(Nameval *listp, char *name) {
    for ( ; listp != NULL; listp = listp->next) {
        if (strcmp(name, listp->name) == 0) {
            return listp;
        }
    }
    return NULL; /* no match */
}
void copy (Nameval *listp, char *name) {
    Nameval *p;
    for (p = listp; p->next != NULL; p = p->next);
    p->next = (Nameval *) malloc(sizeof(Nameval));
    *(p->next) = *(lookup(listp, name));
    p->next->next = NULL;
}
Nameval *delitem(Nameval *listp, char *name) {
    Nameval *p, *prev;
    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (strcmp(name, p->name) == 0) {
            if (prev == NULL) {
                listp = p->next;
            } else {
                prev->next = p->next;
            }
            free(p->name);
            free(p);
            return listp;
        }
        prev = p;
    }
    printf("delitem: %s not in list\n", name);
    return NULL; 
}
void freeall(Nameval *listp) {
    Nameval *next;
    for ( ; listp != NULL; listp = next) {
        next = listp->next;
        free(listp->name);
        free(listp);
    }
}
int main(void) {
    Nameval *nvlist1 = NULL;
    Nameval *p;
    nvlist1 = addfront(nvlist1, newitem("data1", 10));
    nvlist1 = addend(nvlist1, newitem("data2", 45));
    nvlist1 = addend(nvlist1, newitem("data3", 65));
    nvlist1 = addend(nvlist1, newitem("data4", 15));
    nvlist1 = addend(nvlist1, newitem("data5", 75));
    nvlist1 = addend(nvlist1, newitem("data6", 95));
    for (p = nvlist1; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }
    putchar('\n');

    delitem(nvlist1, "data2");
    for (p = nvlist1; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }

    freeall(nvlist1);
    return 0;
}