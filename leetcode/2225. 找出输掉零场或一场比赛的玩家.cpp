// 题目名称：2225. 找出输掉零场或一场比赛的玩家
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/find-players-with-zero-or-one-losses/description
// 题目思路：哈希表
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>MyMap;
        for(auto &match: matches){
            if(!MyMap[match[0]]){
                MyMap[match[0]] = 0;
            }
            if(!MyMap[match[1]]){
                MyMap[match[1]] = 1;
            }else{
                MyMap[match[1]] += 1;
            }
        }
        vector<vector<int>> result(2, vector<int>{});
        for(auto&kv: MyMap){
            if(kv.second < 2){
                result[kv.second].push_back(kv.first);
            }
        }
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        return result;
    }
};

int main(){
    Solution so = Solution();
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> result = so.findWinners(matches);
    for(auto &res: result){
        for(auto &r: res){
            cout << r << " ";
        }
        cout << endl;
    }
}