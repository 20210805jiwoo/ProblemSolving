#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i, cnt = 0, str[5], key;
	printf("Enter 5���� ����: ");
	for (i = 0; i < 5; i++) {
		scanf_s("%d", &str[i]);
	}

	printf("Enter a key: ");
	scanf_s("%d", &key);

	for (i = 0; i < 5; i++) {
		if (str[i] == key) {
			cnt = 1;
			break;
		}
	}
	if (cnt) {
		printf("%d��°�� �ִ�", i + 1);
	}
	else {
		printf("����");
	}
	return 0;
}

