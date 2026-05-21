/* 2550332 杨舸帆 交通 */
#include <iostream>
using namespace std;

int main()
{

	int arr[25];
	int insertNum;
	int cnt = 0;
	int num;

	// Line1: 数据输入提示
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;

	// Line2: 键盘输入的若干数据
	while (cnt < 20) {
		cin >> num;
		if (num <= 0) {
			break;
		}
		arr[cnt] = num;
		cnt++;
	}

	// 如果一个有效数据都没有，则输出”无有效输入”后结束
	if (cnt == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	if (cnt >= 20) {
		cin.ignore(1024, '\n');
	}

	// Line3: 原数组输出提示
	cout << "原数组为：" << endl;

	// Line4: 原数组（插入前）的内容
	for (int i = 0; i < cnt; i++) {
		cout << arr[i];
		if (i < cnt - 1) {
			cout << " ";
		}
	}
	cout << endl;

	// Line5: 要插入数据的输入提示
	cout << "请输入要插入的正整数" << endl;

	// Line6: 键盘输入的要插入的正整数
	cin >> insertNum;

	// 寻找插入位置
	int insertIndex = cnt; // 默认插入到末尾
	for (int i = 0; i < cnt; i++) {
		if (arr[i] > insertNum) {
			insertIndex = i;
			break;
		}
	}

	// 将插入位置及之后的元素后移
	for (int i = cnt; i > insertIndex; i--) {
		arr[i] = arr[i - 1];
	}

	// 插入新元素
	arr[insertIndex] = insertNum;

	// Line7: 新数组输出提示
	cout << "插入后的数组为：" << endl;

	// Line8: 新数组（插入后）的内容
	for (int i = 0; i < cnt + 1; i++) {
		cout << arr[i];
		if (i < cnt) {
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}
