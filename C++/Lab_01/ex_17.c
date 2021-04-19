#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

/* lookup: look up name in tree treep */
Nameval *lookup(Nameval *treep, char *name) {
    if (treep == NULL)
        return NULL;
    int cmp = strcmp(name, treep->name);
    if (cmp == 0)
        return treep;
    else if (cmp < 0)
        return lookup(treep->left, name);
    else
        return lookup(treep->right, name);
}

/* nrlookup: non-recursively look up name in tree treep */
Nameval *nrlookup(Nameval *treep, char *name) {
    while (treep != NULL) {
        int cmp = strcmp(name, treep->name);
        if (cmp == 0)
            return treep;
        else if (cmp < 0)
            treep = treep->left;
        else
            treep = treep->right;
    }
    return NULL;
}

/* applyinorder: in-order (cuvivieTpuMhoe) application of fn to treep */
void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg) {
    if (treep == NULL)
        return;
    applyinorder(treep->left, fn, arg);
    (*fn)(treep, arg);
    applyinorder(treep->right, fn, arg);
}

/* applypostorder: post-order (KomjeBoii) application of fn to treep */
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

int len(Nameval * tree) {
    int length;
    if (!tree)
        return 0;
    if (len(tree->left) >= len(tree->right)) {
        length = len(tree->left);
    } else {
        length = len(tree->right);
    }
    return length + 1;
}

int check(Nameval *treep){
    if (!treep) {
        return 1;
    }
    if (abs(len(treep->left) - len(treep->right)) < 3) {
        int l = check(treep->left);
        int r = check(treep->right);
        if (l && r)
            return 1;
    }
    return 0;
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
    if (check(treep)) {
        printf("This tree is balance\n");
    }
    else {
        printf("This tree is not balance\n");
    }
    double start = clock();
    lookup(treep, "zoo");
    printf("Time for recursive version - %.13lf\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    start = clock();
    nrlookup(treep, "zoo");
    printf("Time for iterative version - %.13lf\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    applyinorder(treep, printnv, "%s: %d\n");
    putchar('\n');
    applypostorder(treep, printnv, "%s: %d\n");
    return 0;
}
