#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);

	int result = n * 9;
	int arr[100];	//각 자릿수별로 저장하기 위한 배열
	int i = 0;

	while (result > 0) {
		arr[i] = result % 10;
		result /= 10;
		i++;	//i를 1 증가시켜 다음 자릿수를 저장할 배열 arr의 인덱스 지정
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%d ", arr[j]);
	}

	return 0;
}