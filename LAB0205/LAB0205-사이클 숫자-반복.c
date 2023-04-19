#include <stdio.h>
int get_cycle_number(int n)
{
	int r = 1;

	while (n != 1) {
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;
		r++;
	}	
	return r;
}

int main(void)
{
	int n = 22;

	printf("%d\n", get_cycle_number(n));

	return 0;
}
