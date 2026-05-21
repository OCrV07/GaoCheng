/* 2550332 杨舸帆 交通 */
#include "5-b7.h"
#include <conio.h> //预置头文件，根据需要来使用，不算违规，但程序不可靠
#include <iomanip>
#include <iostream>
#include <windows.h> //预置头文件，根据需要来使用，不算违规，但程序不可靠
using namespace std;

/* 静态全局变量：控制延时及是否显示内部数组 */
static int s_delay_ms = -1;		// -1 表示每次按任意键
static int s_show_internal = 0; // 是否显示内部数组

/* 三个简单变量(栈顶指针) + 三个一维数组(圆盘信息) */
int g_pegA[10] = {0}, g_pegB[10] = {0}, g_pegC[10] = {0};
int g_topA = 0, g_topB = 0, g_topC = 0;
int g_cnt = 0;

/***************************************************************************
  函数名称：get_top
  功    能：返回指定柱子的栈顶指针
***************************************************************************/
int get_top(char peg)
{
	if (peg == 'A')
		return g_topA;
	else if (peg == 'B')
		return g_topB;
	else
		return g_topC;
}

/***************************************************************************
  函数名称：push
  功    能：将圆盘压入指定柱子的栈顶
***************************************************************************/
void push(char peg, int n)
{
	if (peg == 'A')
		g_pegA[g_topA++] = n;
	else if (peg == 'B')
		g_pegB[g_topB++] = n;
	else
		g_pegC[g_topC++] = n;
}

/***************************************************************************
  函数名称：pop
  功    能：从指定柱子弹出栈顶圆盘并返回
***************************************************************************/
int pop(char peg)
{
	int v;
	if (peg == 'A') {
		v = g_pegA[--g_topA];
		g_pegA[g_topA] = 0;
	}
	else if (peg == 'B') {
		v = g_pegB[--g_topB];
		g_pegB[g_topB] = 0;
	}
	else {
		v = g_pegC[--g_topC];
		g_pegC[g_topC] = 0;
	}
	return v;
}

/***************************************************************************
  函数名称：clear_line
  功    能：清空当前输入行
***************************************************************************/
void clear_line()
{
	char ch;
	while ((ch = cin.get()) != '\n' && ch != EOF)
		;
}

/***************************************************************************
  函数名称：wait_input
  功    能：根据延时设定等待按键或延时
***************************************************************************/
void wait_input()
{
	if (s_delay_ms == -1) {
		while (_getch() != '\r')
			;
	}
	else if (s_delay_ms > 0) {
		Sleep(s_delay_ms);
	}
}

/***************************************************************************
  函数名称：print_info
  功    能：输出内部数组状态(格式同 5-b6-1)
***************************************************************************/
void print_info()
{
	cout << "A:";
	if (g_pegA[0] != 10)
		cout << " ";
	for (int i = 0; i < 10; i++) {
		if (i < g_topA) {
			cout << g_pegA[i] << " ";
		}
		else {
			cout << "  ";
		}
	}
	cout << "B:";
	if (g_pegB[0] != 10)
		cout << " ";
	for (int i = 0; i < 10; i++) {
		if (i < g_topB) {
			cout << g_pegB[i] << " ";
		}
		else {
			cout << "  ";
		}
	}
	cout << "C:";
	if (g_pegC[0] != 10)
		cout << " ";
	for (int i = 0; i < 10; i++) {
		if (i < g_topC) {
			cout << g_pegC[i] << " ";
		}
		else {
			cout << "  ";
		}
	}
}

/***************************************************************************
  函数名称：draw_header
  功    能：画分隔线和列标(A B C 三根柱子)
			  分隔线在上，列标在下，后续会在分隔线上方画圆
***************************************************************************/
void draw_header()
{
	cct_gotoxy(0, 12);
	for (int i = 0; i < 25; i++)
		cout << "=";
	cct_gotoxy(0, 13);
	cout << "  A         B         C";
}

/***************************************************************************
  函数名称：draw_plate
  功    能：在指定列指定层画一个圆盘(plate==0 表示擦除)
  内部参数：col_idx 0/1/2 对应 A/B/C
			level   0 为最底层，依次向上
			plate   0 擦除，否则为盘号
***************************************************************************/
void draw_plate(int col_idx, int level, int plate)
{
	int x = 1 + col_idx * 10;
	int y = 11 - level;
	cct_gotoxy(x, y);
	if (plate == 0) {
		cout << "  ";
	}
	else {
		cout << setw(2) << plate;
	}
}

