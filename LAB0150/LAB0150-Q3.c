#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int generate_number_ones(int nlen)
{
    int r = 0;
    int i;
    for (i = 0; i < nlen; i++) {
        r = r * 10 + 1;
    }
    return r;
}

int main(void)
{
    int num_ones = 0;
    int num, i = 1;
    scanf_s("%d", &num);

    while (1) {
        num_ones = generate_number_ones(i);
        if (num_ones % num == 0) {
            break;
        }
        i++;
    }
    printf("%d\n", i);
}
