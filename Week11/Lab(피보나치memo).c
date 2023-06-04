#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int n, int* F) {
	if (n <= 2)
		return 1;
	else {
		if (F[n] == 0) {
			F[n] = fib(n - 1, F) + fib(n - 2, F);
		}
		return F[n];
	}
}
int main(void) {
	int n, i;
	int* F;

	printf("몇 번째까지의 피보나치 수열 : ");
	scanf("%d", &n);

	F = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++) {
		F[i] = 0;
	}
	fib(n, F);
	for (i = 1; i <= n; i++) {
		printf("%3d", fib(i, F));
	}
	free(F);
}