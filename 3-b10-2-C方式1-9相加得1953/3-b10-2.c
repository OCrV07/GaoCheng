/* 2550332 杨舸帆 交通 */
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int cnt = 0;
	// 枚举的范围理论上可以进一步优化, 但会比较麻烦, 故不优化了
	// 直接以"三位数"这一条件作为枚举边界
	for (int a = 100; a < 999; a++) {
		// 确保 a 没有重复数字
		int a1 = a / 100;
		int a2 = (a / 10) % 10;
		int a3 = a % 10;
		if (a1 == a2 || a1 == a3 || a2 == a3)
			continue;
		if (a1 == 0 || a2 == 0 || a3 == 0)
			continue;

		for (int b = a + 1; b < 999; b++)
		{
			// 确保 b 没有重复数字
			int b1 = b / 100;
			int b2 = (b / 10) % 10;
			int b3 = b % 10;
			if (b1 == b2 || b1 == b3 || b2 == b3)
				continue;
			if (b1 == 0 || b2 == 0 || b3 == 0)
				continue;

			// 确保 a 和 b 没有重复数字
			if (a1 == b1 || a1 == b2 || a1 == b3)
				continue;
			if (a2 == b1 || a2 == b2 || a2 == b3)
				continue;
			if (a3 == b1 || a3 == b2 || a3 == b3)
				continue;

			int c = 1953 - a - b; // 优化: 第三个数没必要循环找, 直接根据条件枚举答案
			if (c <= a || c <= b) // 不符合升序 
				continue;
			if (c < 100 || c > 999) // c 不是三位数
				continue;

			// 确保 c 没有重复数字
			int c1 = c / 100;
			int c2 = (c / 10) % 10;
			int c3 = c % 10;
			if (c1 == c2 || c1 == c3 || c2 == c3)
				continue;
			if (c1 == 0 || c2 == 0 || c3 == 0)
				continue;

			// 确保 c 和 a 没有重复数字
			if (c1 == a1 || c1 == a2 || c1 == a3)
				continue;
			if (c2 == a1 || c2 == a2 || c2 == a3)
				continue;
			if (c3 == a1 || c3 == a2 || c3 == a3)
				continue;

			// 确保c和b没有重复数字
			if (c1 == b1 || c1 == b2 || c1 == b3)
				continue;
			if (c2 == b1 || c2 == b2 || c2 == b3)
				continue;
			if (c3 == b1 || c3 == b2 || c3 == b3)
				continue;

			cnt++;
			printf("No.%3d : %d+%d+%d=1953\n", cnt, a, b, c);
		}
	}
	printf("total=%d\n", cnt);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
