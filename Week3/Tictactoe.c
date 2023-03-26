#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 3

int winCheck(int sum)
{
	if (sum == 3) {
		printf("Player X wins!\n");
		return 1;
	}
	else if (sum == -3) {
		printf("Player O wins!\n");
		return 1;
	}
	return 0;
}

int win(char b[][BOARD_SIZE])
{
	int r, c;
	int sum;
	//가로
	for (r = 0; r < BOARD_SIZE; r++) {
		sum = 0;	//매번 초기화
		for (c = 0; c < BOARD_SIZE; c++)
			sum += b[r][c];

		if (winCheck(sum))
			return 1;
	}
	//세로
	for (c = 0; c < BOARD_SIZE; c++) {
		sum = 0;	//매번 초기화
		for (r = 0; r < BOARD_SIZE; r++)
			sum += b[r][c];

		if (winCheck(sum))
			return 1;
	}
	//대각선
	sum = 0, c = 0;
	for (r = 0; r < BOARD_SIZE; r++) {
		sum += b[r][c];
		c++;
	}
	if (winCheck(sum))
		return 1;
	//백대각선
	sum = 0;
	for (r = 0; r < BOARD_SIZE; r++)
	{
		sum += b[r][BOARD_SIZE - 1 - r];
	}
	if (winCheck(sum))
		return 1;

	return 0;
}

void display(char b[][BOARD_SIZE])
{
	char ch;
	int i, j;
	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%d |", i);
		for (j = 0; j < BOARD_SIZE; j++) {
			if (b[i][j] == 1)
				ch = 'X';
			else if (b[i][j] == -1)
				ch = 'O';
			else
				ch = ' ';
			printf(" %c", ch);
		}
		printf("\n");
	}
}

int main(void)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';

	int one, two;
	int i, j;
	int cnt, lose;

	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';
	cnt = 1;
	display(board);

	do {
		printf("Player %c(행 열):", turn);
		scanf_s("%d %d", &one, &two);

		if (turn == 'X') {
			board[one][two] = 1;
			turn = 'O'; //턴을 바꿔줌
		}
		else {
			board[one][two] = -1;
			turn = 'X';
		}
		display(board);
		lose = !win(board);
		cnt++;

	} while (lose && cnt <= BOARD_SIZE* BOARD_SIZE);

	if (cnt > 9)
		printf("Nobody wins!\n");

	return 0;
}