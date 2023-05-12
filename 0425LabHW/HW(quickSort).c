#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};

int partition(struct Student* A, int left, int right) {
	int i, j;
	struct Student tmp;

	i = left - 1;

	for (j = left; j < right; j++) {
		if (A[j].korean > A[right].korean) {
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

void quickSort(struct Student* A, int left, int right) {
	if (left < right) {
		int mid = partition(A, left, right);
		quickSort(A, right, mid - 1);
		quickSort(A, mid + 1, right);
	}
}

int main() {
	struct Student* A;
	int i, n;

	printf("학생 수 입력: ");
	scanf("%d", &n);
	if (n <= 0) {
		return 0;
	}

	A = (struct Student*)malloc(sizeof(struct Student) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i].id = i + 1;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
		A[i].korean = rand() % 101;
	}

	for (i = 0; i < n; i++)
		printf("학번: %2d\t영어: %2d\t수학: %2d\t국어: %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");

	quickSort(A, 0, n - 1);

	printf("************ 국어 성적으로 정렬 후 **********\n");
	for (i = 0; i < n; i++)
		printf("학번: %2d\t영어: %2d\t수학: %2d\t국어: %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");

	free(A);
	return 0;
}