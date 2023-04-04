#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int calculateReverse(int n)
{
	int r = 0;	//뒤집은 결과 정수

	while (n != 0) {
		r = r * 10;
		r = r + n % 10;
		n = n / 10;
	}
	return r;
}

int main(void)
{
	int num1, num2, input_num;
	int cnt = 0;

	scanf_s("%d", &input_num);
	num1 = input_num;

	num2 = calculateReverse(input_num);
	while (num1 != num2) {
		cnt++;
		num1 = num2 + num1;
		num2 = calculateReverse(num1);

		if (cnt > 1000) {
			printf("NaN\n");
			return 0;
		}
	}
	printf("%d %d\n", cnt, num1);

	return 0;
}
