// 题目名称：2244. 完成所有任务需要的最少轮数
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/description
// 题目思路：哈希+贪心

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> MyMap;
        for (auto& task : tasks) {
            MyMap[task] ++;
        }
        int count = 0;
        for (auto& [key, value] : MyMap) {
            if (value == 1)
                return -1;
            else 
                count += (value+2)/3;
        }
        return count;
    }
};

int main() {
    Solution s;
	vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };
	cout << s.minimumRounds(tasks) << endl;
	return 0;
}