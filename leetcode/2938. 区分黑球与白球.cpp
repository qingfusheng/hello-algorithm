// 题目名称：2938. 区分黑球与白球
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/separate-black-and-white-balls/description
// 题目思路：可以理解为白球左移的过程，或者黑球右移的过程

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int index2 = 0;
        long long result = 0;
        for(int index1 = 0; index1 < s.length(); index1++){
            if(s[index1] == '0'){
                result += index1 - index2++;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.minimumSteps("100") << endl;
    cout << s.minimumSteps("001") << endl;
    return 0;
}