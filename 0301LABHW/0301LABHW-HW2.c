#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char* signs, int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex;
	int total = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%c ", signs[bucket[i]]);
			printf("%d ", i + 1);

			if (signs[bucket[i]] == '+')
				total += (i + 1);
			else
				total -= (i + 1);
		}
		printf(" = %d", total);
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;

	for (i = 0; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(signs, n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	char signs[] = "+-";
	int bucket[2];
	int num;
	printf("입력: ");
	scanf("%d", &num);

	pick(signs, 2, bucket, num, num);

	return 0;
}
