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
Nameval *reverse_it (Nameval *listp) {
    Nameval *prev = NULL;
    Nameval *nex = NULL;
    while (listp->next != NULL) {
        nex = listp->next;
        listp->next = prev;
        prev = listp;
        listp = nex;
    }
    listp->next = prev;
    return listp;
}
Nameval * reverse_rec (Nameval *listp, Nameval *prev) {
    Nameval *p;
    for (p = listp; p->next != NULL; p = p->next);
    if (listp->next != NULL) {
        reverse_rec(listp->next, listp);    
    }
    listp->next = prev;
    return p;
}
void freeall(Nameval *listp) {
    Nameval *next;
    for ( ; listp != NULL; listp = next) {
        next = listp->next;
        free(listp);
    }
}
int main(void) {
    Nameval *nvlist1 = NULL;
    Nameval *p = NULL;
    nvlist1 = addfront(nvlist1, newitem("data1", 10));
    nvlist1 = addend(nvlist1, newitem("data2", 45));
    nvlist1 = addend(nvlist1, newitem("data3", 65));
    nvlist1 = addend(nvlist1, newitem("data4", 75));
    nvlist1 = addend(nvlist1, newitem("data5", 85));
    nvlist1 = addend(nvlist1, newitem("data6", 95));
    nvlist1 = addend(nvlist1, newitem("data7", 105));
    for (p = nvlist1; p != NULL; p = p->next) {
        printf("%s %d %p\n", p->name, p->value, p);
    }
    putchar('\n');
    // nvlist1 = reverse_rec(nvlist1, NULL);
    nvlist1 = reverse_it(nvlist1);
    for (p = nvlist1; p != NULL; p = p->next) {
        printf("%s %d %p\n", p->name, p->value, p);
    }

    freeall(nvlist1);
    return 0;
}