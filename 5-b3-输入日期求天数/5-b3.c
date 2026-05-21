/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 判断是否为闰年
int isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取指定月份的天数
int getDays(int month, int isLeapYear)
{
	// 非闰年
	int nonLeapDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// 闰年
	int leapDays[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return isLeapYear ? leapDays[month] : nonLeapDays[month];
}

// 计算该年的第几天
int calculateDay(int y, int m, int d)
{
	int leap = isLeap(y);
	int total = 0;
	// 累加前m-1个月的天数
	for (int i = 1; i < m; ++i) {
		total += getDays(i, leap);
	}
	// 加上当月天数
	total += d;
	return total;
}

int main()
{
	int y, m, d;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &y, &m, &d);

	// 检查月份合法性
	if (m < 1 || m > 12) {
		printf("输入错误-月份不正确\n");
		return 0;
	}

	// 检查日期合法性（通过数组获取当月天数）
	int maxDay = getDays(m, isLeap(y));
	if (d < 1 || d > maxDay) {
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}

	// 计算并输出天数
	int day = calculateDay(y, m, d);
	printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, day);

	return 0;
}