#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};

int partition(struct Student* A, int left, int right, int menu) {
	int i, j;
	i = left - 1;
	struct Student tmp;
	switch (menu) {
	case 1:
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
		break;
	case 2:
		for (j = left; j < right; j++) {
			if (A[j].math > A[right].math) {
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
		break;
	case 3:
		for (j = left; j < right; j++) {
			if (A[j].english > A[right].english) {
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
		break;
	case 4:
		for (j = left; j < right; j++) {
			if (A[j].id < A[right].id) {
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
		break;
	}
}

void quickSort(struct Student* A, int left, int right, int menu) {
	if (left < right) {
		int mid = partition(A, left, right, menu);
		quickSort(A, left, mid - 1, menu);
		quickSort(A, mid + 1, right, menu);
	}
}

int main() {
	struct Student* A;
	int i, n;
	int menu = -1;

	printf("학생 수를 입력하세요: ");
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

	while (1)
	{
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
		scanf("%d", &menu);
		if (menu == 0)
			break;

		quickSort(A, 0, n - 1, menu);

		for (i = 0; i < n; i++)
			printf("학번: %2d\t영어: %2d\t수학: %2d\t국어: %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
		printf("\n");
	}

	free(A);
	return 0;
}