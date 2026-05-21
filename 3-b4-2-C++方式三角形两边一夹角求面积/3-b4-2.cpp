/* 2550332 杨舸帆 交通 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double Pi = 3.14159;
int main()
{
	int a, b, angle;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> angle;
	cout << fixed << setprecision(3);
	float s = sin(angle * (float)Pi / 180.0);
	// cout << "三角形面积为 : " << float(0.5 * a * b * float(sin(float(angle * Pi / 180.0)))) << endl;
	cout << "三角形面积为 : " << (float)0.5 * a * b * s << endl;
	return 0;
}
