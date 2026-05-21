/* 2550332 杨舸帆 交通 */

#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> a;
	cout << "万位 : " << a / 10000 << endl;
	a %= 10000;
	cout << "千位 : " << a / 1000 << endl;
	a %= 1000;
	cout << "百位 : " << a / 100 << endl;
	a %= 100;
	cout << "十位 : " << a / 10 << endl;
	a %= 10;
	cout << "个位 : " << a << endl;
}
