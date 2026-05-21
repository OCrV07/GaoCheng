/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int main()
{
	printf("请输入年，月，日\n");
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);

	// 判断输入是否合法
	if (m < 1 || m > 12)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	if (d < 0 || d > 31) 
	{
		printf("输入错误-日期不正确\n");
		return 0;
	}

	bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	if (m == 2)
	{
		if (leap)
		{
			if (d > 29)
			{
				printf("输入错误-日期不正确\n");
				return 0;
			}
		}
		else if (d > 28)
		{
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
	}
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	else if (d > 31 && (m == 1 || m == 3 || m == 5 || 
		     m == 7 || m == 8 || m == 10 || m == 12))
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}

	int FebDays = leap ? 29 : 28;
	int ans = 0;
	if (m > 1)
	{
		ans += 31;
	}
	if (m > 2)
	{
		ans += FebDays;
	}
	if (m > 3)
	{
		ans += 31;
	}
	if (m > 4)
	{
		ans += 30;
	}
	if (m > 5)
	{
		ans += 31;
	}
	if (m > 6)
	{
		ans += 30;
	}
	if (m > 7)
	{
		ans += 31;
	}
	if (m > 8)
	{
		ans += 31;
	}
	if (m > 9)
	{
		ans += 30;
	}
	if (m > 10)
	{
		ans += 31;
	}
	if (m > 11)
	{
		ans += 30;
	}
	ans += d;

	printf("%d-%d-%d是%d年的第%d天", y, m, d, y, ans);

	return 0;
}
