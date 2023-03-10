#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, cnt = 0;
	char str[50], word;

	printf("Enter a String: ");
	gets_s(str, 50);

	printf("Enter a character: ");
	scanf_s("%c", &word);

	for (i = 0; str[i] != '\0'; i++) {
		if (word == str[i])
			cnt++;
	}

	printf("'%c' is appeared %d times", word, cnt);
	return 0;
}