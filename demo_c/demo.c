#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double d;
	int w, p;
	printf("请输入double型数据及显示总宽度、小数点后位数\n");
	scanf("%lf %d %d", &d, &w, &p);	  // 不考虑输入错误
	printf("01234567890123456789\n"); // 标尺

	char fmt[30];
	sprintf(fmt, "%%%d.%dlf*\n", w, p);
	printf(fmt, d);

	return 0;
}