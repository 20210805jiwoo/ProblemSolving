#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int** M, int i, int j) {
	printf("<%d, %d>\n", i, j);
	if (i == 0 && j == 0) return m[i][j];
	else if (i == 0) {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, M, i, j - 1);

		return M[i][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, M, i - 1, j);
		return M[i - 1][j] + m[i][j];
	}
	else {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, M, i, j - 1);

		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, M, i - 1, j);

		return ((M[i][j - 1] < M[i - 1][j]) ? M[i][j - 1] : M[i - 1][j]) + m[i][j];
	}
}

int main() {
	int** m;
	int** M;
	int r, c;
	int i, j;

	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
		}
	printf("%d\n", matrixPath(m, M, r - 1, c - 1));
}