#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* A, int left, int right) {
	int i, j;
	int tmp;

	i = left - 1;

	for (j = left; j < right; j++) {
		if (A[j] < A[right]) {
			i++;

			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	i++;
	tmp = A[i];
	A[i] = A[right];
	A[right] = tmp;
	return i;
}

void quickSort(int* A, int left, int right) {
	if (left < right) {
		int mid = partition(A, left, right);
		quickSort(A, right, mid - 1);
		quickSort(A, mid + 1, right);
	}
}

int main() {
	int* A;
	int i, n;

	scanf("%d", &n);
	if (n <= 0) {
		return 0;
	}

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL) {
		return 0;
	}

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i] = rand() % 1000;
	}

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	quickSort(A, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;
}