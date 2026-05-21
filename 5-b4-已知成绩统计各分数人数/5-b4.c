/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const int MAXN = 1000;
	int scores[1005] = {0};
	int ans[105] = {0};

	printf("请输入成绩（最多1000个），负数结束输入\n");
	int num;
	int cnt = 0;
	while (cnt < MAXN) {
		scanf("%d", &num);
		if (num < 0)
			break;
		scores[cnt] = num;
		ans[num]++;
		cnt++;
	}

	// 检查是否有有效输入
	if (cnt == 0) {
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d", scores[i]);
		if (i != cnt - 1) {
			printf(" ");
		}
		if ((i + 1) % 10 == 0) { // 每10个换行
			printf("\n");
		}
	}
	// 确保最后一行换行
	if (cnt % 10 != 0) {
		printf("\n");
	}

	printf("分数与人数的对应关系为:\n");
	// 按分数从高到低（100到0）遍历
	for (int s = 100; s >= 0; s--) {
		if (ans[s] > 0) {
			printf("%d %d\n", s, ans[s]);
		}
	}
	return 0;
}