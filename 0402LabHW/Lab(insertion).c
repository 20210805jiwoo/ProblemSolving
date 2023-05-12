#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
���� ��ġ���� �� ������ �迭(���ʿ� �̹� ���ĵ� �迭)���� �ڽ��� �� ��ġ ã�� ����
*/
void insertionSort(int* A, int n) {
	int i, j, k, tmp;
	for (i = 1; i < n; i++) {	//�ٱ� loop �迭 ��ü ��ȸ
		for (j = 0; j < i; j++) {	//�ִ� �� �տ����� �� (���� ��ġ���� �������� ���鼭 ���� �� ��ġ ã��)
			if (A[i] < A[j])	//������ ū �� ���ʷ� ������
				break;
		} //j <- A[i]�� �� ��ġ  

		//�� ��ġ�� �� �����Ϸ��� �� ��ġ���� ������ġ������ ��� ���� ���������� �� ĭ�� �̵�

		tmp = A[i];	//���� ���������� ����Ǵ� ��ġ i�� �ӽ�����
		//  movement
		//	A[i] = A[i - 1];
		//	A[i - 1] = A[i - 2];
		//	...
		//	A[j + 1] = A[j];
		for (k = i; k > j; k--) {	//�迭�� �̵� ���� ���������� �� ĭ�� �̵�
			A[k] = A[k - 1];	//����ִ� ��ġ ����
		}
		A[j] = tmp;
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

	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	insertionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;
}
/*
��������
void insertionSort(int* A, int n) {
	int i, j, k, tmp;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (A[i] > A[j]) // A[i]�� A[j]���� ũ�� �ڸ� �ٲٱ�
				break;
		}
		tmp = A[i];
		for (k = i; k > j; k--) {
			A[k] = A[k - 1];
		}
		A[j] = tmp;
	}
}

*/