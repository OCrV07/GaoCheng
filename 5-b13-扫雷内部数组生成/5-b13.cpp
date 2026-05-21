/* 2550332 杨舸帆 交通 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

#define ROWS 10 // 10行
#define COLS 26 // 26列
#define MINE_CNT 50

void initBoard(char board[ROWS][COLS])
{
	// 初始化所有位置为 '0'
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = '0';
		}
	}
}

void placeMines(char board[ROWS][COLS])
{
	int cnt = 0; // 统计已放置的雷数
	srand((unsigned int)(time(0)));

	while (cnt < MINE_CNT) {
		// 随机选择一个格子生成雷
		int row = rand() % ROWS;
		int col = rand() % COLS;

		// 若生成的位置已有雷，则重新生成
		if (board[row][col] != '*') {
			board[row][col] = '*';
			cnt++;
		}
	}
}

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

void calculateNumbers(char board[ROWS][COLS])
{
	// 遍历每个位置
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			// 若这个位置不是雷，计算周围雷数
			if (board[i][j] != '*') {
				int mineCnt = countMinesAround(board, i, j);
				board[i][j] = '0' + mineCnt; // 将数字转为字符
			}
		}
	}
}

// 打印盘面
void printBoard(char board[ROWS][COLS])
{

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	char board[ROWS][COLS];

	initBoard(board);		 // 初始化为 '0'
	placeMines(board);		 // 随机放置50颗雷
	calculateNumbers(board); // 计算每个格子周围的雷数

	printBoard(board); // 打印结果

	return 0;
}