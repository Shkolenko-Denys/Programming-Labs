#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1
#define GROW 2

unsigned int nhash = 5;

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next;
};
Nameval **symtab = NULL;

enum { MULTIPLIER=31 };
/* hash: compute hash value of string */
unsigned int hash(char *str) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *) str; *p != '\0'; p++) {
        h = MULTIPLIER*h + *p;
    }
    return h % nhash;
}

/* lookup: find name in symtab, with optional create */
Nameval* lookup(char *name, int create, int value) {
    Nameval *sym;
    Nameval *p;
    int counter = 1;
    int h = hash(name);
    for (sym = symtab[h]; sym!=NULL; sym=sym->next)
        if (strcmp(name, sym->name) == 0)
            return sym;
    if (create) {
        for (p = symtab[h]; p != NULL; p = p->next) {
            counter++;
        }
        if (counter > MAX) {
            nhash += GROW;
            symtab = (Nameval **) realloc(symtab, (nhash)*sizeof(Nameval*));
            sym = lookup(name, create, value);
        } else {
            sym = (Nameval *) malloc(sizeof(Nameval));
            sym->name = name; /* assumed allocated elsewhere */
            sym->value = value;
            sym->next = symtab[h];
            symtab[h] = sym;
        }
    }
    return sym;
}

int main (void) {
    symtab = calloc(nhash, sizeof(Nameval*));
    Nameval *p = NULL;
    lookup("milk", 1, 12);
    lookup("house", 1, 13);
    lookup("summer", 1, 14);
    lookup("cat", 1, 15);
    lookup("kite", 1, 16);
    lookup("queen", 1, 17);
    lookup("umbrella", 1, 17);
    printf("nhash = %d\n", nhash);
    for (int i = 0; i < nhash; i++) {
        for (p = symtab[i]; p != NULL; p = p->next) {
            printf("%d) %s %d\n", i, p->name, p->value);
        }
    }
    return 0;
}