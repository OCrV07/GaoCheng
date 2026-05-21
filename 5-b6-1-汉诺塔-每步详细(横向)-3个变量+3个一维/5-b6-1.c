/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int pegA[10], pegB[10], pegC[10];
int ptrA = 0, ptrB = 0, ptrC = 0;
int cnt = 0;

void clear_line()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

void info()
{
	printf("A:");
	if (pegA[0] != 10)
		printf(" ");
	for (int i = 0; i < 10; i++) {
		if (i < ptrA) {
			printf("%d ", pegA[i]);
		}
		else {
			printf("  ");
		}
	}
	printf("B:");
	if (pegB[0] != 10)
		printf(" ");
	for (int i = 0; i < 10; i++) {
		if (i < ptrB) {
			printf("%d ", pegB[i]);
		}
		else {
			printf("  ");
		}
	}
	printf("C:");
	if (pegC[0] != 10)
		printf(" ");
	for (int i = 0; i < 10; i++) {
		if (i < ptrC) {
			printf("%d ", pegC[i]);
		}
		else {
			printf("  ");
		}
	}
	printf("\n");
}

void push(char peg, int n)
{
	if (peg == 'A')
		pegA[ptrA++] = n;
	else if (peg == 'B')
		pegB[ptrB++] = n;
	else
		pegC[ptrC++] = n;
}

int pop(char peg)
{
	int v;
	if (peg == 'A') {
		v = pegA[--ptrA];
		pegA[ptrA] = 0;
	}
	else if (peg == 'B') {
		v = pegB[--ptrB];
		pegB[ptrB] = 0;
	}
	else {
		v = pegC[--ptrC];
		pegC[ptrC] = 0;
	}
	return v;
}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cnt++;
		printf("第%4d 步(%2d): %c-->%c ", cnt, n, src, dst);
		pop(src);
		push(dst, n);
		info();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cnt++;
		printf("第%4d 步(%2d): %c-->%c ", cnt, n, src, dst);
		pop(src);
		push(dst, n);
		info();
		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n, ret;
	char src, dst;

	do {
		printf("请输入汉诺塔的层数(1-10)\n");
		ret = scanf(" %d", &n);
		if (ret <= 1) {
			clear_line();
		}
	} while (n < 1 || n > 16);

	int valid = 0;
	do {
		printf("请输入起始柱(A-C)\n");
		ret = scanf(" %c", &src);
		if (ret <= 1) {
			clear_line();
		}
		if (src >= 'a' && src <= 'z')
			src = src - 'a' + 'A';

		valid = (src >= 'A' && src <= 'C');
	} while (!valid);

	for (int i = n; i > 0; i--)
		push(src, i);

	do {
		printf("请输入目标柱(A-C)\n");
		ret = scanf(" %c", &dst);
		if (ret <= 1) {
			clear_line();
		}
		if (dst >= 'a' && dst <= 'z')
			dst = dst - 'a' + 'A';

		valid = (dst >= 'A' && dst <= 'C');
		if (valid && dst == src) {
			printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
			valid = 0;
		}
	} while (!valid);

	printf("初始:");
	printf("%*s", 16, "");
	info();
	char tmp = (char)('A' + 'B' + 'C' - src - dst);
	hanoi(n, src, tmp, dst);
}
