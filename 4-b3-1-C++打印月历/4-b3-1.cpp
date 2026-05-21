/* 2550332 杨舸帆 交通 */
#include <iostream> 
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	// 1月和2月被视为前一年的13月和14月
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int c = y / 100; // 世纪 - 1
	int k = y % 100; // 年份的后两位
	return ((k + k / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7 + 7) % 7;
}

void calendar(int year, int month)
{
	/* 按需添加代码 */
	cout << endl;

	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	int d = zeller(year, month, 1); // 计算该月第一天是星期几
	int day1_space = d * 8; // 每个空格占 8 个字符宽度
	cout << setw(day1_space) << ""; // 打印第一行的前导空格
	bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; // 判断是否为闰年

	// 计算该月的天数
	int daysInMonth; 
	if (month == 2) 
		daysInMonth = leap ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11) 
		daysInMonth = 30;
	else 
		daysInMonth = 31;

	// 打印每个月的天数
	for (int day = 1; day <= daysInMonth; day++) 
	{
		cout << setw(4) << day; // 打印日期
		cout << setw(4) << ""; // 打印日期后面的空格

		// (d + day - 1) % 7 是当前日期对应的星期几, 如果等于 6 就说明是星期六, 需要换行
		if ((d + day - 1) % 7 == 6)
			cout << endl;
	}
	// 最后一天如果不是星期六, 就换行
	if ((d + daysInMonth - 1) % 7 != 6)
		cout << endl;

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main()
{
	// 输入
	int y, m;

	while (1) 
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;

		if (cin.fail()) 
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear(); //清除错误状态
			cin.ignore(1000, '\n'); //丢弃输入缓冲区中的错误输入
			continue;
		}

		if (!((y >= 1900 && y <= 2100) && (m >= 1 && m <= 12)))
		{
			if (y < 1900 || y > 2100)
				cout << "年份不正确，请重新输入" << endl;
			else if (m < 1 || m > 12)
				cout << "月份不正确，请重新输入" << endl;
		}
		else
			break;
	}

	// 输出
	calendar(y, m);

	return 0;
}
