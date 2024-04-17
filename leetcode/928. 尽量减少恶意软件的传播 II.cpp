// 题目名称：928. 尽量减少恶意软件的传播 II
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimize-malware-spread-ii/description
// 题目思路：
// 备注：
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        unordered_set<int> st(initial.begin(), initial.end());
        vector<int> vis(graph.size());
        int node_id, size;
        function<void(int)> dfs = [&](int x) {
            vis[x] = true;
            size++;
            for (int y = 0; y < graph[x].size(); y++) {
                if (graph[x][y] == 0) {
                    continue;
                }
                if (st.contains(y)) {
                    // 按照 924 题的状态机更新 node_id
                    // 注意避免重复统计，例如上图中的 0 有两条不同路径可以遇到 1
                    if (node_id != -2 && node_id != y) {
                        node_id = node_id == -1 ? y : -2;
                    }
                } else if (!vis[y]) {
                    dfs(y);
                }
            }
        };

        unordered_map<int, int> cnt;
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] || st.contains(i)) {
                continue;
            }
            node_id = -1;
            size = 0;
            dfs(i);
            if (node_id >= 0) { // 只找到一个在 initial 中的节点
                // 删除节点 node_id 可以让 size 个点不被感染
                cnt[node_id] += size;
            }
        }

        int max_cnt = 0;
        int min_node_id = 0;
        for (auto [node_id, c] : cnt) {
            if (c > max_cnt || c == max_cnt && node_id < min_node_id) {
                max_cnt = c;
                min_node_id = node_id;
            }
        }
        return cnt.empty() ? ranges::min(initial) : min_node_id;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> initial = {0,1};
    cout << s.minMalwareSpread(graph, initial) << endl;
    return 0;
}