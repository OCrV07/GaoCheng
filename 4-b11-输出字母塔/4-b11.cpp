/* 2550332 杨舸帆 交通 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

    /***************************************************************************
	 函数名称：l_print
	 功    能：递归打印左侧递减字符序列
	 输入参数：char ch, int cnt
	 返 回 值：无
   ***************************************************************************/
void l_print(char ch, int cnt)
{
	if (cnt < 0)
		return;
	cout << ch;
	if (cnt > 0)
		l_print(ch - 1, cnt - 1);
}

   /***************************************************************************
	 函数名称：r_print
	 功    能：递归打印右侧递增字符序列
	 输入参数：char start_ch, int cnt
	 返 回 值：无
   ***************************************************************************/
void r_print(char start_ch, int cnt)
{
	if (cnt <= 0)
		return;
	cout << start_ch;
	r_print(start_ch + 1, cnt - 1);
}

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_tower(char start, char end, bool order, int layer, int extra)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	int n = end - start;
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */

	if (order == 1) // 正三角打印（从外层到中心）
	{
		// 打印当前行
		int space_num = n - layer;  // 修改：计算空格数
		cout << setw(space_num) << "";

		// 打印左侧递减部分
		l_print(start + layer, layer);

		// 打印右侧递增部分
		r_print(start + 1, layer);

		// 换行
		cout << endl;

		// 递归打印下一行（内层）
		if (layer < n)
			print_tower(start, end, order, layer + 1, 0);
	}
	else // 倒三角打印（从中心到外层）
	{
		if (end == 'A' - 1)
			return;
		// 先递归打印内层
		if (layer < n)
			print_tower(start, end, order, layer + 1, extra);

		// 打印当前行
		int space_num = n - layer + extra;  // 修改：计算空格数
		cout << setw(space_num) << "";

		// 打印左侧递减部分
		l_print(start + layer, layer);

		// 打印右侧递增部分
		r_print(start + 1, layer);

		// 换行
		cout << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') 
	{
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((int)(end_ch - 'A') * 2 + 1) << "" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((int)(end_ch - 'A') * 2 + 1) << "" << setfill(' ') << endl; 
	print_tower('A', end_ch, 1, 0, 0); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw((int)(end_ch - 'A') * 2 + 1) << "" << setfill(' ') << endl; 
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((int)(end_ch - 'A') * 2 + 1) << "" << setfill(' ') << endl; 
	print_tower('A', end_ch, 0, 0, 0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw((int)(end_ch - 'A') * 2 + 1) << "" << setfill(' ') << endl; 
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((int)(end_ch - 'A') * 2 + 1) << "" << setfill(' ') << endl; 
	print_tower('A', end_ch, 1, 0, 0);   //打印 A~结束字符的正三角 
	print_tower('A', end_ch - 1, 0, 0, 1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
