/* 2550332 杨舸帆 交通 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;
	char ch;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;

		// 处理输入错误
		if (ret == 0) {
			// 输入了字母或标点等非法字符，需要清空输入缓冲区
			while ((ch = getchar()) != '\n' && ch != EOF)
				;
		}

		printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}

