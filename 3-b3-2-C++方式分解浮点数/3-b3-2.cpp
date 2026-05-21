/* 2550332 杨舸帆 交通 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> a;

    double digit_d;
    int digit;
    double divisor = 1000000000.0; 

    digit_d = floor(a / divisor);   
    digit = (int)digit_d;            
    cout << "十亿位 : " << digit << endl;  
    a -= digit_d * divisor;      
    divisor /= 10.0;                 

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "亿位   : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "千万位 : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "百万位 : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "十万位 : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "万位   : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "千位   : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "百位   : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "十位   : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    cout << "圆     : " << digit << endl;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / 0.1 + 1e-3);
    digit = (int)digit_d;
    cout << "角     : " << digit << endl;
    a -= digit_d * 0.1;

    digit_d = floor(a / 0.01 + 1e-3);
    digit = (int)digit_d;
    cout << "分     : " << digit << endl;

    return 0;
}
