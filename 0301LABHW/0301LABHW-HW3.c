#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int item[], int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, sum = 0;
	if (k == 0)
	{
		for (i = 0; i < bucketSize; i++) {
			sum += item[bucket[i]]; //그 줄의 합 구하기
		}
		if (sum == (1000 * bucketSize))  //구해놓은 합이 입력값과 동일시
		{
			for (i = 0; i < bucketSize; i++) {
				if (item[bucket[i]] == 0)   //0이면 출력X
					continue;
				printf("%d ", item[bucket[i]]); //아니면 출력
			}
			printf("\n");
		}
		sum = 0;
		return;
	}
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	int item[] = { 0, 1000,5000,10000 };
	int money;
	printf("입력 : ");
	scanf("%d", &money);
	int num = money / 1000;

	int* bucket = (int*)malloc(sizeof(int) * num);
	pick(item, 4, bucket, num, num); // 중복포함

	free(bucket);
	return 0;
}
