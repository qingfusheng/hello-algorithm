// 题目名称：华科大-03. 数学难题
// 题目来源：LeetCode Exam
// 题目难度：Medium
// 题目链接：https://leetcode.cn/contest/hust_1024_2023/problems/fwbmtF/
// 题目思路：就en做
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<int> cal_x_and_num(string s) {
	int left_x = 0;
	int left_num = 0;
	string temp = "";
	bool is_x = false;
	bool signal = true;
	s += '#';
	int index_begin = 0;
	int index_end = s.length() - 1;
	for (int i = index_begin; i <= index_end; i++) {
		if (isdigit(s[i])) {
			temp += s[i];
		}
		if (s[i] == 'x') {
			if (temp == "")
				temp = "1";
			if (!signal)
				temp = "-" + temp;
			left_x += stoi(temp);
			temp = "";
			is_x = true;
			
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '#') {
			if (i == index_begin) {
				signal = false;
				continue;
			}
			if (is_x) {
				is_x = false;
			}
			else {
				if (!signal)
					temp = "-" + temp;
				left_num += stoi(temp);
				temp = "";
			}

			if (s[i] == '+') {
				signal = true;
			}
			else {
				signal = false;
			}
		}
	}
	return vector<int>{left_x, left_num};
}
string mathProblem(string s) {
	int equal_index = s.find('=');
	vector<int> temp1 = cal_x_and_num(s.substr(0, equal_index));
	vector<int> temp2 = cal_x_and_num(s.substr(equal_index + 1, s.length()));
	int left_x = temp1[0], right_x = temp2[0], left_num = temp1[1], right_num = temp2[1];
	cout << left_x << "," << left_num << "," << right_x << "," << right_num << endl;
	if (left_x == right_x)
		if (left_num == right_num) {
			return "Infinite solutions";
		}
		else {
			return "No solution";
		}
	if (left_num == right_num)
		return "x=0";
	return "x=" + to_string((right_num - left_num) / (left_x - right_x));



}
int main() {
	string n = "1+1=x";
	string result = mathProblem(n);
	cout << result;
}
