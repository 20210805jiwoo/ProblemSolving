#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* A, int left, int mid, int right, int* tmp) {
    int i, j, t;
    i = left;
    j = mid + 1;
    t = left;

    while (i <= mid && j <= right) {
        if (A[i] < A[j]) {
            tmp[t] = A[i];
            t++; i++;
        }
        else {
            tmp[t] = A[j];
            t++; j++;
        }
    }

    if (j > right) {
        for (; i <= mid; i++, t++)
            tmp[t] = A[i];
    }
    else {
        for (; j <= right; j++, t++) {
            tmp[t] = A[j];
        }
    }
    for (i = left; i <= right; i++)
        A[i] = tmp[i];
}

void mergeSort(int* A, int left, int right, int* tmp) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid, tmp);
        mergeSort(A, mid + 1, right, tmp);
        merge(A, left, mid, right, tmp);
    }
}

int main(void)
{
    int* A;
    int* tmp;
    int n, i;
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    A = (int*)malloc(sizeof(int) * n);
    tmp = (int*)malloc(sizeof(int) * n);
    if (A == NULL || tmp == NULL) {
        return 0;
    }
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        A[i] = rand() % 1000;
    }

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    mergeSort(A, 0, n - 1, tmp);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(tmp);
    free(A);
    return 0;
}
