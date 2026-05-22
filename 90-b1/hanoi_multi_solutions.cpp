/* 2550332 杨舸帆 交通 */

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include "cmd_console_tools.h"
#include "cmd_hdc_tools.h"
#include "hanoi_const_value.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;

/* 静态全局变量：控制延时及是否显示内部数组 */
static int s_delay_ms = -1;		// -1 表示每次按任意键
static int s_show_internal = 1; // 是否显示内部数组

/* 三个简单变量(栈顶指针) + 三个一维数组(圆盘信息) */
int g_pegA[10] = {0}, g_pegB[10] = {0}, g_pegC[10] = {0};
int g_topA = 0, g_topB = 0, g_topC = 0;
int g_cnt = 0;

/***************************************************************************
  函数名称：clear_state
  功    能：清除状态
***************************************************************************/
void clear_state()
{
	// 清空数组
	for (int i = 0; i < 10; i++) {
		g_pegA[i] = 0;
		g_pegB[i] = 0;
		g_pegC[i] = 0;
	}

	// 重置栈顶指针
	g_topA = 0;
	g_topB = 0;
	g_topC = 0;

	// 重置步数计数器
	g_cnt = 0;
}

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
  函数名称：set_delay
  功    能：设置移动速度
***************************************************************************/
void set_delay(int *speed)
{
	do {
		cout << "请输入移动速度(0-200：0-按回车单步演示 1-200 : 延时1-200ms)" << endl;
		cin >> *speed;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
	} while (*speed < 0 || *speed > 200);

	if (*speed == 0)
		s_delay_ms = -1;
	else
		s_delay_ms = *speed;
}

/***************************************************************************
  函数名称：set_show
  功    能：设置是否显示内部数组
***************************************************************************/
void set_show(int *show)
{
	do {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> *show;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
	} while (*show < 0 || *show > 1);
	s_show_internal = *show;
}

/***************************************************************************
函数名称：wait
功    能：根据延时设定等待按键或延时
***************************************************************************/
void wait()
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
  函数名称：hanoi_info_input
  功    能：输入汉诺塔基本信息
***************************************************************************/
void hanoi_info_input(int *n, char *src, char *dst)
{
	// 输入层数
	do {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> *n;
		if (cin.fail()) {
			cin.clear();
			clear_line();
		}
		else {
			clear_line();
		}
	} while (*n < 1 || *n > 10);

	// 输入起始柱
	int valid = 0;
	do {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> *src;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
		if (*src >= 'a' && *src <= 'z')
			*src -= 32;
		valid = (*src >= 'A' && *src <= 'C');
	} while (!valid);

	// 输入目标柱
	valid = 0;
	do {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> *dst;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
		if (*dst >= 'a' && *dst <= 'z')
			*dst -= 32;
		valid = (*dst >= 'A' && *dst <= 'C');
		if (valid && *dst == *src) {
			cout << "目标柱(" << *dst << ")与起始柱(" << *src << ")相同" << endl;
			valid = 0;
		}
	} while (!valid);
}

