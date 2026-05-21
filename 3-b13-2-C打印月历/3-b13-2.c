/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    // 所有逻辑和C++方式没有区别, 故删去所有注释
    int y, m;
    int ret;
    char ch;

    while (1) {
        printf("请输入年份(2000-2030)和月份(1-12) : ");
        ret = scanf("%d %d", &y, &m);
        if (ret == 2 && y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
            break;
        if (ret != 2) {
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
        printf("输入非法，请重新输入\n");
    }

    int leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;

    int d;
    while (1) {
        printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", y, m);
        ret = scanf("%d", &d);
        if (ret == 1 && d >= 0 && d <= 6)
            break;
        if (ret == 0) {
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
        printf("输入非法，请重新输入\n");
    }
    printf("\n");

    printf("%d年%d月的月历为: \n", y, m);
    printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

    int day1_space = d * 8;
    printf("%*s", day1_space, "");

    for (int day = 1; day <= 31; day++) {
        if (m == 2) {
            if (leap && day > 29) 
                break;
            if (!leap && day > 28) 
                break;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (day == 31) 
                break;
        }
        printf("%4d%4s", day, "");
        if ((d + day - 1) % 7 == 6) 
            printf("\n");
    }

    printf("\n");
    return 0;
}
