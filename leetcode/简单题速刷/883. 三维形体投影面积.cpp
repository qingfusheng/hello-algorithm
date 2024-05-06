#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid.size();
        for(int i = 0;i<m;i++){
            int max_val = 0;
            for(int j = 0;j<n;j++){
                if(grid[i][j] != 0) ans++;
                max_val = max(grid[i][j], max_val);
            }
            ans += max_val;
        }

        for(int j = 0;j<n;j++){
            int max_val = 0;
            for(int i =0;i<m;i++){
                max_val = max(max_val, grid[i][j]);
            }
            ans += max_val;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2},{3,4}};
    cout << s.projectionArea(grid) << endl;
    return 0;
}