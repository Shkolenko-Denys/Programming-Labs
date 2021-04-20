#include <stdio.h>
#include <stdlib.h>

typedef struct TypeList TypeList;
struct TypeList {
    void *data;
    void *data1;
    void *data2;
    TypeList *next; // next in the list
};

int main (void) {
    TypeList *data_list = NULL;
    return 0;
}