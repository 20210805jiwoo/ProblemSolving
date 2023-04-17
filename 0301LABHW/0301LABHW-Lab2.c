#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char* actor[], int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%10s ", actor[bucket[i]]);
		}
		printf("\n");
		return;
	}

	//recursive case
	lastIndex = bucketSize - k - 1;
	if (bucketSize==k) 
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(actor, n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	int num;
	printf("인기상 몇명? ");
	scanf("%d", &num);
	char* actor[] = { "공유","김수현","송중기","지성","현빈" };
	int bucket[3];
	pick(actor, 5, bucket, 3, 3);
	return 0;
}