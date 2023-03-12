#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void echo(int a[], int size) {
	int i;
	printf("5개의 정수 입력: ");
	for (i = 0; i < size; i++) {
		scanf_s("%d", &a[i]);
		printf("%d ", a[i]);
	}
}

void reverse(int a[],int size) {
	int i;
	for (i = 4; i >= 0; i--) {
		printf("%d ", a[i]);
	}
}

int main(void)
{
	int num[5];
	echo(num,5);
	printf("\n");
	reverse(num,5);
	return 0;
}