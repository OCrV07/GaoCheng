/* 2550332 杨舸帆 交通 */

#include <iostream>
using namespace std;
int main()
{
	double m;
	cout << "请输入找零值" << endl;
	cin >> m;
	int money = (int)(m * 100 + 0.5); // 将金额转换为整数，单位为分
	int cnt50 = 0, cnt20 = 0, cnt10 = 0, cnt5 = 0, cnt1 = 0,
		cnt05 = 0, cnt01 = 0, cnt005 = 0, cnt002 = 0, cnt001 = 0;

	cnt50 = money / 5000;
	money -= cnt50 * 5000;
	cnt20 = money / 2000;
	money -= cnt20 * 2000;
	cnt10 = money / 1000;
	money -= cnt10 * 1000;
	cnt5 = money / 500;
	money -= cnt5 * 500;
	cnt1 = money / 100;
	money -= cnt1 * 100;

	cnt05 = money / 50;
	money -= cnt05 * 50;
	cnt01 = money / 10;
	money -= cnt01 * 10;
	cnt005 = money / 5;
	money -= cnt005 * 5;
	cnt002 = money / 2;
	money -= cnt002 * 2;
	cnt001 = money;
	money -= cnt001;

	int total = cnt50 + cnt20 + cnt10 + cnt5 + cnt1
		+ cnt05 + cnt01 + cnt005 + cnt002 + cnt001;

	cout << "共" << total << "张找零，具体如下：" << endl;
	if (cnt50 > 0)
		cout << "50元 ： " << cnt50 << "张" << endl;
	if (cnt20 > 0)
		cout << "20元 ： " << cnt20 << "张" << endl;
	if (cnt10 > 0)
		cout << "10元 ： " << cnt10 << "张" << endl;
	if (cnt5 > 0)
		cout << "5元  ： " << cnt5 << "张" << endl;
	if (cnt1 > 0)
		cout << "1元  ： " << cnt1 << "张" << endl;
	if (cnt05 > 0)
		cout << "5角  ： " << cnt05 << "张" << endl;
	if (cnt01 > 0)
		cout << "1角  ： " << cnt01 << "张" << endl;
	if (cnt005 > 0)
		cout << "5分  ： " << cnt005 << "张" << endl;
	if (cnt002 > 0)
		cout << "2分  ： " << cnt002 << "张" << endl;
	if (cnt001 > 0)
		cout << "1分  ： " << cnt001 << "张" << endl;

	return 0;
}
