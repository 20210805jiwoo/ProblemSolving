#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[])
{
	int len = strlen(src_s);
	for (int i = 0; i < len; i++) {
		s[i] = src_s[len - 1 - i];	//���������� �ϳ��� �����ͼ� ���ο� �迭�� ����
	}
	s[len] = '\0';	//null���� �߰��ؼ� ���ڿ��� �� ǥ��
}

int main(void)
{
	char src_s[101];
	char s[101];

	scanf("%s", src_s);
	reverse(src_s, s);
	printf("%s\n", s);
}