#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand((unsigned)time(NULL));
	int i, num;
	char ch;

	printf("*** �ζ� ��ȣ ������ ***\n");

	while (1) {
		printf("���� ��ȣ: ");
		for (i = 0; i < 6; i++) {
			printf("%d ", (rand() % 45) + 1);
		}
		printf("\n�ٽ� �����ϰڽ��ϱ�? (y/n): ");
		scanf_s(" %c", &ch);

		if (ch == 'n') {
			break;
		}
	}
	return 0;
}