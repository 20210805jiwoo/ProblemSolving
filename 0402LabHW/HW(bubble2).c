#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student {
	int id;
	int korean, english, math;
};
void BubbleSort(struct Student* arr, int n, int menu) {
	struct Student tmp;
	switch (menu) {
	case 1:
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j].korean < arr[j + 1].korean) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
		break;

	case 2:
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j].math < arr[j + 1].math) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j].english < arr[j + 1].english) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j].id > arr[j + 1].id) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
		break;
	}

	for (int i = 0; i < n; i++) {
		printf("학번 : %d	", arr[i].id);
		printf("영어 : %d	", arr[i].english);
		printf("수학 : %d	", arr[i].math);
		printf("국어 : %d\n", arr[i].korean);
	}
	printf("\n");
}
int main() {
	srand(time(NULL));
	int n;
	int menu = -1;
	printf("학생 수를 입력하세요 : ");
	scanf("%d", &n);

	struct Student* arr;
	arr = (struct Student*)malloc(sizeof(struct Student) * n);

	for (int i = 0; i < n; i++) {
		arr[i].id = (i + 1);
		arr[i].korean = rand() % 100 + 1;
		arr[i].english = rand() % 100 + 1;
		arr[i].math = rand() % 100 + 1;
	}
	for (int i = 0; i < n; i++) {
		printf("학번 : %d	", arr[i].id);
		printf("영어 : %d	", arr[i].english);
		printf("수학 : %d	", arr[i].math);
		printf("국어 : %d\n", arr[i].korean);
	}
	printf("\n");

	while (1) {
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		BubbleSort(arr, n, menu);
	}
	free(arr);
	return 0;
}