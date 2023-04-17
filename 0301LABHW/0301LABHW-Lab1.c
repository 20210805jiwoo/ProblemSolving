#include <stdio.h>

void pick(char* ball, int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", ball[bucket[i]]);
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(ball, n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	char ball[] = "ABCDEFGH";
	int bucket[3];

	pick(ball, 8, bucket, 3, 3);
}