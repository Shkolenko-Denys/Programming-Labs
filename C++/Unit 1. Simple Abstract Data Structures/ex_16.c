#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int value;
    Nameval *left; /* lesser */
    Nameval *right; /* greater */
};

/* insert: insert newp in treep, return treep */
Nameval *insert(Nameval *treep, Nameval *newp) {
    if (treep == NULL)
        return newp;
    int cmp = strcmp(newp->name, treep->name);
    if (cmp == 0)
        printf("insert: duplicate entry %s ignored", newp->name);
    else if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else
        treep->right = insert(treep->right, newp);
    return treep;
}

/* applyinorder: in-order application of fn to treep */
void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg) {
    if (treep == NULL)
        return;
    applyinorder(treep->left, fn, arg);
    (*fn)(treep, arg);
    applyinorder(treep->right, fn, arg);
}

/* applypostorder: post-order application of fn to treep */
void applypostorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg) {
    if (treep == NULL)
        return;
    applypostorder(treep->left, fn, arg);
    applypostorder(treep->right, fn, arg);
    (*fn)(treep, arg);
}
/* printnv: print name and value using format in arg */
void printnv(Nameval *p, void *arg) {
    char *fmt;
    fmt = (char *) arg;
    printf(fmt, p->name, p->value);
}

int main(void) {
    Nameval *treep = NULL;
    treep = insert(treep, &(struct Nameval){.name="milk", .value=18});
    treep = insert(treep, &(struct Nameval){.name="house", .value=20});
    treep = insert(treep, &(struct Nameval){.name="summer", .value=50});
    treep = insert(treep, &(struct Nameval){.name="cat", .value=60});
    treep = insert(treep, &(struct Nameval){.name="kite", .value=10});
    treep = insert(treep, &(struct Nameval){.name="queen", .value=11});
    treep = insert(treep, &(struct Nameval){.name="umbrella", .value=12});
    applyinorder(treep, printnv, "%s: %d\n"); /* симетричне застосування функції fn до treep */
    return 0;
}
