#include <stdio.h>
#define PI 3.14

void area_len(double *pr);

int main(void) {
	double r;
	do {
		fseek(stdin, 0, SEEK_END); // buffer cleaning
		printf(" Enter radius: ");
	} while (scanf("%lf", &r) != 1 || r <= 0);
	area_len(&r);
	return 0;
}
void area_len(double *pr) {
	double s = PI * (*pr) * (*pr),
		len = 2 * PI * (*pr);
	printf(" Area: %.2f\n", s);
	printf(" Length: %.2f\n", len);
}
