// 题目名称：924. 尽量减少恶意软件的传播
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimize-malware-spread/description/
// 题目思路：并查集
// 备注：（抄的题解，待补充）
#include <bits/stdc++.h>
using namespace std;
// 困难题，并查集

class Solution {
public:
// copy
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {

        int n = graph.size();

        // 构建并查集
        // 1.并查数组
        int p[n], size[n];
        // 2.模板函数
        function<int(int)> find = [&](int x) {
            if (p[x] != x)p[x] = find(p[x]);
            return p[x];
        };
        function<void(int, int)> unite = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a == b)return;
            if (size[a] < size[b])swap(a, b);
            p[b] = a, size[a] += size[b];
        };
        // 3.初始化
        for (int i = 0; i < n; i++) {
            p[i] = i, size[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (graph[i][j])unite(i, j);
            }
        }

        // initial数组去重
        int cnt[n];
        memset(cnt, 0, sizeof cnt);
        for (int e: initial)cnt[find(e)]++;   // 被感染且唯一的点的对应的cnt值为1

        // 找到所在连通块点数最大的点（唯一点）
        int curSize = 0, idx = -1;
        for (int e: initial) {
            int rt = find(e);
            if (cnt[rt] == 1) {         // 被感染且唯一的点
                if (curSize < size[rt])curSize = size[rt], idx = e;
                else if (curSize == size[rt] && e < idx)idx = e;
            }
        }

        // 没有唯一点
        if (idx == -1) {
            idx = INT_MAX;
            for (int e: initial)
                if (e < idx)idx = e;
        }

        return idx;
    }
};
int main(){
    Solution s;
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> initial = {0,1};
    cout << s.minMalwareSpread(graph, initial) << endl;
    return 0;
}