#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
현재 위치에서 그 이하의 배열(앞쪽에 이미 정렬된 배열)비교해 자신이 들어갈 위치 찾아 정렬
*/
void insertionSort(int* A, int n) {
	int i, j, k, tmp;
	for (i = 1; i < n; i++) {	//바깥 loop 배열 전체 순회
		for (j = 0; j < i; j++) {	//최대 내 앞에까지 비교 (현재 위치에서 앞쪽으로 가면서 내가 들어갈 위치 찾음)
			if (A[i] < A[j])	//나보다 큰 애 최초로 만나면
				break;
		} //j <- A[i]가 들어갈 위치  

		//그 위치에 나 삽입하려면 그 위치부터 현재위치까지의 모든 원소 오른쪽으로 한 칸씩 이동

		tmp = A[i];	//현재 삽입정렬이 수행되는 위치 i값 임시저장
		//  movement
		//	A[i] = A[i - 1];
		//	A[i - 1] = A[i - 2];
		//	...
		//	A[j + 1] = A[j];
		for (k = i; k > j; k--) {	//배열의 이동 구현 오른쪽으로 한 칸씩 이동
			A[k] = A[k - 1];	//비어있는 위치 만듦
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
내림차순
void insertionSort(int* A, int n) {
	int i, j, k, tmp;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (A[i] > A[j]) // A[i]가 A[j]보다 크면 자리 바꾸기
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