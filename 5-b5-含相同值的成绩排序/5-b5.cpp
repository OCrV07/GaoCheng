/* 2550332 杨舸帆 交通 */
#include <iostream>
using namespace std;
int main()
{
	const int MAXN = 1000;
	int scores[1005] = {0};
	int ans[105] = {0};
	int rank[105] = {0}; // 当前分数对应的名次

	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int num;
	int cnt = 0;
	while (cnt < MAXN) {
		cin >> num;
		if (num < 0)
			break;
		scores[cnt] = num;
		ans[num]++;
		cnt++;
	}

	// 检查是否有有效输入
	if (cnt == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;
	for (int i = 0; i < cnt; i++) {
		cout << scores[i];
		if (i != cnt - 1) {
			cout << " ";
		}
		if ((i + 1) % 10 == 0) { // 每10个换行
			cout << endl;
		}
	}
	// 确保最后一行换行
	if (cnt % 10 != 0) {
		cout << endl;
	}

	// 计算每个分数的名次（从高到低，相同分数名次相同，下一名次跳过并列数）
	int cur_rank = 1; // 当前名次（从1开始，1为最高）
	for (int s = 100; s >= 0; s--) {
		if (ans[s] > 0) {		// 该分数有数据
			rank[s] = cur_rank; // 记录当前分数的名次
			cur_rank += ans[s]; // 下一名次 = 当前名次 + 并列人数（跳过并列）
		}
	}

	// 输出分数与名次的对应关系（按名次从高到低）
	cout << "分数与名次的对应关系为:" << endl;
	for (int s = 100; s >= 0; s--) {
		if (ans[s] > 0) {
			int cur = ans[s];
			for (; cur > 0; cur--)
				cout << s << " " << rank[s] << endl;
		}
	}
	return 0;
}