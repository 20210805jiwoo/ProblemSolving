#define CRT_SECURE_NO_WARNINGS
#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];
#include <stdio.h>
void draw_tree(int row, int left, int right)	//중간위치 계산
{
	int mid;
	if (right - left < 2)	//영역 너무 작으면 그냥 복귀
		return;

	mid = (right + left) / 2;

	printf("**테스트 row=%d left=%d right=%d mid=%d\n", row, left, right, mid);
	printf("  (%d %d)에 X를 찍는다\n", row, mid);

	screen[row][mid] = 'X';
	draw_tree(row + 1, left, mid);	//왼쪽 영역
	draw_tree(row + 1, mid + 1, right);	//오른쪽 영역
}

void init(char s[][MAX_WIDTH])	//screen 문자열 초기화
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
			printf(" %c", s[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int width;
	init(screen);
	printf("Enter a width(<=70) of a screen:");
	scanf_s("%d", &width);

	draw_tree(0, 0, width - 1);
	display(screen, width);
}