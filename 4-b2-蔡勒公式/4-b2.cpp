/* 2550332 杨舸帆 交通 */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
    // 1月和2月被视为前一年的13月和14月
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int c = y / 100; // 世纪 - 1
    int k = y % 100; // 年份的后两位
    return ((k + k / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7 + 7) % 7;
}

void output(int n)
{
    switch (n) {
        case 0:
            cout << "星期日" << endl;
            break;
        case 1:
            cout << "星期一" << endl;
            break;
        case 2:
            cout << "星期二" << endl;
            break;
        case 3:
            cout << "星期三" << endl;
            break;
        case 4:
            cout << "星期四" << endl;
            break;
        case 5:
            cout << "星期五" << endl;
            break;
        case 6:
            cout << "星期六" << endl;
            break;
        default:
            cout << "error" << endl;
            break;
    }
}

int main()
{
    // cout << zeller(2014, 4, 2) << endl; // 测试1

    // 输入
    int y, m, d;

    while (1) {
        cout << "请输入年[1900-2100]、月、日：" << endl;
        cin >> y >> m >> d;

        if (cin.fail()) {
            cout << "输入错误，请重新输入" << endl;
            cin.clear();            // 清除错误状态
            cin.ignore(1000, '\n'); // 丢弃输入缓冲区中的错误输入
            continue;
        }

        bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
        if (!((y >= 1900 && y <= 2100) && (m >= 1 && m <= 12))) {
            if (y < 1900 || y > 2100)
                cout << "年份不正确，请重新输入" << endl;
            else if (m < 1 || m > 12)
                cout << "月份不正确，请重新输入" << endl;
        }
        else {
            if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 ||
                 m == 12) &&
                (d >= 1 && d <= 31))
                break;
            else if ((m == 4 || m == 6 || m == 9 || m == 11) &&
                     (d >= 1 && d <= 30))
                break;
            else if (m == 2) {
                if (leap && (d >= 1 && d <= 29))
                    break;
                else if (!leap && (d >= 1 && d <= 28))
                    break;
                else
                    cout << "日不正确，请重新输入" << endl;
            }
            else
                cout << "日不正确，请重新输入" << endl;
        }
    }

    // 输出
    output(zeller(y, m, d));

    return 0;
}
