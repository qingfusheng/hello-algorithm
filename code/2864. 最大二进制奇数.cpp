// 题目名称：2864. 最大二进制奇数
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/maximum-odd-binary-number/description
// 题目思路：一种新操作：string(count, char)，用于生成count个char字符的字符串

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        string res = "1";
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                res.push_back('0');
            }else if(s[i] == '1'){
                count += 1;
            }
        }
        while(--count)res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    Solution solu = Solution();
    string s = "1101";
    string res = solu.maximumOddBinaryNumber(s);
    cout << res << endl;
    return 0;
}