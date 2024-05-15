// 题目名称：2589. 完成所有任务的最少时间
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/description
// 题目思路：** 排序+贪心 **

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
	}
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), cmp);
        vector<int> run(tasks[n - 1][1] + 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            //cout << "temp:" << accumulate(run.begin() + start, run.begin() + end + 1, 0) << endl;
            duration -= accumulate(run.begin() + start, run.begin() + end + 1, 0);
            res += max(duration, 0);
            //cout<<"res:"<<res<<endl;
            for (int j = end; j >= 0 && duration > 0; j--) {
                if (run[j] == 0) {
                    duration--;
                    run[j] = 1;
                }
            }
   //         cout<<"run:";
   //         for (int i = 0; i < run.size(); i++) {
			//	cout<<run[i]<<" ";
			//}
   //         cout << endl;
        }
        return res;
    }
};

int main() {
    Solution sol;
	vector<vector<int>> tasks = { {2,3,1} ,{4,5,1},{1,5,2} };
	int result = sol.findMinimumTime(tasks);
	cout<< result << endl;
	return 0;
}