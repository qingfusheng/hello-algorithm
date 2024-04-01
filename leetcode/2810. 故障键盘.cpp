// 题目名称：2810. 故障键盘
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/faulty-keyboard/description/
// 题目思路：模拟
// 备注：我看题解中有人使用双端队列，不确定跟string比的效率如何，但是确实可行，关于双端队列，我的想法是，根据reverse来交换首尾，从尾部添加元素
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	string finalString(string s) {
		string res = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'i') {
				if (i + 1 < s.length() && s[i + 1] == 'i') {
					i++;
					continue;
				}
				reverse(res.begin(), res.end());  // 在时间复杂度上优于自己实现的reverse
			}
			else {
				res += s[i];
				// res.push_back(s[i]);会降低空间占用，但会cost时间
			}
		}
		return res;
	}
};

int main() {
	string s = "poiinter";
	//string s = "string";
	Solution so = Solution();
	string result = so.finalString(s);
	cout << result << endl;
}