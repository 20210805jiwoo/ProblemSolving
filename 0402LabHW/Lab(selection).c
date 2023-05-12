#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int* A, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int max = A[0];	//array의 첫 번째 값 넣어줌
		int max_idx = 0;
		for (j = 1; j < n - i; j++) {
			if (max < A[j]) {
				max = A[j];	//max 갱신
				max_idx = j; //max_idx도 갱신
			}
		}
		//A[max_idx](현재 가장 큰 값) <-> A[n-i-1](가장 오른쪽 값)
		A[max_idx] = A[n - i - 1]; //가장 오른쪽 값 max에 넣고
		A[n - i - 1] = max; //temp 필요없는 이유: max에 이미 저장
	}
}

int main() {
	int n, i;
	int* A;
	scanf("%d", &n);

	if (n <= 0)	//에러체크
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));	//매번 다른 seed
	//srand(303); 에러 재연하기 위해

	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	selectionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;
}