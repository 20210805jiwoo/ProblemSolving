#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char num[1000];

	printf("���� �Է��ϼ���: ");
	scanf("%s", num);

	int len = strlen(num);
	int a = num[len - 1] - '0';	
	/*num[len - 1] : ������ ������ �ڸ���, �ƽ�Ű������ �����
	- '0' �ؼ� ���ڷ� ��ȯ�ؾ���
	ex) 5�� �ƽ�Ű ��:53 / 53 - 48(0�� �ƽ�Ű��) = 5
	*/
	if (a % 2 == 0)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}