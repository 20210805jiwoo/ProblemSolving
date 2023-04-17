#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int convert(int n, int k, int arr[])
{
	int i = 0;
	while (n > 0) {
		arr[i] = n % k;
		n /= k;
		i++;
	}
	return i;	//�迭 ����
}

int isPalindrome(int arr[], int len)
{
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len - i - 1])
			return 0;
	}
	return 1;
}

int main(void)
{
	int n, k;
	int arr[100];
	printf("�ڿ��� ���� �Է�: ");
	scanf("%d %d", &n, &k);

	int len = convert(n, k, arr);

	if (isPalindrome(arr, len)) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}