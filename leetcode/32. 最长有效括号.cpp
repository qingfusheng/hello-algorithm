// 题目名称：32. 最长有效括号
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/longest-valid-parentheses/description/
// 题目思路：栈，动态规划
// 备注：栈的思想中需要注意的是 "()(()" 和 "()(())"，主要是前者，如何来标记这个长度的问题
#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 栈的思想，需要注意的是 "()(()" 和 "()(())"，主要是前者，如何来标记这个长度的问题
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1); // 初始化栈，栈底标志为-1
        int max_len = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    max_len = max(max_len, i - stk.top());
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution solu;
    string s = "()(()";
    int result = solu.longestValidParentheses(s);
    cout << result << endl;
    return 0;
}

/*
// 动态规划的思想，没看太懂，再琢磨琢磨
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<int> dp(n, 0);
        int max_len = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max_len = max(max_len, dp[i]);
            }
        }

        return max_len;
    }
};
*/