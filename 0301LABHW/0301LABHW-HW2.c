#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, total = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			if (bucket[i] == 0) {
				printf("+%d", i + 1);
				total += (i + 1);
			}
			else {
				printf("-%d", i + 1);
				total -= (i + 1);
			}
		}
		printf(" = %d\n", total);
		return;
	}
	lastIndex = bucketSize - k - 1;	//가장 최근에 뽑힌 수가 저장된 위치 index
	smallest = 0;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	int num;
	int* bucket;
	scanf("%d", &num);
	bucket = (int*)malloc(sizeof(int) * num);

	pick(2, bucket, num, num);
	free(bucket);
	return 0;
}