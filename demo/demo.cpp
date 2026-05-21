#include <iostream>
using namespace std;

int main()
{
	// 直接用GBK编码值构造"你"字
	unsigned char gbk_ni[] = {0xC4, 0xE3, 0x00}; // "你"的GBK编码

	cout << gbk_ni << endl; // 如果环境是GBK，输出：你

	return 0;
}