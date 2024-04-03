// 题目名称：67. 二进制求和
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/add-binary/description/
// 题目思路：push_back()和+=的效率，以及 temp % 2 ? '1' : '0'和 '0'+temp%2的效率
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        for(int i=0;i<max(a.length(), b.length());i++){
            int temp1 = i < a.length() ? a[a.length() - i - 1] - '0' : 0;
            int temp2 = i < b.length() ? b[b.length() - i - 1] - '0' : 0;
            int temp = temp1 + temp2 + carry;
            carry = temp / 2;
            res.push_back(temp % 2 ? '1' : '0');
        }
        if(carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    Solution solu = Solution();
    string a = "11";
    string b = "1";
    string res = solu.addBinary(a, b);
    cout << res << endl;
    return 0;
}