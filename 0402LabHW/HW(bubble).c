#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student {
	int id;
	int korean, english, math;
};
void BubbleSortDescendingByKorean(struct Student* arr, int n) {
	struct Student tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j].korean < arr[j + 1].korean) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	printf("************ 국어 성적으로 정렬 후 **********\n");
	for (int i = 0; i < n; i++) {
		printf("학번 : %d	", arr[i].id);
		printf("영어 : %d	", arr[i].english);
		printf("수학 : %d	", arr[i].math);
		printf("국어 : %d\n", arr[i].korean);
	}
}
void BubbleSortAscendingById(struct Student* arr, int n) {
	struct Student tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j].id > arr[j + 1].id) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	printf("************ 학번으로 정렬 후 **********\n");
	for (int i = 0; i < n; i++) {
		printf("학번 : %d	", arr[i].id);
		printf("영어 : %d	", arr[i].english);
		printf("수학 : %d	", arr[i].math);
		printf("국어 : %d\n", arr[i].korean);
	}
}

int main() {
	srand(time(NULL));
	int n, random;
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

	BubbleSortDescendingByKorean(arr, n);
	BubbleSortAscendingById(arr, n);

}