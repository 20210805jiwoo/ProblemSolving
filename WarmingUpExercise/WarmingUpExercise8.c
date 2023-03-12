#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input(char name[]) {
	printf("Enter your name: ");
	fgets(name, 50, stdin);
}

void reverse(char name[]) {
	int i;
	printf("Reverse: ");
	for (i = strlen(name) - 1; i >= 0; i--) {
		printf("%c", name[i]);
	}
}

int main(void)
{
	char name[50];

	input(name);
	reverse(name);

	return 0;
}