#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H(int n) {
	int i = 0;
	int sum = 0;

	if (n == 0 || n == 1)
		return 1;
	for (i = 0; i < n; i++)
		sum = sum + H(i) * H(n - 1 - i);
	return sum;
}

int main() {
	int n;
	printf("0���� ū ����: ");
	scanf("%d", &n);
	printf("����� %d\n", H(n));
	return 0;
}