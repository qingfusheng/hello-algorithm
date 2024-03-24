// 题目名称：5. 最长回文子串
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/longest-palindromic-substring/description/
// 题目思路：DP动态规划 || Manacher's Algorithm（马拉车算法）
// 备注：动规是常规解法，确保状态转移方程即可；Manacher's Algorithm是专门解决最长回文子串问题的线性时间复杂度算法，在时间复杂度上优化了很多,需要注意
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestPalindrome(string s) {
	int n = s.length(), max_length = 0;
	string res = "";
	bool** dp = new bool* [n];
	for (int i = 0; i < n; i++)
		dp[i] = new bool[n];
	for (int l = 0; l < n; l++) {
		for (int i = 0; i + l < n; i++) {
			int j = i + l;
			if (l == 0)
				dp[i][j] = true;
			else if (l == 1) {
				dp[i][j] = (s[i] == s[j]) ? true : false;
			}
			else {
				dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
			}
			if (dp[i][j] && l + 1 > max_length) {
				cout << "i=" << i << ",j=" << j << endl;
				max_length = l;
				res = s.substr(i, l+1);
			}
		}
	}
	return res;
}
string longestPalindrome2(string s) {
    /*
        Manacher's Algorithm（马拉车算法），这是一个专门用于解决最长回文子串问题的线性时间复杂度的算法。
        这个算法首先对字符串进行预处理，然后使用一个数组 p 来记录每个位置的最长回文半径。
        在计算过程中，它会尽可能地利用已经计算出的回文半径来避免不必要的计算。最后，它找出最长的回文半径，然后返回对应的回文子串。
    */

    // 首先将原字符串的每个字符两边都加上特殊字符，这样可以保证所有的回文子串都是奇数长度。
    std::string t = "^#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    t += '$';
    int n = t.size();
    std::vector<int> p(n, 0);  // 存储每个位置的最长回文半径。
    int C = 0, R = 0;    // C 是最近找到的能扩展到右边界 R 的回文串的中心位置，而 R 是这个回文串的右边界。
    for (int i = 1; i < n - 1; ++i) {
        // |-|-|{i_mirror}|-|C|-|{i}|-|R|
        int i_mirror = 2 * C - i;  // C-(i-C), C<i<R，获取i关于C的镜像位置i_mirror
        if (R > i) {
            // R - i 实际上表示的是以 i 为中心，最多能向右扩展的长度。
            // p[i_mirror]是i关于C的镜像位置的最长回文子串，由于不能超出R，所以加入了R-i的限制
            p[i] = std::min(R - i, p[i_mirror]);
        }
        else {
            // i位于右边界R的右边，所以p[i]暂时置为0
            p[i] = 0;
        }

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            // 不断地尝试扩展，直到无法扩展为止。
            ++p[i];
        }

        if (i + p[i] > R) {
            // 如果新的回文串的右边界位置大于 R，我们需要更新 C 和 R 的位置。
            C = i;
            R = i + p[i];
        }
    }

    int max_len = 0, center_index = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i] > max_len) {
            max_len = p[i];
            center_index = i;
        }
    }

    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}
int main() {
	string input = "babac";
	string result = longestPalindrome2(input);
	cout << result;
	return 0;
}