// 题目名称：1235. 规划兼职工作
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/maximum-profit-in-job-scheduling/description
// 题目思路：动态规划 + 二分查找
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool cmp(const vector<int> &job1, const vector<int> &job2) {
        return job1[1] < job2[1];
    }
public:

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = vector<int>{startTime[i], endTime[i], profit[i]};
        }
        // sort(jobs.begin(), jobs.end(), [](const vector<int> &job1, const vector<int> &job2) -> bool {
        //     return job1[1] < job2[1];
        // });
        
        sort(jobs.begin(), jobs.end(), cmp);

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int> &job) -> bool {
                return st < job[1];
            }) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};

int main(){
    Solution s; 
    vector<int> startTime = {1, 2, 3, 3}; 
    vector<int> endTime = {3, 4, 5, 6}; 
    vector<int> profit = {50, 10, 40, 70}; 
    cout << s.jobScheduling(startTime, endTime, profit) << endl; 
    return 0;
}