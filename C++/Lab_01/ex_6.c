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

int addname(Nameval newname) {
    Nameval *nvp;
    if (nvtab.nameval == NULL) { /* first time */
        nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { /* grow */
        nvp = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max)*sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

int delname(char *name) {
    for (int i=0; i<nvtab.nval; i++) {
        if (strcmp(nvtab.nameval[i].name, name) == 0) {
            nvtab.nameval[i].name = NULL;
            // nvtab.nval--;
            return 1;
        }    
    }
    return 0;
}

int main(void) {
    addname((struct Nameval) {.name="Andy", .value=12});
    addname((struct Nameval) {.name="Billy", .value=18});
    addname((struct Nameval) {.name="Bob", .value=19});
    for (int i=0; i<nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }
    
    printf("\t[Delete \"Billy\"...]\n");

    if(delname("Billy")) {
        for (int i=0; i<nvtab.nval; i++) {
            printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
        }
    }
    free(nvtab.nameval);
    nvtab.nameval = NULL;
    return 0;
}