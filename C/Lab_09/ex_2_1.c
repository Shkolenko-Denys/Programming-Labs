#include <stdio.h>
#include <ctype.h>
#define SIZE 100
int main(void) {
	char text[SIZE];
	printf("Enter text: ");
	gets(text);
	int i = 0;
	while (*(text + i) != '\0') {
		if (isdigit(*(text + i)) || ispunct(*(text + i))) {
			for (int j = i; *(text + j) != '\0'; j++) {
				*(text + j) = *(text + j + 1);
			}
			i--;
		}
		i++;
	}
	printf("Result: %s\n", text);
	return 0;
}