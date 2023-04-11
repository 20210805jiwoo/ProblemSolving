#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1, num2, carry = 0, carry_cnt = 0;
	int r1, r2;

	scanf("%d %d", &num1, &num2);

	while (num1 != 0 || num2 != 0) {
		r1 = num1 % 10;
		r2 = num2 % 10;

		if (r1 + r2 + carry >= 10) {	//자리올림 발생
			carry = 1;
			carry_cnt++;
		}
		else {
			carry = 0;
		}
		num1 = num1 / 10;	//다음 자리수 계산
		num2 = num2 / 10;
	}
	printf("%d\n", carry_cnt);
	return 0;
}