/***************************************************************************
  函数名称：print_info
  功    能：输出内部数组状态
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
	cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET - 2, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 1);
	for (int i = 0; i < Underpan_Distance * 2 + 7; i++)
		cout << "=";
	cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);

	cout << "A";
	for (int i = 0; i < Underpan_Distance - 1; i++)
		cout << " ";
	cout << "B";
	for (int i = 0; i < Underpan_Distance - 1; i++)
		cout << " ";
	cout << "C";
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
	// 设置设置输出宽度为2, 所以要偏移一个像素
	int x = MenuItem4_Start_X + Underpan_A_X_OFFSET + col_idx * Underpan_Distance - 1;
	int y = MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 2 - level;
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
void do_move(int n, char src, char dst, int mode)
{
	g_cnt++;
	if (mode == 1) {
		cout << n << "#: " << src << "-->" << dst << endl;
	}
	else if (mode == 2) {
		cout << "第" << setw(4) << g_cnt << " 步( " << n << "#: " << src << "-->" << dst << ")" << endl;
	}

	if (mode == 3 || mode == 4) {
		// 阶段1：更新内部数组
		int plate = pop(src);
		push(dst, plate);
		if (mode == 3) {
			cout << "第" << setw(4) << g_cnt << " 步( " << n << "#: " << src << "-->" << dst << ")";
			cout << "  ";
			print_info();
			cout.flush();
			cout << endl;
		}

		if (mode == 4) {
			// 刷新日志行
			cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
			cout << "第" << setw(4) << g_cnt << " 步( " << n << "#: " << src << "-->" << dst << ")";
			cout << "  ";
			print_info();
			cout.flush();
			// 阶段1 等待
			wait();

			// 阶段2：更新屏幕对应位置
			int si = src - 'A', di = dst - 'A';
			draw_plate(si, get_top(src), 0);		 // 擦除源行旧位置（此时栈顶已更新）
			draw_plate(di, get_top(dst) - 1, plate); // 在目标行画新盘

			// 阶段2 等待
			wait();
		}
	}
}
/***************************************************************************
  函数名称：hanoi
  功    能：递归求解汉诺塔
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int mode)
{
	if (n == 1) {
		do_move(1, src, dst, mode);
	}
	else {
		hanoi(n - 1, src, dst, tmp, mode);
		do_move(n, src, dst, mode);
		hanoi(n - 1, tmp, src, dst, mode);
	}
}

void mode_1() // 基本解
{
	int n;
	char src, dst;
	hanoi_info_input(&n, &src, &dst);
	char tmp = (char)('A' + 'B' + 'C' - src - dst);
	hanoi(n, src, tmp, dst, 1);
}

void mode_2() // 基本解(步数记录)
{
	int n;
	char src, dst;
	hanoi_info_input(&n, &src, &dst);
	char tmp = (char)('A' + 'B' + 'C' - src - dst);
	hanoi(n, src, tmp, dst, 2);
}

void mode_3() // 内部数组显示(横向)
{
	int n;
	char src, dst;
	hanoi_info_input(&n, &src, &dst);

	// 清除 system("pause") 带来的键盘缓冲区残留，避免干扰后续 _getch()
	while (_kbhit())
		_getch();

	// 初始化：将圆盘从大到小压入起始柱
	for (int i = n; i > 0; i--) {
		push(src, i);
	}

	// 开始汉诺塔递归
	char tmp = (char)('A' + 'B' + 'C' - src - dst);
	hanoi(n, src, tmp, dst, 3);
}

void mode_4() // 内部数组显示(纵向 + 横向)
{
	int n;
	char src, dst;
	hanoi_info_input(&n, &src, &dst);
	int speed, show = 1;
	set_delay(&speed);

	// 清除 system("pause") 带来的键盘缓冲区残留，避免干扰后续 _getch()
	while (_kbhit())
		_getch();

	// 初始化：将圆盘从大到小压入起始柱
	for (int i = n; i > 0; i--) {
		push(src, i);
	}

	// 清屏幕并打印确认信息
	cct_cls();
	cct_gotoxy(Status_Line_X, Status_Line_Y);
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << "ms" << endl;
	draw_header();

	// 移动日志行，显示"初始:" 及内部数组
	cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
	cout << "初始:";
	if (s_show_internal) {
		cout << "                ";
		print_info();
	}
	cout.flush();

	// 第一次按任意键并画出初始圆盘
	wait();
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
	hanoi(n, src, tmp, dst, 4);

	// 把光标移到日志末尾下方
	cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
}

void mode_5(bool mode5 = true) // 图形解-预备-画三个圆柱
{
	if (mode5) {
		cct_cls();
		hdc_cls();
	}
	const int win_width = 1400, win_high = 900; // 设定屏幕宽度
	const int win_fgcolor = 0;

	hdc_init(HDC_COLOR[0], win_fgcolor, win_width,
			 win_high); // 用(背景色，前景色，宽度，高度）初始化窗口
	s_delay_ms = HDC_Init_Delay;
	// 画底盘
	hdc_rectangle(HDC_Start_X, HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High,
				  HDC_COLOR[11]); // 画A柱底盘
	wait();
	hdc_rectangle(HDC_Start_X + HDC_Underpan_Distance + HDC_Base_Width * 23, HDC_Start_Y, HDC_Base_Width * 23,
				  HDC_Base_High,
				  HDC_COLOR[11]); // 画B柱底盘
	wait();
	hdc_rectangle(HDC_Start_X + 2 * HDC_Underpan_Distance + HDC_Base_Width * 23 * 2, HDC_Start_Y, HDC_Base_Width * 23,
				  HDC_Base_High,
				  HDC_COLOR[11]); // 画C柱底盘

	wait();

	// 画立柱
	hdc_rectangle(HDC_Start_X + HDC_Base_Width * 11, HDC_Start_Y - HDC_Base_High * 12, HDC_Base_Width,
				  HDC_Base_High * 12,
				  HDC_COLOR[11]); // 画A立柱
	wait();
	hdc_rectangle(HDC_Start_X + HDC_Base_Width * 11 + HDC_Underpan_Distance + HDC_Base_Width * 23,
				  HDC_Start_Y - HDC_Base_High * 12, HDC_Base_Width, HDC_Base_High * 12,
				  HDC_COLOR[11]); // 画B立柱
	wait();
	hdc_rectangle(HDC_Start_X + HDC_Base_Width * 11 + 2 * HDC_Underpan_Distance + HDC_Base_Width * 23 * 2,
				  HDC_Start_Y - HDC_Base_High * 12, HDC_Base_Width, HDC_Base_High * 12,
				  HDC_COLOR[11]); // 画C立柱
}

void mode_6() // 图形解-预备-在起始柱上画n个盘子
{
	int n;
	char src, dst;
	hanoi_info_input(&n, &src, &dst);
	// 清除 system("pause") 带来的键盘缓冲区残留，避免干扰后续 _getch()
	while (_kbhit())
		_getch();

	cct_cls();
	hdc_cls();
	cct_gotoxy(Status_Line_X, Status_Line_Y);
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
	mode_5(false);

	wait();
	// 盘子宽度: 3w-21w, 盘子高度: h
	// 盘子颜色: HDC_COLOR[1]~HDC_COLOR[10]，底色: HDC_COLOR[0]
	// 总共 n 个盘
	// 1号盘的高度: HDC_Start_Y - HDC_Base_High * n
	for (int i = n; i > 0; i--) {
		hdc_rectangle(HDC_Start_X + HDC_Base_Width * (11 - i) + (HDC_Underpan_Distance + HDC_Base_Width * 23) * 0,
					  HDC_Start_Y - HDC_Base_High * (n - i + 1), HDC_Base_Width * (2 * i + 1), HDC_Base_High,
					  HDC_COLOR[i]);
		wait();
	}
	cout << endl;
}

void mode_7() // 图形解-预备-第一次移动
{
	int n;
	char src, dst;
	hanoi_info_input(&n, &src, &dst);
	// 如果启用延迟，设置速度
	// 便于后续模式可以直接调用mode_6()画盘
	int speed;
	set_delay(&speed);
	// 清除 system("pause") 带来的键盘缓冲区残留，避免干扰后续 _getch()
	while (_kbhit())
		_getch();

	cct_cls();
	hdc_cls();
	cct_gotoxy(Status_Line_X, Status_Line_Y);
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
	mode_5(false);

	wait();
	// 盘子宽度: 3w-21w, 盘子高度: h
	// 盘子颜色: HDC_COLOR[1]~HDC_COLOR[10]，底色: HDC_COLOR[0]
	// 总共 n 个盘
	// 1号盘的高度: HDC_Start_Y - HDC_Base_High * n
	for (int i = n; i > 0; i--) {
		hdc_rectangle(HDC_Start_X + HDC_Base_Width * (11 - i) + (HDC_Underpan_Distance + HDC_Base_Width * 23) * 0,
					  HDC_Start_Y - HDC_Base_High * (n - i + 1), HDC_Base_Width * (2 * i + 1), HDC_Base_High,
					  HDC_COLOR[i]);
		wait();
	}
	cout << endl;
}

void mode_8() // 图形解-预备-第二次移动
{
}

void mode_9() // 图形解-游戏版
{
}

void solution_mode_choose(int mode)
{
	cout << endl;
	switch (mode) {
		case 0:
			break;
		case 1:
			mode_1();
			break;
		case 2:
			mode_2();
			break;
		case 3:
			mode_3();
			break;
		case 4:
			mode_4();
			break;
		case 5:
			mode_5();
			break;
		case 6:
			mode_6();
			break;
		case 7:
			mode_7();
			break;
		case 8:
			mode_8();
			break;
		case 9:
			mode_9();
			break;
	}
}