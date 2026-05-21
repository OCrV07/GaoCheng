/* 2550332 杨舸帆 交通 */
#include <iomanip>
#include <iostream>
using namespace std;

/* 每月天数（非闰年） */
const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* 星期 header 模板：28 字符宽（含末尾空格） */
const char WEEKDAY_HEADER[] = "Sun Mon Tue Wed Thu Fri Sat ";

bool is_leap(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int day_of_week(int y, int m, int d)
{
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

void print_spaces(int n)
{
	for (int i = 0; i < n; i++) {
		cout << ' ';
	}
}
void print_month_header(int month)
{
	int name_width = (month < 10) ? 3 : 4;
	int target_pos = 15;
	int left_pad = target_pos - name_width;
	int right_pad = 28 - name_width - left_pad;

	print_spaces(left_pad);
	cout << month << "月";
	print_spaces(right_pad);
}

void print_week(int week_idx, int start_dow, int days)
{
	int first_day = 1 + week_idx * 7 - start_dow; // 本周第一天是几号
	for (int d = 0; d < 7; d++) {
		int day = first_day + d;
		if (day >= 1 && day <= days) {
			cout << setw(4) << left << day;
		}
		else {
			cout << "    ";
		}
	}
}

int main()
{
	int year, per_row;

	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;

	cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
	cin >> per_row;

	cout << year << "年的日历:" << endl;
	cout << endl; // 空一行

	/* 预处理每月信息：1 日星期几、总天数、需要几行 */
	int start_dow[12], month_days[12], month_rows[12];
	for (int m = 1; m <= 12; m++) {
		start_dow[m - 1] = day_of_week(year, m, 1);
		month_days[m - 1] = DAYS_IN_MONTH[m - 1];
		if (m == 2 && is_leap(year))
			month_days[m - 1] = 29;

		// 该月日历行数
		int empty_before = start_dow[m - 1]; // 第1周前面的空位
		month_rows[m - 1] = (empty_before + month_days[m - 1] + 6) / 7;
	}

	/* 按行输出月份组 */
	for (int row_start = 1; row_start <= 12; row_start += per_row) {
		int row_end = row_start + per_row - 1;
		if (row_end > 12)
			row_end = 12;

		int count = row_end - row_start + 1; // 本行月份数

		// 算本行最大行数
		int max_rows = 0;
		for (int m = row_start; m <= row_end; m++) {
			if (month_rows[m - 1] > max_rows)
				max_rows = month_rows[m - 1];
		}

		// 第1行：月份标题
		for (int i = 0; i < count; i++) {
			int m = row_start + i;
			print_month_header(m);
			if (i < count - 1)
				cout << "    ";
		}
		cout << endl;

		// 第2行：星期标题
		for (int i = 0; i < count; i++) {
			cout << WEEKDAY_HEADER;
			if (i < count - 1)
				cout << "    ";
		}
		cout << endl;

		// 第3~8行：日期
		for (int w = 0; w < max_rows; w++) {
			for (int i = 0; i < count; i++) {
				int m = row_start + i;
				if (w < month_rows[m - 1]) {
					print_week(w, start_dow[m - 1], month_days[m - 1]);
				}
				else {
					print_spaces(28);
				}
				if (i < count - 1)
					cout << "    ";
			}
			cout << endl;
		}

		cout << endl; // 每组之间空一行
	}

	cout << endl; // 结尾多空两行（这里再加一个空行，与上面组间的空行合计两个）
	return 0;
}