#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(int* items, int n, int* bucket, int bucketSize, int k,int money) {
	int lastIndex, i, smallest;
	if (k == 0) {
		if (money == 0) {
			for (i = 0; i < bucketSize; i++) {
				printf("%d ", items[bucket[i]]);
			}
			printf("\n");
		}
		return;
	}
	lastIndex = bucketSize - k - 1;
	if (bucketSize == k) {
		smallest = 0;
	}
	else {
		smallest = bucket[lastIndex];
	}
	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, n, bucket, bucketSize, k - 1, money - items[i]);
	}
}

int main(void) {
	int items[] = { 10000,5000,1000 };
	int bucket[6];

	int money;
	scanf("%d", &money);

	for (int i = 0; i <= 6; i++) {
		pick(items, 3, bucket, i, i, money);
	}
	return 0;
}