/***************************************************************************
  函数名称：do_move
  功    能：执行一次移动（分为两阶段）
			   阶段1：更新数组，刷新日志行，等待按键/延时
			   阶段2：更新屏幕对应位置，等待按键/延时
***************************************************************************/
void do_move(int n, char src, char dst)
{
	g_cnt++;

	// 阶段1：更新内部数组
	int plate = pop(src);
	push(dst, plate);

	// 刷新日志行（固定在第14行）
	cct_gotoxy(0, 14);
	cout << "第" << setw(4) << g_cnt << "步(" << n << "#: " << src << "-->" << dst << ")";
	if (s_show_internal) {
		cout << "  ";
		print_info();
	}
	cout.flush();

	// 阶段1 等待
	wait_input();

	// 阶段2：更新屏幕对应位置
	int si = src - 'A', di = dst - 'A';
	draw_plate(si, get_top(src), 0);		 // 擦除源行旧位置（此时栈顶已更新）
	draw_plate(di, get_top(dst) - 1, plate); // 在目标行画新盘

	// 阶段2 等待
	wait_input();
}

/***************************************************************************
  函数名称：hanoi
  功    能：递归求解汉诺塔
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		do_move(1, src, dst);
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		do_move(n, src, dst);
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：main
  功    能：主函数
***************************************************************************/
int main()
{
	int n;
	char src, dst;
	int speed, show;

	// 输入层数
	do {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			clear_line();
		}
		else {
			clear_line();
		}
	} while (n < 1 || n > 10);

	// 输入起始柱
	int valid = 0;
	do {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
		if (src >= 'a' && src <= 'z')
			src -= 32;
		valid = (src >= 'A' && src <= 'C');
	} while (!valid);

	// 输入目标柱
	valid = 0;
	do {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
		if (dst >= 'a' && dst <= 'z')
			dst -= 32;
		valid = (dst >= 'A' && dst <= 'C');
		if (valid && dst == src) {
			cout << "目标柱(" << dst << ")与起始柱(" << src << ")相同" << endl;
			valid = 0;
		}
	} while (!valid);

	// 输入移动速度
	do {
		cout << "请输入移动速度(0-5: 0-每步按键继续 1-延时最长 5-延时最短)" << endl;
		cin >> speed;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
	} while (speed < 0 || speed > 5);

	switch (speed) {
		case 0:
			s_delay_ms = -1;
			break;
		case 1:
			s_delay_ms = 1000;
			break;
		case 2:
			s_delay_ms = 500;
			break;
		case 3:
			s_delay_ms = 200;
			break;
		case 4:
			s_delay_ms = 50;
			break;
		case 5:
			s_delay_ms = 0;
			break;
	}

	// 输入是否显示内部数组
	do {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> show;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
	} while (show < 0 || show > 1);
	s_show_internal = show;

	// 信息确认
	cout << "从 " << src << " 移动到 " << dst << "，层数 " << n << " 层，延时等级为 " << speed << "，"
		 << (s_show_internal ? "显示" : "不显示") << "内部数组值" << endl;
	system("pause");
	// 清除 system("pause") 带来的键盘缓冲区残留，避免干扰后续 _getch()
	while (_kbhit())
		_getch();

	// 初始化：将圆盘从大到小压入起始柱
	for (int i = n; i > 0; i--) {
		push(src, i);
	}

	// 清屏幕并打印确认信息
	cct_cls();
	cct_gotoxy(0, 0);
	cout << "从 " << src << " 移动到 " << dst << "，层数 " << n << " 层，延时等级为 " << speed << "，"
		 << (s_show_internal ? "显示" : "不显示") << "内部数组值" << endl;
	draw_header();

	// 移动日志行（固定在第14行），显示"初始:" 及内部数组（如要显示）
	cct_gotoxy(0, 14);
	cout << "初始:";
	if (s_show_internal) {
		cout << "                ";
		print_info();
	}
	cout.flush();

	// 第一次按任意键并画出初始圆盘
	wait_input();
	int si = src - 'A';
	if (src == 'A') {
		for (int i = 0; i < g_topA; i++)
			draw_plate(si, i, g_pegA[i]);
	}
	else if (src == 'B') {
		for (int i = 0; i < g_topB; i++)
			draw_plate(si, i, g_pegB[i]);
	}
	else {
		for (int i = 0; i < g_topC; i++)
			draw_plate(si, i, g_pegC[i]);
	}

	// 开始汉诺塔递归
	char tmp = (char)('A' + 'B' + 'C' - src - dst);
	hanoi(n, src, tmp, dst);

	// 把光标移到日志末尾下方，然后暂停
	cct_gotoxy(0, 15);
	system("pause");
	return 0;
}
