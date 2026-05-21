/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	double m;
	printf("请输入找零值：\n");
	scanf("%lf", &m);
	int money_int = (int)m;
	double money_frac = m - money_int;
	int cnt50 = 0, cnt20 = 0, cnt10 = 0, cnt5 = 0, cnt1 = 0,
		cnt05 = 0, cnt01 = 0, cnt005 = 0, cnt002 = 0, cnt001 = 0;

	cnt50 = money_int / 50;
	money_int -= cnt50 * 50;
	cnt20 = money_int / 20;
	money_int -= cnt20 * 20;
	cnt10 = money_int / 10;
	money_int -= cnt10 * 10;
	cnt5 = money_int / 5;
	money_int -= cnt5 * 5;
	cnt1 = money_int;
	money_int -= cnt1;

	cnt05 = (int)floor(money_frac / 0.5);
	money_frac = fmod(money_frac, 0.5);
	cnt01 = (int)floor(money_frac / 0.1);
	money_frac = fmod(money_frac, 0.1);
	cnt005 = (int)floor(money_frac / 0.05);
	money_frac = fmod(money_frac, 0.05);
	cnt002 = (int)floor(money_frac / 0.02);
	money_frac = fmod(money_frac, 0.02);
	cnt001 = (int)floor(money_frac / 0.01);

	int total = cnt50 + cnt20 + cnt10 + cnt5 + cnt1
		+ cnt05 + cnt01 + cnt005 + cnt002 + cnt001;

	printf("共%d张找零，具体如下：\n", total);
	if (cnt50 > 0)
		printf("50元 : %d张\n", cnt50);
	if (cnt20 > 0)
		printf("20元 : %d张\n", cnt20);
	if (cnt10 > 0)
		printf("10元 : %d张\n", cnt10);
	if (cnt5 > 0)
		printf("5元  : %d张\n", cnt5);
	if (cnt1 > 0)
		printf("1元  : %d张\n", cnt1);
	if (cnt05 > 0)
		printf("5角  : %d张\n", cnt05);
	if (cnt01 > 0)
		printf("1角  : %d张\n", cnt01);
	if (cnt005 > 0)
		printf("5分  : %d张\n", cnt005);
	if (cnt002 > 0)
		printf("2分  : %d张\n", cnt002);
	if (cnt001 > 0)
		printf("1分  : %d张\n", cnt001);

	return 0;
}
