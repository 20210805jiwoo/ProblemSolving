#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H(int n, int* memo)
{
	int result = 0;
	if (n == 0 || n == 1)
		return 1;
	if (memo[n] != 0)
		return memo[n];
	for (int i = 0; i < n; i++)
		result += H(i, memo) * H(n - 1 - i, memo);
	memo[n] = result;

	return memo[n];
}

int main(void)
{
	int n, i;
	int* memo;
	printf("0보다 큰 정수: ");
	scanf("%d", &n);

	memo = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n + 1; i++)
		memo[i] = 0;

	printf("결과는 %d\n", H(n,memo));
	free(memo);
	return 0;
}