/* 2550332 杨舸帆 交通 */
#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	// 输入年份和月份
	int y, m;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	// 判断是否为闰年
	bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;

	// 输入该月第一天是星期几
	int d;
	while (1) {
		cout << "请输入" << y << "年" << m << "月" << "1日的星期(0-6表示星期日-星期六) : ";
		cin >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n'); 
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (d >= 0 && d <= 6)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	cout << endl;
	// 输入结束, 下面开始打印日历
	// 打印表头
	cout << y << "年" << m << "月的月历为: " << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

	// 观察demo发现: 每天占的宽度是 6, 空格的宽度是 2, 打印出数字的位置在每天占的宽度的中间
	// 1 个数字在第 4 个字符位置, 2 个数字在第 3、4 个字符位置
	int width = 54;
	// 根据输入的第一天是星期几，计算第一行需要打印多少个空格
	int day1_space = d * 8; // 每个空格占 8 个字符宽度
	cout << setw(day1_space) << ""; // 打印第一行的前导空格
	
	// 打印每个月的天数
	for (int day = 1; day <= 31; day++) {
		if (m == 2) { // 二月
			if (leap && day > 29) 
				break;
			if (!leap && day > 28) 
				break;
		} else if (m == 4 || m == 6 || m == 9 || m == 11) { // 小月只有30天
			if (day == 31) 
				break;
		}
		cout << setw(4) << day; // 打印日期
		cout << setw(4) << ""; // 打印日期后面的空格

		// (d + day - 1) % 7 是当前日期对应的星期几, 如果等于 6 就说明是星期六, 需要换行
		if ((d + day - 1) % 7 == 6) 
			cout << endl; 
	}

	cout << endl;
	return 0;
}
