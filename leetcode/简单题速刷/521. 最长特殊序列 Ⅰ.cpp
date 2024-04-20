#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)return -1;
        return a.length() > b.length() ? a.length():b.length();
    }
};
int main(){
    Solution s;
    cout << s.findLUSlength("aba", "cdc") << endl;
    return 0;
}

/*
// 最长特殊序列（独有的子序列）？难于理解题意。



字符串的子序列的长度不会超过该字符串的长度。若子序列的长度等于字符串的长度，那么子序列就是该字符串。

若两字符串不相同，那么我们可以选择较长的字符串作为最长特殊序列，显然它不会是较短的字符串的子序列。特别地，当两字符串长度相同时（但不是同一字符串），我们仍然可以选择其中的一个字符串作为最长特殊序列，它不会是另一个字符串的子序列。

若两字符串相同，那么任一字符串的子序列均会出现在两个字符串中，此时应返回 −1-1−1。

*/