#include<stdio.h>

void pick(int n, int picked[], int m, int toPick) {
    int i;
    int lastIndex;
    int smallest;

    if (toPick == 0) {  //고를 것이 없으면 출력
        for (i = 0; i < m; i++) {
            printf("%d ", picked[i]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1; //picked array에서 마지막에 채워진 element의 index

    if (m == toPick)    //처음 고르는거면
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(n, picked, m, toPick - 1);
    }

}

int main() {
    int picked[4];
    pick(7, picked, 4, 4);
}