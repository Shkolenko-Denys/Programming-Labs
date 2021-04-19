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

int main(void) {
    Nameval *treep = NULL;
    treep = insert(treep, &(struct Nameval){.name="apple", .value=18});
    treep = insert(treep, &(struct Nameval){.name="cat", .value=20});
    treep = insert(treep, &(struct Nameval){.name="day", .value=50});
    treep = insert(treep, &(struct Nameval){.name="eyes", .value=60});
    treep = insert(treep, &(struct Nameval){.name="fish", .value=10});
    treep = insert(treep, &(struct Nameval){.name="house", .value=11});
    treep = insert(treep, &(struct Nameval){.name="zoo", .value=12});
    double start = clock();
    lookup(treep, "zoo");
    printf("Recursive version - %.13lf\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    start = clock();
    nrlookup(treep, "zoo");
    printf("Iterative version - %.13lf\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}