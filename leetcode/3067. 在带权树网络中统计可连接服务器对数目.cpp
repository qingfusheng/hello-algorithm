#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int signalSpeed;
    vector<vector<pair<int, int>>> g;
    int dfs(int x, int fa, int sum){
        int cnt = sum % signalSpeed == 0;
        for(auto &[y, wt]:g[x]){
            if(y != fa){
                cnt += dfs(y, x, sum + wt);
            }
        }
        return cnt;
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        this->signalSpeed = signalSpeed;
        int n = edges.size() + 1;
        g = vector<vector<pair<int, int>>>(n);
        for(vector<int>& e: edges){
            int x = e[0], y = e[1], wt = e[2];
            g[x].push_back({y, wt});
            g[y].push_back({x, wt});
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (auto &[y, wt] : g[i]) {
                int cnt = dfs(y, i, wt);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    vector<int> res = s.countPairsOfConnectableServers(edges, 2);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}