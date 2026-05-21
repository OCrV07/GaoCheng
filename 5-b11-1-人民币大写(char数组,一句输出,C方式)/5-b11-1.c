/* 2550332 杨舸帆 交通 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
// 可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖"
												 的地方，只允许从这个数组中取值 */
char result[256];							  /* 除result外，不再允许定义任何形式的全局变量 */

// 追加字符串到result末尾
void append_str(const char str[])
{
	int i = 0;
	while (result[i] != '\0')
		i++;

	int j = 0;
	while (str[j] != '\0') {
		result[i + j] = str[j];
		j++;
	}
	result[i + j] = '\0';
}

void daxie(int num, int flag_of_zero)
{
	char ch[3] = {chnstr[2 * num], chnstr[2 * num + 1], '\0'};
	if (num == 0) {
		if (flag_of_zero)
			append_str(ch);
	}
	else {
		append_str(ch);
	}
}

int main()
{
	/* --允许添加需要的内容 --*/
	// 处理出每一位的值(3-b3)
	int ret;
	double a;
	char c;

	while (1) {
		printf("请输入[0-100亿)之间的数字:\n");
		ret = scanf("%lf", &a);
		if (ret == 1 && (a >= 0 && a <= 10000000000))
			break;
		if (ret == 0) {
			// 输入了字母或标点等非法字符，需要清空输入缓冲区
			while ((c = getchar()) != '\n' && c != EOF)
				;
		}
	}

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
	bool yi_printed = false,
		 wan_printed = false; // 某级别是否已输出过, 默认为false
	yi_valid = (shiyi + yi);  // 若右侧表达式不为0, 则亿级有值, 设为true. 万级和个级同理
	wan_valid = (qianwan + baiwan + shiwan + wan);
	ge_valid = (qian + bai + shi + yuan);

	printf("大写结果是:\n");

	// 特判 0
	if (!yi_valid && !wan_valid && !ge_valid && !jiao && !fen) {
		daxie(0, 1);
		append_str("圆整");
		printf("%s\n", result);
		return 0;
	}

	// 十亿位
	daxie(shiyi, 0);
	if (shiyi != 0) {
		append_str("拾");
		yi_printed = true;
	}

	// 亿位
	daxie(yi, 0);
	if (yi_valid) // 若亿级有值, 输出"亿"
	{
		append_str("亿");
		yi_printed = true;
	}

	// 千万位
	daxie(qianwan, yi_valid && wan_valid);
	if (qianwan != 0) {
		append_str("仟");
		wan_printed = true;
	}

	// 百万位
	daxie(baiwan, qianwan != 0 && (shiwan != 0 || (shiwan == 0 && wan != 0)));
	if (baiwan != 0) {
		append_str("佰");
		wan_printed = true;
	}

	// 十万位
	daxie(shiwan, wan_printed && baiwan != 0 && wan != 0);
	if (shiwan != 0) {
		append_str("拾");
		wan_printed = true;
	}

	// 万位
	daxie(wan, 0);
	if (wan != 0 || wan_valid) {
		append_str("万");
		wan_printed = true;
	}

	// 千位
	daxie(qian, (yi_printed || wan_printed) && ge_valid);
	if (qian != 0)
		append_str("仟");

	// 百位
	daxie(bai, ge_valid && qian != 0 && (shi != 0 || yuan != 0));
	if (bai != 0)
		append_str("佰");

	// 十位
	daxie(shi, ((yi_printed || wan_printed) && qian != 0 && bai != 0 && yuan != 0) ||
				   (!(yi_printed || wan_printed) && bai != 0 && yuan != 0));
	if (shi != 0)
		append_str("拾");

	// 个位(圆)
	daxie(yuan, 0);
	if (yi_valid || wan_valid || ge_valid)
		append_str("圆");

	// 十分位(角)
	daxie(jiao, (yi_printed || wan_printed || ge_valid) && fen != 0);
	if (jiao != 0)
		append_str("角");

	// 百分位(分)
	daxie(fen, 0);
	if (fen != 0)
		append_str("分");
	else
		append_str("整");

	printf("%s\n",
		   result); /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出
					 */
	return 0;
}