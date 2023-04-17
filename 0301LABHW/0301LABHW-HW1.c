#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(int* ball, int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%d ", ball[bucket[i]]);
		}
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (i = 0; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(ball, n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	int ball[4] = { 0,1,2,3 };
	int bucket[3];

	pick(ball, 4, bucket, 3, num);
	return 0;
}