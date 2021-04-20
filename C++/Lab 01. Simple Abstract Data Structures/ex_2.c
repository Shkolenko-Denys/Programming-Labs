#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval; /* присвоїли існуючому типу данних нове ім'я */

struct Nameval {
    char *name;
    int value;
};

struct NVtab {
    int nval; /* current number of values */
    int max; /* allocated number of values */
    Nameval *nameval; /* array of name-value pairs */
} nvtab; /* nvtab екземпляр структури */

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
    // struct NVtab nvtab; /* як варіант, можемо оголосити nvtab в функції main, а не глобально */
    // nvtab.nameval = NULL;
    // int curnum;
    /* далі передаємо адресу структури, а не саму структуру, оскільки нам потрібно, щоб функції вносили зміни */
    addname((struct Nameval) {.name="Andy", .value=12}, &nvtab);
    // printf("curnum %d\n", curnum);
    addname((struct Nameval) {.name="Billy", .value=18}, &nvtab);
    // printf("curnum %d\n", curnum);
    addname((struct Nameval) {.name="Bob", .value=19}, &nvtab);
    // printf("curnum %d\n", curnum);
    for (int i=0; i<nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    printf("\t[Delete \"Billy\"...]\n");

    if(delname("Billy", &nvtab)) {
        for (int i=0; i<nvtab.nval; i++) {
            printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
        }
    }
    
    free(nvtab.nameval); /* звільняємо пам'ять, що виділялась динамічно */
    nvtab.nameval = NULL;
    return 0;
}