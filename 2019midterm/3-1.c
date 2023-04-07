#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int solution(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n = n / 10;
		++cnt;
	}
	printf("%d", cnt);

	return 0;
}

int main(void)
{
	int num;
	printf("숫자 입력: ");
	scanf("%d", &num);
	solution(num);
}