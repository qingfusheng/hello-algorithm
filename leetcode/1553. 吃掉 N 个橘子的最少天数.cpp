// 题目名称：1553. 吃掉 N 个橘子的最少天数
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges/description
// 题目思路：乍一眼看上去，这道题目是一个典型的动态规划问题，但是动规会超时，因此需要剪枝和记忆化操作。

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }else{
            return 1 + min(minDays(n/2) + n % 2, minDays(n/3) + n % 3);
        }
    }
};

int main(){
    Solution s;
    cout << s.minDays(10) << endl;
    return 0;
}

/*
    关于记忆化操作，python中是通过lru_cache装饰器实现的。
class Solution:
    @lru_cache(None)
    def minDays(self, n: int) -> int:
        if n==0:
            return 0
        if n==1:
            return 1
        return 1+min(self.minDays(n//2)+n%2, self.minDays(n//3)+n%3)
*/