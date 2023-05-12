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
	printf("************ ���� �������� ���� �� **********\n");
	for (int i = 0; i < n; i++) {
		printf("�й� : %d	", arr[i].id);
		printf("���� : %d	", arr[i].english);
		printf("���� : %d	", arr[i].math);
		printf("���� : %d\n", arr[i].korean);
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
	printf("************ �й����� ���� �� **********\n");
	for (int i = 0; i < n; i++) {
		printf("�й� : %d	", arr[i].id);
		printf("���� : %d	", arr[i].english);
		printf("���� : %d	", arr[i].math);
		printf("���� : %d\n", arr[i].korean);
	}
}

int main() {
	srand(time(NULL));
	int n, random;
	printf("�л� ���� �Է��ϼ��� : ");
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
		printf("�й� : %d	", arr[i].id);
		printf("���� : %d	", arr[i].english);
		printf("���� : %d	", arr[i].math);
		printf("���� : %d\n", arr[i].korean);
	}

	BubbleSortDescendingByKorean(arr, n);
	BubbleSortAscendingById(arr, n);

}