#include <stdio.h>
int H(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum = sum + H(i) * (n - i - 1);
		return sum;
	}
}
int main(void)
{
	int n = 10;
	printf("%d", H(n));

	return 0;
}
