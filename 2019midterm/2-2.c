#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char num[1000];
	scanf("%s", num);

	int len = strlen(num);
	int ten = num[len - 2] - '0';
	int one = num[len - 1] - '0';
	//2�ǹ��
	if (one % 2 == 0)
		printf("1");
	else
		printf("0");

	//3�ǹ��
	long long int sum = 0;
	for (int i = 0; num[i] != '\0'; i++) {
		sum += num[i] - '0';
	}
	if (sum % 3 == 0)
		printf("1");
	else
		printf("0");

	//4�ǹ��
	if ((ten * 10 + one) % 4 == 0)
		printf("1");
	else
		printf("0");

	//5�ǹ��
	if (one == 0 | one == 5)
		printf("1");
	else
		printf("0");

	return 0;
}