#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n)
{
	int cnt=0;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int num;
	scanf("%d", &num); // 몇 번째 사람인지 입력 받기

	int i = 1;
	int cnt = 0;
	int result = 0;

	while (cnt < num) {
		cnt = cnt + solution(3 * i);
		result = 3 * i;

		i++;
	}

	if (cnt > num) {
		for (int i = 0; i < cnt - num; i++) {
			result /= 10;
		}
	}

	printf("%d", result % 10);
	return 0;
}