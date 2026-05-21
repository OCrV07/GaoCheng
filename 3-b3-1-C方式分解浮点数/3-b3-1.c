/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main()
{
    double a;
    printf("请输入[0-100亿)之间的数字:\n");
    scanf("%lf", &a);

    double digit_d;
    int digit;
    double divisor = 1000000000.0;  

	digit_d = floor(a / divisor);   
    digit = (int)digit_d;          
    printf("十亿位 : %d\n", digit);  
    a -= digit_d * divisor;          
    divisor /= 10.0;                

    // 循环不能用, 故复制粘贴
    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("亿位   : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("千万位 : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("百万位 : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("十万位 : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("万位   : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("千位   : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("百位   : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("十位   : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    digit = (int)digit_d;
    printf("圆     : %d\n", digit);
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / 0.1 + 1e-3);
    digit = (int)digit_d;
    printf("角     : %d\n", digit);
    a -= digit_d * 0.1;

    digit_d = floor(a / 0.01 + 1e-3);
    digit = (int)digit_d;
    printf("分     : %d\n", digit);

    return 0;
}
