/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &a);
	printf("万位 : %d\n", a / 10000);
	a %= 10000;
	printf("千位 : %d\n", a / 1000);
	a %= 1000;
	printf("百位 : %d\n", a / 100);
	a %= 100;
	printf("十位 : %d\n", a / 10);
	a %= 10;
	printf("个位 : %d\n", a / 1);
	return 0;
}
