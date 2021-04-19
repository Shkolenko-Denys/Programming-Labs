#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NHASH 11
typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int value;
    Nameval *next;
};
Nameval *symtab[NHASH];

enum { MULTIPLIER=31 };
/* hash: compute hash value of string */
unsigned int hash(char *str) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *) str; *p != '\0'; p++) {
        h = MULTIPLIER*h + *p;
    }
    return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Nameval* lookup(char *name, int create, int value) {
    Nameval *sym;
    int h = hash(name);
    for (sym = symtab[h]; sym!=NULL; sym=sym->next)
        if (strcmp(name, sym->name) == 0)
            return sym;
    if (create) {
        sym = (Nameval *) malloc(sizeof(Nameval));
        sym->name = name; /* assumed allocated elsewhere */
        sym->value = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

int main(void) {
    Nameval *node = lookup("Billy", 1, 12);
    printf ("%s %d\n", node->name, node->value);
    return 0;
}