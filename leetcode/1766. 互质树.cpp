// 题目名称：1766. 互质数
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/tree-of-coprimes/description/
// 题目思路：（抄的题解）深度优先搜索，对于每个节点，找到与其值互质的最深的祖先节点
// 备注：我本来的想法是，针对于每一个节点，对它的祖先节点进行遍历，找到与其值互质的最深的祖先节点（没尝试，因为这是个图不会写

#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> gcds; 
    vector<vector<int>> tmp;
    vector<vector<int>> g;
    vector<int> dep;
    vector<int> ans;

public:
    void dfs(vector<int> &nums, int x, int depth) {
        dep[x] = depth;
        for (int val : gcds[nums[x]]) {
            if (tmp[val].empty()) {
                continue;
            }
        
            int las = tmp[val].back();
            if (ans[x] == -1 || dep[las] > dep[ans[x]]) {
                ans[x] = las;
            }
        }
        tmp[nums[x]].push_back(x);

        for (int val : g[x]) {
            if (dep[val] == -1) { // 被访问过的点dep不为-1
                dfs(nums, val, depth + 1);
            }
        }

        tmp[nums[x]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        // 初始化
        gcds.resize(51);
        tmp.resize(51);
        ans.resize(n, -1);
        dep.resize(n, -1);
        g.resize(n);

        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (gcd(i, j) == 1) {
                    gcds[i].push_back(j);
                } 
            }
        }
        
        for (const auto &val : edges) {
            g[val[0]].push_back(val[1]);
            g[val[1]].push_back(val[0]);
        }

        dfs(nums, 0, 1);
        
        return ans;
    }
};
/*抄题解了，是真不会啊*/


int main(){
    Solution s;
    vector<int> nums = {5,6,10,2,3,6,15};
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    vector<int> ans = s.getCoprimes(nums, edges);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}