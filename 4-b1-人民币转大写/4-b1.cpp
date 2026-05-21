/* 2550332 杨舸帆 交通 */
#include <cmath>
#include <iostream>
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	if (num == 0) {
		if (flag_of_zero)
			cout << chnstr[num];
	}
	else {
		cout << chnstr[num];
		//}
		///* 不允许对本函数做任何修改 */
		// switch (num) {
		//	case 0:
		//		if (flag_of_zero) // 此标记什么意思请自行思考
		//			cout << "零";
		//		break;
		//	case 1:
		//		cout << "壹";
		//		break;
		//	case 2:
		//		cout << "贰";
		//		break;
		//	case 3:
		//		cout << "叁";
		//		break;
		//	case 4:
		//		cout << "肆";
		//		break;
		//	case 5:
		//		cout << "伍";
		//		break;
		//	case 6:
		//		cout << "陆";
		//		break;
		//	case 7:
		//		cout << "柒";
		//		break;
		//	case 8:
		//		cout << "捌";
		//		break;
		//	case 9:
		//		cout << "玖";
		//		break;
		//	default:
		//		cout << "error";
		//		break;
		// }
	}

	int main()
	{
		/* 按需完成 */
		// 处理出每一位的值(3-b3)
		double a;
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> a;

		int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao,
			fen;
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
		yi_valid =
			(shiyi +
			 yi); // 若右侧表达式不为0, 则亿级有值, 设为true. 万级和个级同理
		wan_valid = (qianwan + baiwan + shiwan + wan);
		ge_valid = (qian + bai + shi + yuan);

		cout << "大写结果是:" << endl;

		// 特判 0
		if (!yi_valid && !wan_valid && !ge_valid && !jiao && !fen) {
			daxie(yuan, 1); // 输出"零"
			cout << "圆整" << endl;
			return 0;
		}

		// 十亿位
		daxie(shiyi, 0);
		if (shiyi != 0) {
			cout << "拾";
			yi_printed = true;
		}

		// 亿位
		daxie(yi, 0);
		if (yi_valid) // 若亿级有值, 输出"亿"
		{
			cout << "亿";
			yi_printed = true;
		}

		// 千万位
		daxie(qianwan, yi_valid && wan_valid);
		if (qianwan != 0) {
			cout << "仟";
			wan_printed = true;
		}

		// 百万位
		daxie(baiwan,
			  qianwan != 0 && (shiwan != 0 || (shiwan == 0 && wan != 0)));
		if (baiwan != 0) {
			cout << "佰";
			wan_printed = true;
		}

		// 十万位
		daxie(shiwan, wan_printed && baiwan != 0 && wan != 0);
		if (shiwan != 0) {
			cout << "拾";
			wan_printed = true;
		}

		// 万位
		daxie(wan, 0);
		if (wan != 0 || wan_valid) {
			cout << "万";
			wan_printed = true;
		}

		// 千位
		daxie(qian, (yi_printed || wan_printed) && ge_valid);
		if (qian != 0)
			cout << "仟";

		// 百位
		daxie(bai, ge_valid && qian != 0 && (shi != 0 || yuan != 0));
		if (bai != 0)
			cout << "佰";

		// 十位
		daxie(shi, ((yi_printed || wan_printed) && qian != 0 && bai != 0 &&
					yuan != 0) ||
					   (!(yi_printed || wan_printed) && bai != 0 && yuan != 0));
		if (shi != 0)
			cout << "拾";

		// 个位(圆)
		daxie(yuan, 0);
		if (yi_valid || wan_valid || ge_valid)
			cout << "圆";

		// 十分位(角)
		daxie(jiao, (yi_printed || wan_printed || ge_valid) && fen != 0);
		if (jiao != 0)
			cout << "角";

		// 百分位(分)
		daxie(fen, 0);
		if (fen != 0)
			cout << "分";
		else
			cout << "整";

		cout << endl;
	}
