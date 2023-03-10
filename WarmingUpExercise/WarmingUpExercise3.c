#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int total(int n);

int main(void) {
	int num;
	while (1) {
		printf("Input a number(-1 for exit): ");
		scanf_s("%d", &num);
		if (num == -1) {
			exit(1);
		}
		printf("1부터 %d까지의 합은 %d\n", num, total(num));
	}
	return 0;
}

int total(int n) {
	if (n == 1)
		return 1;
	else
		return (n + total(n - 1));
}