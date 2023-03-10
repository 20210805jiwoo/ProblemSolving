#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int i, num;
	int result = 1;
	printf("Enter a number: ");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		result *= 2;
	}

	printf("%d", result);
}