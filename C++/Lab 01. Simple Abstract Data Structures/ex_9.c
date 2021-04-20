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
void inccounter(Nameval *p, void *arg) {
    int *ip;
     ip = (int *)arg;
     (*ip)++;
}
void coolfun (Nameval *listp, void (* fn)(Nameval *, void *), void * arg) {
    for ( ; listp != NULL; listp = listp->next) {
        fn(listp, arg);
    }
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
void merge(Nameval *listp1, Nameval *listp2) {
    Nameval *p;
    for (p = listp1; p->next != NULL; p = p->next);
    p->next = (Nameval *) malloc(sizeof(Nameval));
    p->next = listp2;
}
Nameval * unmerge(Nameval *listp, char *name) {
    Nameval *r;
    Nameval *d;
    r = lookup(listp, name);
    d = r->next;
    r->next = NULL;
    return d;
}
void addbefore(Nameval *listp, char *name, Nameval *new) {
    Nameval *p;
    for (p = listp; p->next->name != name; p = p->next);
    Nameval *r = p->next; // r - temporary var
    p->next = new;
    new->next = r;
}
void addafter(Nameval *listp, char *name, Nameval *new) {
    Nameval *p;
    for (p = listp; p->name != name; p = p->next);
    Nameval *r = p->next; // r - temporary var
    p->next = new;
    new->next = r;
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
    Nameval *nvlist2 = NULL;
    Nameval *nvlist3 = NULL;
    Nameval *newit1 = NULL;
    Nameval *newit2 = NULL;
    Nameval *p = NULL;
    
    nvlist1 = addfront(nvlist1, newitem("data1", 10));
    nvlist1 = addend(nvlist1, newitem("data2", 45));
    nvlist1 = addend(nvlist1, newitem("data3", 65));

    nvlist2 = addfront(nvlist2, newitem("data21", 10));
    nvlist2 = addend(nvlist2, newitem("data22", 20));
    nvlist2 = addend(nvlist2, newitem("data23", 30));
    nvlist2 = addend(nvlist2, newitem("data24", 40));

    printf("I)\n");
    for (p = nvlist1; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }

    printf("II)\n");
    for (p = nvlist2; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }
    putchar('\n');
    printf("Editing...\n\n");
    newit1 = newitem("newdate1", 100);
    newit2 = newitem("newdate2", 200);
    addafter(nvlist1, "data2", newit1);
    addbefore(nvlist1, "data3", newit2);
    copy(nvlist2, "data22");
    merge(nvlist1, nvlist2);
    nvlist3 = unmerge(nvlist1, "data2");

    printf("I)\n");
    for (p = nvlist1; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }
    printf("II)\n");
    for (p = nvlist2; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }
    printf("III)\n");
    for (p = nvlist3; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }

    freeall(nvlist1);
    freeall(nvlist2);
    return 0;
}