#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);

	int result = n * 9;
	int arr[100];	//�� �ڸ������� �����ϱ� ���� �迭
	int i = 0;

	while (result > 0) {
		arr[i] = result % 10;
		result /= 10;
		i++;	//i�� 1 �������� ���� �ڸ����� ������ �迭 arr�� �ε��� ����
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%d ", arr[j]);
	}

	return 0;
}