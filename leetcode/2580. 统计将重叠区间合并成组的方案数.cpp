// 题目名称：2580. 统计将重叠区间合并成组的方案数
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/description
// 题目思路：边界问题，排序+贪心
// 备注：也可以把所有的边界都挪列出来，但是会timeout

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int countWays(vector<vector<int>>& ranges) {
    if(ranges.size()==0)
		return 0;
    int mod = pow(10, 9) + 7;
	sort(ranges.begin(),ranges.end());
	long long result = 2;
    int left = ranges[0][0], right = ranges[0][1];
    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i][0] <= right) {
            if (ranges[i][1] > right) {
                right = ranges[i][1];
            }
        }
        else {
            result = (result * 2) % mod;
            left = ranges[i][0];
            right = ranges[i][1];
        }
    }
    return result;
}


int main() {
	vector<vector<int>> range{ {1,3},{10,20},{2,5},{4,8} };
	int result = countWays(range);
	cout<<result<< endl;
}


/*
//  想到了排序，但似乎没想到可以直接贪心,维护结果数组很明显会超时
class Solution {
public:
    int defined_pow(int a, int b, int mod) {
            long long result = 1;
            for (int i = 0; i < b; i++) {
            result = (result * a) % mod;
        }
        return result;
    }
    int countWays(vector<vector<int>>& ranges) {
        if (ranges.size() == 0)
            return 0;
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> results{};
        bool insert;
        for (auto range : ranges) {
            insert = true;
            for (int i = 0; i < results.size();i++) {
                if (!(range[1] < results[i][0] || range[0] > results[i][1])) {
                    insert = false;
                    results[i][0] = min(results[i][0], range[0]);
                    results[i][1] = max(results[i][1], range[1]);
                    break;
                }
            }
            if (insert) {
                results.push_back(range);
            }
        }
        return defined_pow(2, results.size(), pow(10, 9)+7);
    }
};
*/