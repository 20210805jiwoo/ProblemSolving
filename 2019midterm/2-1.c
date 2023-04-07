#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char num[1000];

	printf("숫자 입력하세요: ");
	scanf("%s", num);

	int len = strlen(num);
	int a = num[len - 1] - '0';	
	/*num[len - 1] : 숫자의 마지막 자리수, 아스키값으로 저장됨
	- '0' 해서 숫자로 변환해야함
	ex) 5의 아스키 값:53 / 53 - 48(0의 아스키값) = 5
	*/
	if (a % 2 == 0)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}