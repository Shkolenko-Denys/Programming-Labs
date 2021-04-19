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
            free(p);
            free(p->name);
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
        free(listp);
        free(listp->name);
    }
}
int main(void) {
    Nameval *nvlist1 = NULL;
    Nameval *nvlist2 = NULL;
    Nameval *nvlist3 = NULL;
    Nameval *newit1 = NULL;
    Nameval *newit2 = NULL;
    Nameval *p = NULL;
    nvlist1 = addfront(nvlist1, newitem("data11", 10));
    nvlist1 = addend(nvlist1, newitem("data12", 20));
    nvlist1 = addend(nvlist1, newitem("data13", 30));
    nvlist1 = addend(nvlist1, newitem("data14", 40));
    nvlist1 = addend(nvlist1, newitem("data15", 55));
    nvlist1 = addend(nvlist1, newitem("data16", 66));
    nvlist1 = addend(nvlist1, newitem("data17", 77));

    nvlist2 = addfront(nvlist2, newitem("data21", 10));
    nvlist2 = addend(nvlist2, newitem("data22", 20));
    nvlist2 = addend(nvlist2, newitem("data23", 30));
    nvlist2 = addend(nvlist2, newitem("data24", 40));
    nvlist2 = addend(nvlist2, newitem("data25", 55));
    nvlist2 = addend(nvlist2, newitem("data26", 66));
    nvlist2 = addend(nvlist2, newitem("data27", 77));

    newit1 = newitem("newdate1", 100);
    newit2 = newitem("newdate2", 200);
    addafter(nvlist1, "data13", newit1);
    addbefore(nvlist1, "data14", newit2);
    merge(nvlist1, nvlist2);
    nvlist3 = unmerge(nvlist1, "data15");
    copy(nvlist2, "data22");
    int n = 0;
    coolfun(nvlist1, inccounter, &n);
    printf("%d elements in nvlist1\n", n);
    delitem(nvlist2, "data23");
    nvlist1 = reverse_rec(nvlist1, NULL);
    reverse_it(nvlist3);
    delitem(nvlist1, "None");
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