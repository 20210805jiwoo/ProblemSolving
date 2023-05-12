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
		printf("�й� : %d	", arr[i].id);
		printf("���� : %d	", arr[i].english);
		printf("���� : %d	", arr[i].math);
		printf("���� : %d\n", arr[i].korean);
	}
	printf("\n");
}
int main() {
	srand(time(NULL));
	int n;
	int menu = -1;
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
	printf("\n");

	while (1) {
		printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������) : ");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		BubbleSort(arr, n, menu);
	}
	free(arr);
	return 0;
}