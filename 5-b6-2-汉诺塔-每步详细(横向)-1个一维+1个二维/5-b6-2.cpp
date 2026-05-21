/* 2550332 杨舸帆 交通 */

#include <iomanip>
#include <iostream>
using namespace std;

int index[3][10];
int ptr[3] = {0};
int cnt = 0;

// 清空输入行
void clear_line()
{
	char ch;
	while ((ch = cin.get()) != '\n' && ch != EOF)
		;
}

void info()
{
	for (int k = 0; k < 3; k++) {
		cout << char('A' + k) << ":";
		if (index[k][0] != 10)
			cout << " ";
		for (int i = 0; i < 10; i++) {
			if (i < ptr[k]) {
				cout << index[k][i] << " ";
			}
			else {
				cout << "  ";
			}
		}
	}
	cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cnt++;
		cout << "第" << setw(4) << right << cnt << " 步(" << setw(2) << right
			 << n << "): " << src << "-->" << dst << " ";
		index[src - 'A'][--ptr[src - 'A']] = 0;
		index[dst - 'A'][ptr[dst - 'A']++] = n;
		info();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cnt++;
		cout << "第" << setw(4) << right << cnt << " 步(" << setw(2) << right
			 << n << "): " << src << "-->" << dst << " ";
		index[src - 'A'][--ptr[src - 'A']] = 0;
		index[dst - 'A'][ptr[dst - 'A']++] = n;
		info();
		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n;
	char src, dst;

	// 输入层数
	do {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			clear_line();
		}
		else {
			clear_line();
		}
	} while (n < 1 || n > 16);

	// 输入起始柱
	int valid = 0;
	do {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
		if (src >= 'a' && src <= 'z')
			src -= 32;
		valid = (src >= 'A' && src <= 'C');
	} while (!valid);

	// 初始化起始柱
	for (int i = n; i > 0; i--)
		index[src - 'A'][ptr[src - 'A']++] = i;

	// 输入目标柱
	valid = 0;
	do {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (cin.fail()) {
			cin.clear();
			clear_line();
			continue;
		}
		else {
			clear_line();
		}
		if (dst >= 'a' && dst <= 'z')
			dst -= 32;
		valid = (dst >= 'A' && dst <= 'C');
		if (valid && dst == src) {
			cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同"
				 << endl;
			valid = 0;
		}
	} while (!valid);

	// 初始状态输出
	cout << "初始:";
	cout << setw(16) << setfill(' ') << "";
	info();

	char tmp = char('A' + 'B' + 'C' - src - dst);
	hanoi(n, src, tmp, dst);

	return 0;
}