#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char* actor[], int n, int* bucket, int bucketSize, int k)
{
	int i, smallest, lastIndex;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%10s ", actor[bucket[i]]);
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (i = smallest; i < n; i++) {
		int j = 0; int flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (bucket[j] == i) flag = 1;
		if (flag == 1)
			continue;

		bucket[lastIndex + 1] = i;
		pick(actor, n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	int num;
	printf("상의 종류는? ");
	scanf("%d", &num);
	printf("\t상 1\t상 2\n");

	int bucket[2];
	char* actor[5] = { "공유","김수현","송중기","지성","현빈" };
	pick(actor, 5, bucket, 2, 2);

	return 0;
}