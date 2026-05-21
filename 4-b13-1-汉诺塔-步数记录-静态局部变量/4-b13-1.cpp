/* 2550332 杨舸帆 交通 */
#include <iomanip>
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、本函数不允许出现任何形式的循环
			3、允许定义一个静态局部变量
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int cnt = 1;
	if (n == 1) {
		cout << setw(5) << cnt << ':' << setw(3) << n << "# " << src << "-->"
			 << dst << endl;
		cnt++;
	}
	else {
		hanoi(n - 1, src, dst, tmp); // 将前 n-1 层从 src 移动到 tmp
		cout << setw(5) << cnt << ':' << setw(3) << n << "# " << src << "-->"
			 << dst << endl; // 将第 n 层从 src 移动到 dst
		cnt++;
		hanoi(n - 1, tmp, src, dst); // 将前 n-1 层从 tmp 移动到 dst
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
			2、处理输入错误时，允许使用循环
			3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int n;
	char src, dst;

	// 输入层数
	do {
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> n;
		cin.clear();			// 清除错误标志
		cin.ignore(1024, '\n'); // 清空缓冲区
	} while (n < 1 || n > 16);

	// 输入起始柱
	bool valid = false;
	do {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		cin.clear();			// 清除错误标志
		cin.ignore(1024, '\n'); // 清空缓冲区

		// 统一转换为大写字母
		if (src >= 'a' && src <= 'z')
			src = src - 'a' + 'A';

		valid = (src >= 'A' && src <= 'C');
	} while (!valid);

	// 输入目标柱
	do {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		cin.clear();			// 清除错误标志
		cin.ignore(1024, '\n'); // 清空缓冲区

		// 统一转换为大写字母
		if (dst >= 'a' && dst <= 'z')
			dst = dst - 'a' + 'A';

		valid = dst >= 'A' && dst <= 'C';
		if (valid && dst == src) {
			cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同"
				 << endl;
			valid = false;
		}
	} while (!valid);

	cout << "移动步骤为:" << endl;
	hanoi(n, src, char('A' + 'B' + 'C' - src - dst), dst);
}
