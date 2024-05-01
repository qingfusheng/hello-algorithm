// 题目名称：857. 雇佣 K 名工人的最低成本
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/description
// 题目思路：题解：https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/solutions/1815856/yi-bu-bu-ti-shi-ru-he-si-kao-ci-ti-by-en-1p00/?envType=daily-question&envId=2024-05-02

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> r; 
        for (int i = 0; i < quality.size(); i++) {
            r.push_back({(double)wage[i] / quality[i], quality[i]}); 
        } 

        sort(r.begin(), r.end()); 

        priority_queue<int> hp; 
        double ans = 1e18, sum = 0; 

        for (auto& p : r) {
            hp.push(p.second); 
            sum += p.second; 

            if (hp.size() > k) {
                sum -= hp.top(); 
                hp.pop(); 
            }

            if (hp.size() == k) {
                ans = min(ans, sum * p.first); 
            }
        }

        return ans; 
    }
};

int main(){
    Solution s; 
    vector<int> quality = {10, 20, 5}; 
    vector<int> wage = {70, 50, 30}; 
    int k = 2; 
    cout << s.mincostToHireWorkers(quality, wage, k) << endl; 
    return 0;
}