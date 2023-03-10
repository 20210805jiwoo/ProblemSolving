#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand((unsigned)time(NULL));
	int i, num;
	char ch;

	printf("*** 로또 번호 생성기 ***\n");

	while (1) {
		printf("생성 번호: ");
		for (i = 0; i < 6; i++) {
			printf("%d ", (rand() % 45) + 1);
		}
		printf("\n다시 생성하겠습니까? (y/n): ");
		scanf_s(" %c", &ch);

		if (ch == 'n') {
			break;
		}
	}
	return 0;
}