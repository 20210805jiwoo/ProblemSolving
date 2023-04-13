#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[])
{
	int len = strlen(src_s);
	for (int i = 0; i < len; i++) {
		s[i] = src_s[len - 1 - i];	//끝에서부터 하나씩 가져와서 새로운 배열에 저장
	}
	s[len] = '\0';	//null문자 추가해서 문자열의 끝 표시
}

int main(void)
{
	char src_s[101];
	char s[101];

	scanf("%s", src_s);
	reverse(src_s, s);
	printf("%s\n", s);
}