/* 2550332 杨舸帆 交通 */

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // 处理出每一位的值(3-b3)
    double a;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> a;

    int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
    double digit_d;
    double divisor = 1000000000.0;

    digit_d = floor(a / divisor);
    shiyi = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    yi = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    qianwan = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    baiwan = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    shiwan = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    wan = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    qian = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    bai = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    shi = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / divisor);
    yuan = (int)digit_d;
    a -= digit_d * divisor;
    divisor /= 10.0;

    digit_d = floor(a / 0.1 + 1e-3);
    jiao = (int)digit_d;
    a -= digit_d * 0.1;

    digit_d = floor(a / 0.01 + 1e-3);
    fen = (int)digit_d;

    // 处理每一位的大写输出
    bool yi_valid, wan_valid, ge_valid; // 某级别是否有值
    bool yi_printed = false, wan_printed = false;   // 某级别是否已输出过, 默认为false
    yi_valid = (shiyi + yi); // 若右侧表达式不为0, 则亿级有值, 设为true. 万级和个级同理
    wan_valid = (qianwan + baiwan + shiwan + wan);
    ge_valid = (qian + bai + shi + yuan);

    cout << "大写结果是:" << endl;

    // 特判 0
    if (!yi_valid && !wan_valid && !ge_valid && !jiao && !fen)
    {
        cout << "零圆整" << endl;
        return 0;
    }

    // 十亿位
    if (shiyi == 1)
        cout << "壹";
    else if (shiyi == 2)
        cout << "贰";
    else if (shiyi == 3)
        cout << "叁";
    else if (shiyi == 4)
        cout << "肆";
    else if (shiyi == 5)
        cout << "伍";
    else if (shiyi == 6)
        cout << "陆";
    else if (shiyi == 7)
        cout << "柒";
    else if (shiyi == 8)
        cout << "捌";
    else if (shiyi == 9)
        cout << "玖";
    if (shiyi != 0)
    {
        cout << "拾";
        yi_printed = true;
    }

    // 亿位
    if (yi == 1)
        cout << "壹";
    else if (yi == 2)
        cout << "贰";
    else if (yi == 3)
        cout << "叁";
    else if (yi == 4)
        cout << "肆";
    else if (yi == 5)
        cout << "伍";
    else if (yi == 6)
        cout << "陆";
    else if (yi == 7)
        cout << "柒";
    else if (yi == 8)
        cout << "捌";
    else if (yi == 9)
        cout << "玖";
    if (yi_valid) // 若亿级有值, 输出"亿"
    {
        cout << "亿";
        yi_printed = true;
    }

    // 千万位
    if (qianwan == 1)
        cout << "壹";
    else if (qianwan == 2)
        cout << "贰";
    else if (qianwan == 3)
        cout << "叁";
    else if (qianwan == 4)
        cout << "肆";
    else if (qianwan == 5)
        cout << "伍";
    else if (qianwan == 6)
        cout << "陆";
    else if (qianwan == 7)
        cout << "柒";
    else if (qianwan == 8)
        cout << "捌";
    else if (qianwan == 9)
        cout << "玖";
    if (qianwan != 0)
    {
        cout << "仟";
        wan_printed = true;
    }
    else if (yi_valid && wan_valid)
        cout << "零";

    // 百万位
    if (baiwan == 1)
        cout << "壹";
    else if (baiwan == 2)
        cout << "贰";
    else if (baiwan == 3)
        cout << "叁";
    else if (baiwan == 4)
        cout << "肆";
    else if (baiwan == 5)
        cout << "伍";
    else if (baiwan == 6)
        cout << "陆";
    else if (baiwan == 7)
        cout << "柒";
    else if (baiwan == 8)
        cout << "捌";
    else if (baiwan == 9)
        cout << "玖";
    if (baiwan != 0)
    {
        cout << "佰";
        wan_printed = true;
    }
    else if (qianwan != 0 && (shiwan != 0 || (shiwan == 0 && wan != 0)))
        cout << "零";

    // 十万位
    if (shiwan == 1)
        cout << "壹";
    else if (shiwan == 2)
        cout << "贰";
    else if (shiwan == 3)
        cout << "叁";
    else if (shiwan == 4)
        cout << "肆";
    else if (shiwan == 5)
        cout << "伍";
    else if (shiwan == 6)
        cout << "陆";
    else if (shiwan == 7)
        cout << "柒";
    else if (shiwan == 8)
        cout << "捌";
    else if (shiwan == 9)
        cout << "玖";
    if (shiwan != 0)
    {
        cout << "拾";
        wan_printed = true;
    }
    else if (wan_printed && baiwan != 0 && wan != 0)
        cout << "零";

    // 万位
    if (wan == 1)
        cout << "壹";
    else if (wan == 2)
        cout << "贰";
    else if (wan == 3)
        cout << "叁";
    else if (wan == 4)
        cout << "肆";
    else if (wan == 5)
        cout << "伍";
    else if (wan == 6)
        cout << "陆";
    else if (wan == 7)
        cout << "柒";
    else if (wan == 8)
        cout << "捌";
    else if (wan == 9)
        cout << "玖";
    if (wan != 0 || wan_valid)
    {
        cout << "万";
        wan_printed = true;
    }

    // 千位
    if (qian == 1)
        cout << "壹";
    else if (qian == 2)
        cout << "贰";
    else if (qian == 3)
        cout << "叁";
    else if (qian == 4)
        cout << "肆";
    else if (qian == 5)
        cout << "伍";
    else if (qian == 6)
        cout << "陆";
    else if (qian == 7)
        cout << "柒";
    else if (qian == 8)
        cout << "捌";
    else if (qian == 9)
        cout << "玖";
    if (qian != 0)
        cout << "仟";
    else if ((yi_printed || wan_printed) && ge_valid)
        cout << "零";

    // 百位
    if (bai == 1)
        cout << "壹";
    else if (bai == 2)
        cout << "贰";
    else if (bai == 3)
        cout << "叁";
    else if (bai == 4)
        cout << "肆";
    else if (bai == 5)
        cout << "伍";
    else if (bai == 6)
        cout << "陆";
    else if (bai == 7)
        cout << "柒";
    else if (bai == 8)
        cout << "捌";
    else if (bai == 9)
        cout << "玖";
    if (bai != 0)
        cout << "佰";
    else if (ge_valid && qian != 0 && (shi != 0 || yuan != 0))
        cout << "零";

    // 十位
    if (shi == 1)
        cout << "壹";
    else if (shi == 2)
        cout << "贰";
    else if (shi == 3)
        cout << "叁";
    else if (shi == 4)
        cout << "肆";
    else if (shi == 5)
        cout << "伍";
    else if (shi == 6)
        cout << "陆";
    else if (shi == 7)
        cout << "柒";
    else if (shi == 8)
        cout << "捌";
    else if (shi == 9)
        cout << "玖";
    if (shi != 0)
        cout << "拾";
    else if (((yi_printed || wan_printed) && qian != 0 && bai != 0 && yuan != 0)
        || (!(yi_printed || wan_printed) && bai != 0 && yuan != 0))
        cout << "零";

    // 个位(圆)
    if (yuan == 1)
        cout << "壹";
    else if (yuan == 2)
        cout << "贰";
    else if (yuan == 3)
        cout << "叁";
    else if (yuan == 4)
        cout << "肆";
    else if (yuan == 5)
        cout << "伍";
    else if (yuan == 6)
        cout << "陆";
    else if (yuan == 7)
        cout << "柒";
    else if (yuan == 8)
        cout << "捌";
    else if (yuan == 9)
        cout << "玖";
    if (yi_valid || wan_valid || ge_valid)
        cout << "圆";

    // 十分位(角)
    if (jiao == 1)
        cout << "壹";
    else if (jiao == 2)
        cout << "贰";
    else if (jiao == 3)
        cout << "叁";
    else if (jiao == 4)
        cout << "肆";
    else if (jiao == 5)
        cout << "伍";
    else if (jiao == 6)
        cout << "陆";
    else if (jiao == 7)
        cout << "柒";
    else if (jiao == 8)
        cout << "捌";
    else if (jiao == 9)
        cout << "玖";
    if (jiao != 0)
        cout << "角";
    else if ((yi_printed || wan_printed || ge_valid) && fen != 0)
        cout << "零";

    // 百分位(分)
    if (fen == 1)
        cout << "壹";
    else if (fen == 2)
        cout << "贰";
    else if (fen == 3)
        cout << "叁";
    else if (fen == 4)
        cout << "肆";
    else if (fen == 5)
        cout << "伍";
    else if (fen == 6)
        cout << "陆";
    else if (fen == 7)
        cout << "柒";
    else if (fen == 8)
        cout << "捌";
    else if (fen == 9)
        cout << "玖";
    if (fen != 0)
        cout << "分";
    else
        cout << "整";

    cout << endl;
}
