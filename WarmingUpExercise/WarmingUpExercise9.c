#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int a[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		scanf_s("%d", &a[i]);
	}
}

int compare(int str1[], int str2[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (str1[i] != str2[i])
			return 0;
	}
	return 1;
}

int main(void)
{
	int str1[5], str2[5];

	printf("Enter ù��° �迭: ");
	input(str1, 5);

	printf("Enter �ι�° �迭: ");
	input(str2, 5);

	int c = compare(str1, str2, 5);
	if (c == 1)
		printf("�� ���� �迭�� ����");
	else
		printf("�� ���� �迭�� �ٸ���");
	return 0;
}