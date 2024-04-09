// 题目名称：1702. 修改后的最大二进制字符串
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/maximum-binary-string-after-change/description/
// 题目思路：抄的官方题解
// 备注：我们注意到最终结果，至多有一个 000。如果输入字符串中没有 000，则直接返回结果。如果有 000，结果中 000 的位置取决于字符串第一个 000 的位置，之后每多一个 000 便可以向后移动一位。
//      所以我们只需要求出字符串中第一个 000 的下标，以及 000 的出现的个数，即可直接构造结果。


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size(), i = binary.find('0');
        // i为binary中第一个0的index
        // npos是一个常数,用来表示不存在的位置
        if (i == string::npos) {
            return binary;
        }
        int zeros = count(binary.begin(), binary.end(), '0');
        string s(n, '1');
        s[i + zeros - 1] = '0';
        return s;
    }
};

int main(){
    Solution s;
    cout << s.maximumBinaryString("000110") << endl;
    return 0;
}