#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
};

struct NVtab {
    int nval;
    int max;
    Nameval *nameval;
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
            *(p->nameval + i) = *(p->nameval + p->nval-1);
            p->nval--;
            return 1;
        }    
    }
    return 0;
}

int main(void) {
    addname((struct Nameval) {.name="Andy", .value=12}, &nvtab);
    addname((struct Nameval) {.name="Billy", .value=18}, &nvtab);
    addname((struct Nameval) {.name="Fred", .value=17}, &nvtab);
    addname((struct Nameval) {.name="Ivan", .value=17}, &nvtab);
    addname((struct Nameval) {.name="Bob", .value=19}, &nvtab);
    for (int i=0; i<nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }
    
    printf("\t[Delete \"Billy\"...]\n");

    if(delname("Billy", &nvtab)) {
        for (int i=0; i<nvtab.nval; i++) {
            printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
        }
    }
    free(nvtab.nameval);
    nvtab.nameval = NULL;
    return 0;
}