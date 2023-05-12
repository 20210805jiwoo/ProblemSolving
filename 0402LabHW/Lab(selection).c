#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int* A, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int max = A[0];	//array�� ù ��° �� �־���
		int max_idx = 0;
		for (j = 1; j < n - i; j++) {
			if (max < A[j]) {
				max = A[j];	//max ����
				max_idx = j; //max_idx�� ����
			}
		}
		//A[max_idx](���� ���� ū ��) <-> A[n-i-1](���� ������ ��)
		A[max_idx] = A[n - i - 1]; //���� ������ �� max�� �ְ�
		A[n - i - 1] = max; //temp �ʿ���� ����: max�� �̹� ����
	}
}

int main() {
	int n, i;
	int* A;
	scanf("%d", &n);

	if (n <= 0)	//����üũ
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));	//�Ź� �ٸ� seed
	//srand(303); ���� �翬�ϱ� ����

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