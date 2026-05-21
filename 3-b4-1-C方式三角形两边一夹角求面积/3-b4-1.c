/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
const double Pi = 3.14159;
int main()
{
	int a, b, angle;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &angle);
	float s = sin(angle * (float)Pi / 180.0);
	printf("三角形面积为 : %.3f\n", (float)0.5 * a * b * s);
	return 0;
}
