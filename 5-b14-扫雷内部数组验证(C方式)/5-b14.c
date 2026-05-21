/* 2550332 杨舸帆 交通 */

/* 2550625 安国优 2550322 陆迪缘 2551298 蔡鸿成 2553942 李旭 2550333 潘布*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // 10行
#define COLS 26 // 26列
#define MINE_CNT 50

// 计算某个位置周围8个方向的雷数(也即这个位置如果不是雷, 该显示什么数字)
int countMinesAround(char board[ROWS][COLS], int row, int col)
{
	int cnt = 0;

	// 8个方向的偏移量
	int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	for (int i = 0; i < 8; i++) {
		// 八个位置的坐标
		int nr = row + dr[i];
		int nc = col + dc[i];

		// 检查是否在边界内
		if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
			if (board[nr][nc] == '*')
				cnt++;
		}
	}
	return cnt;
}

int checkMines(char board[ROWS][COLS])
{
	// 遍历每个位置
	int cnt = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (board[i][j] == '*')
				cnt++;
		}
	}
	return (cnt == 50);
}
int checkNumbers(char board[ROWS][COLS])
{
	// 遍历每个位置
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			// 若这个位置不是雷，计算周围雷数
			if (board[i][j] != '*') {
				int mineCnt = countMinesAround(board, i, j);
				if (board[i][j] != '0' + mineCnt)
					return 0; // 数字不正确
			}
		}
	}
	return 1; // 数字正确
}
int main()
{
	char board[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	if (!checkMines(board))
		printf("错误1\n");
	else if (!checkNumbers(board))
		printf("错误2\n");
	else
		printf("正确\n");

	return 0;
}