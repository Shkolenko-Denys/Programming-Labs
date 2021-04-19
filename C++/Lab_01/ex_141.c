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
    if (abs(len(treep->left) - len(treep->right)) < 2) {
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
    if (check(treep))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
