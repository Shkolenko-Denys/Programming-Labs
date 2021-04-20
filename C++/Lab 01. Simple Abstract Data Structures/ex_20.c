#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NHASH 5
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
    lookup("аваіваі", 1, 12);
    lookup("івівап", 1, 13);
    lookup("іаіваі", 1, 14);
    lookup("іаваіа", 1, 15);
    lookup("уееук", 1, 16);
    lookup("впівпва", 1, 17);
    lookup("hнеш", 1, 17);
    lookup("hіаііа", 1, 17);
    lookup("ййцуц", 1, 17);
    lookup("hссчмм", 1, 17);
    lookup("йцуцк", 1, 17);
    lookup("hисис", 1, 17);
    lookup("нгшне", 1, 17);
    for (int i = 0; i < NHASH; i++) {
        for (p = symtab[i]; p != NULL; p = p->next) {
            printf("%d) %s %d\n", i, p->name, p->value);
        }
    }
    return 0;
}