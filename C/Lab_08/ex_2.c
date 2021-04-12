#include <stdio.h>

void sort(double *pa, double *pb);

int main(void) {
	double a, b;
	do {
		fseek(stdin, 0, SEEK_END); // buffer cleaning
		printf(" Enter a, b separated by a whitespace: ");
	} while (scanf("%lf %lf", &a, &b) != 2);
	sort(&a, &b);
	printf(" %f, %f\n", a, b);
	printf(" %f, %f\n", b, a);
	return 0;
}
void sort(double *pa, double *pb) {
	if (*pa > *pb) {
		double t = *pa;
		*pa = *pb;
		*pb = t;
	}
}