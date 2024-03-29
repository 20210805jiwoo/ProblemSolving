#include <stdio.h>

#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];

int cnt = 0;

void draw_tree(int row, int left, int right)
{
    int mid;
    if (right - left < 2) return;

    mid = (right + left) / 2;

    screen[row][mid] = ++cnt;
    draw_tree(row + 1, left, mid); // 왼쪽 영역
    draw_tree(row + 1, mid + 1, right); // 오른쪽 영역
}

void init(char s[][MAX_WIDTH])
{
    int i, j;
    for (i = 0; i < MAX_LEVEL; i++)
        for (j = 0; j < MAX_WIDTH; j++)
            s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width)
{
    int i, j;
    for (i = 0; i < MAX_LEVEL; i++) {
        for (j = 0; j < width; j++)
            if (s[i][j] == '-')
                printf(" %c", s[i][j]);
            else
                printf(" %d", s[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int width;
    init(screen);
    printf("Enter a width(<= 70) of a screen:");
    scanf_s("%d", &width);
    draw_tree(0, 0, width - 1);
    display(screen, width);
}