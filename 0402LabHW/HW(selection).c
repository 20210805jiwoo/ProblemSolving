#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
	int id;
	int english;
	int math;
	int korean;
};

void selectionSort(struct Student* A, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		struct Student min = A[0];
		int min_idx = 0;
		for (j = 1; j < n - i; j++) {
			if (min.korean > A[j].korean) {
				min = A[j];
				min_idx = j;
			}
		}
		A[min_idx] = A[n - i - 1];
		A[n - i - 1] = min;
	}
}
int main()
{
	int n, i;
	struct Student* A;

	printf("학생 수 입력: ");
	scanf("%d", &n);
	if (n <= 0)
		return 0;

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

	for (i = 0; i < n; i++) {
		printf("학번: %2d\t영어: %2d\t수학: %2d\t국어: %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}
	printf("\n");

	selectionSort(A, n);

	for (i = 0; i < n; i++) {
		printf("학번: %2d\t영어: %2d\t수학: %2d\t국어: %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}
	printf("\n");

	free(A);
	return 0;
}
//국어 성적 기준으로 내림차순 정렬