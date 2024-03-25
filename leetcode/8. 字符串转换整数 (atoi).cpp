// 题目名称：8. 字符串转换整数 (atoi)
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/string-to-integer-atoi/description/
// 题目思路：en做
// 备注：需要考虑溢出的问题
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int myAtoi(string s) {
	bool signal = true;
	int length = s.length();
	int index = 0;
	while (s[index] == ' ')index++;  // 前导空格
	if (s[index] == '+') {
		signal = true;
		index++;
	}
	else if (s[index] == '-') {
		signal = false;
		index++;
	}
	while (s[index] == '0')index++;  // 前导0
	int result = 0;
	while (s[index] >= '0' && s[index] <= '9') {
		if (result > (INT_MAX - (s[index] - '0')) / 10) {
			return signal ? INT_MAX : INT_MIN;
		}
		// 这里是先判断再检测，相比于 溢出以后事后检测 要高效一些。
		// if(result>INT_MAX)
		result = 10 * result + (s[index] - '0');
		index++;
	}
	return signal? result : (-1) * result;
}
int main() {
	string s = "-91283472332";
	int result = myAtoi(s);
	cout << result << endl;
	return 0;
}