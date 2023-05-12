#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, i;
	int* A;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n <= 0)
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		A[i] = rand() % 1000;
	}

	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

//n개의 정수의 난수 만들기