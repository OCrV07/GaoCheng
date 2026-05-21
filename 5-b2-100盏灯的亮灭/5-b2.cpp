/* 2550332 Ñîô´·« ½»Í¨ */
#include <iostream>
using namespace std;

int main()
{
	bool arr[105];
	for (int i = 1; i <= 100; i++)
		arr[i] = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = i; j <= 100; j += i) {
			arr[j] = !arr[j];
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (arr[i]) {

			if (i != 1)
				cout << " ";
			cout << i;
		}
	}
	cout << endl;

	return 0;
}