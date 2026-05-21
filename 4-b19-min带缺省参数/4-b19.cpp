/* 2550332 杨舸帆 交通 */
#include <iostream>
using namespace std;

int min(int a, int b, int c = 2147483647, int d = 2147483647)
{
	int mi = a < b ? a : b;
	if (c != 2147483647)
		mi = mi < c ? mi : c;
	if (d != 2147483647)
		mi = mi < d ? mi : d;
	return mi;
}

int main()
{
	int num;
	while (true) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;

		// 个数输入错误（非整数）则重新输入
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		// 个数范围错误则直接退出
		if (num < 2 || num > 4) {
			cout << "个数输入错误" << endl;
			return 0;
		}

		// 读取 num 个正整数
		int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
		bool error = false;

		for (int i = 0; i < num; i++) {
			int temp = 0;
			cin >> temp;
			if (cin.fail() || temp <= 0) {
				// 输入出错（非整数或负数/零）则从个数开始重新输入
				cin.clear();
				cin.ignore(1024, '\n');
				error = true;
				break;
			}

			// 根据当前读取的序号存储到对应的变量中
			if (i == 0)
				val1 = temp;
			else if (i == 1)
				val2 = temp;
			else if (i == 2)
				val3 = temp;
			else if (i == 3)
				val4 = temp;
		}

		if (error)
			continue;

		// 忽略多余的输入
		cin.ignore(1024, '\n');

		int result;
		if (num == 2)
			result = min(val1, val2);
		else if (num == 3)
			result = min(val1, val2, val3);
		else
			result = min(val1, val2, val3, val4);
		cout << "min=" << result << endl;
		break;
	}
	return 0;
}
