#include <iostream>
using namespace std;

int main()
{
	int a = 8, n = 13;
	cout << (n %= a %= 4) << endl;
}
