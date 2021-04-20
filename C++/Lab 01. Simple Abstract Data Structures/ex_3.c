#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
};

struct NVtab {
    int nval; // current number of values
    int max; // allocated number of values
    Nameval *nameval; // array of name-value pairs
} nvtab;

enum {NVINIT = 1, NVGROW = 2};

int addname(Nameval newname, struct NVtab *p) {
    Nameval *nvp;
    if (p->nameval == NULL) { /* first time */
        p->nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (p->nameval == NULL)
            return -1;
        p->max = NVINIT;
        p->nval = 0;
    } else if (p->nval >= p->max) { /* grow */
        nvp = (Nameval *) realloc(p->nameval, (NVGROW*p->max)*sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        p->max *= NVGROW;
        p->nameval = nvp;
    }
    p->nameval[p->nval] = newname;
    return p->nval++;
}
int delname(char *name, struct NVtab *p) {
    for (int i=0; i<p->nval; i++) {
        if (strcmp(p->nameval[i].name, name) == 0) {
            memmove(p->nameval + i, p->nameval+i+1, (p->nval-(i+1))*sizeof(Nameval));
            p->nval--;
            return 1;
        }    
    }
    return 0;
}

int main(void) {
    int curnum;
    curnum = addname((struct Nameval) {.name="Andy", .value=12}, &nvtab);
    printf("%d\n", curnum);
    Nameval *pnt = nvtab.nameval; // створюємо цей вказівник
    curnum = addname((struct Nameval) {.name="Billy", .value=18}, &nvtab);
    printf("%d\n", curnum);
    curnum = addname((struct Nameval) {.name="Bob", .value=19}, &nvtab);
    printf("%d\n", curnum);
    for (int i=0; i<nvtab.nval; i++) {
        printf("%s %d\n", (pnt+i)->name, (pnt+i)->value); /* звераємося через вказівник */
    }
    putchar('\n');

    if(delname("Billy", &nvtab)) {
        for (int i=0; i<nvtab.nval; i++) {
            printf("%s %d\n", (pnt+i)->name, (pnt+i)->value); /* звераємося через вказівник */
        }
    }
    free(nvtab.nameval);
    nvtab.nameval = NULL;
    return 0;
}