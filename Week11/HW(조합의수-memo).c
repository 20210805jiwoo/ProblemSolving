#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, int** memo)
{
	if (r == 0 || n == r)
		return 1;
	else
	{
		if (memo[n - 1][r - 1] == 0)
			memo[n - 1][r - 1] = comb(n - 1, r - 1, memo);
		if (memo[n - 1][r] == 0)
			memo[n - 1][r] = comb(n - 1, r, memo);

		memo[n][r] = memo[n - 1][r - 1] + memo[n - 1][r];

		return memo[n][r];
	}
}

int main(void)
{
	int n, r, C, i, j;
	int** memo;

	scanf("%d %d", &n, &r);

	memo = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i <= n; i++)
		memo[i] = (int*)malloc(sizeof(int) * (r + 1));

	for (i = 0; i <= n; i++)
		for (j = 0; j <= r; j++)
			memo[i][j] = 0;

	C = comb(n, r, memo);
	printf("%d\n", C);

	// 동적으로 할당된 메모리 해제
	for (i = 0; i <= n; i++)
		free(memo[i]);
	free(memo);

	return 0;
}
