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

int main (void) {
    Nameval *p = NULL;
    lookup("httpsssssssssa", 1, 12);
    lookup("httpsssssssssb", 1, 13);
    lookup("httpsssssssssc", 1, 14);
    lookup("httpsssssssssd", 1, 15);
    lookup("httpssssssssse", 1, 16);
    lookup("httpsssssssssf", 1, 17);
    lookup("httpsssssssssg", 1, 17);
    lookup("httpsssssssssk", 1, 17);
    lookup("httpsssssssssl", 1, 17);
    lookup("httpsssssssssm", 1, 17);
    lookup("httpsssssssssn", 1, 17);
    lookup("httpssssssssso", 1, 17);
    lookup("httpsssssssssp", 1, 17);
    for (int i = 0; i < NHASH; i++) {
        for (p = symtab[i]; p != NULL; p = p->next) {
            printf("%d) %s %d\n", i, p->name, p->value);
        }
    }
    return 0;
}