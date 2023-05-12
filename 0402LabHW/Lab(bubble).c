#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int* A, int n)
{
	int i, j, tmp;
	for (i = 0; i < n - 1; i++) {	//처음부터 끝까지 인접한 두 원소 비교
		for (j = 0; j < n - 1 - i; j++) {	//정렬된 수(맨 오른쪽)제외
			if (A[j] > A[j + 1]) {
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}

int main() {
	int n, i;
	int* A;
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

	bubbleSort(A, n);

	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	free(A);
	return 0;
}