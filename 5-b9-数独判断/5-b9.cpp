/* 2550332 杨舸帆 交通 */
#include <iostream>
using namespace std;

void readGrid(int grid[9][9]);
bool checkRows(int grid[9][9]);
bool checkCols(int grid[9][9]);
bool checkSubgrids(int grid[9][9]);

int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	int grid[9][9];

	// Line 2-x: 输入的9 * 9=81个数字
	readGrid(grid);

	// Line x+1: 判断结果
	if (checkRows(grid) && checkCols(grid) && checkSubgrids(grid)) {
		cout << "是数独的解" << endl;
	}
	else {
		cout << "不是数独的解" << endl;
	}

	return 0;
}

/**
 * 读取9x9矩阵并处理输入错误
 * 处理原则：cin正确但范围不合理，不清缓冲区直接读下一个数字；cin错误则清缓冲区
 */
void readGrid(int grid[9][9])
{
	int cnt = 0;
	while (cnt < 81) {
		int row = cnt / 9;
		int col = cnt % 9;
		cin >> grid[row][col];
		if (cin.fail()) {
			cin.clear();			// 清除错误状态
			cin.ignore(1024, '\n'); // 丢弃输入缓冲区中的错误输入
			continue;
		}

		// 检查范围是否在1-9之间
		if (grid[row][col] >= 1 && grid[row][col] <= 9) {
			cnt++;
		}
		// 范围不合理时，不清空缓冲区，直接继续读取下一个数字
	}
}

/**
 * 检查每行是否包含1-9且不重复
 */
bool checkRows(int grid[9][9])
{
	for (int i = 0; i < 9; i++) {
		bool used[10] = {false}; // 下标1-9记录数字是否已出现

		for (int j = 0; j < 9; j++) {
			int num = grid[i][j];
			if (used[num]) {
				return false;
			}
			used[num] = true;
		}
	}
	return true;
}

/**
 * 检查每列是否包含1-9且不重复
 */
bool checkCols(int grid[9][9])
{
	for (int j = 0; j < 9; j++) {
		bool used[10] = {false};

		for (int i = 0; i < 9; i++) {
			int num = grid[i][j];
			if (used[num]) {
				return false;
			}
			used[num] = true;
		}
	}
	return true;
}

/**
 * 检查每个小九宫格是否包含1-9且不重复
 */
bool checkSubgrids(int grid[9][9])
{
	for (int blockRow = 0; blockRow < 3; blockRow++) {
		for (int blockCol = 0; blockCol < 3; blockCol++) {
			bool used[10] = {false};

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int num = grid[blockRow * 3 + i][blockCol * 3 + j];
					if (used[num]) {
						return false;
					}
					used[num] = true;
				}
			}
		}
	}
	return true;
}