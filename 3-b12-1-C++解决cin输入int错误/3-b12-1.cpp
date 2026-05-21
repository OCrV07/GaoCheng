/* 2550332 杨舸帆 交通 */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear(); //清除错误状态
			cin.ignore(1000, '\n'); //丢弃输入缓冲区中的错误输入
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}

	cout << "cin.fail()=" << cin.fail() << " x=" << x << endl; //此句不准动，并且要求输出时fail为0

	return 0;
}
