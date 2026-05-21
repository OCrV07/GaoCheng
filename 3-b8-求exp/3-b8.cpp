/* 2550332 杨舸帆 交通 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int x;
	cout << "请输入x的值[-10 ~ +65]" << endl;
	cin >> x;
	while (x < -10 || x > 65)
	{
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
	}

	double ans = 1.0, now = 1.0;

	for (int i = 1; ; i++)
	{
		now *= (double)x / i;
		if (fabs(now) < 1e-6)
		{
			cout << "迭代终值 " << "n=" << i << ' ';
			cout << scientific << setprecision(9);
			cout << "|x^" << i << "/" << i << "!|=";
			if (x != 0)
				cout << now << endl;
			else
				cout << 0 << endl;
			break;
		}

		ans += now;
	}

	cout << resetiosflags(ios::scientific) << setprecision(10);
	cout << "e^" << x << "=" << ans << endl;
}
