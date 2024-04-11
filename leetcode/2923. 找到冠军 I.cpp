#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int j=0;j<n;j++){
            bool isS = true;
            for(int i = 0;i < n;i++){
                if(grid[i][j] == 1){
                    isS = false;
                }
            }
            if(isS)
                return j;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    cout << s.findChampion(grid) << endl;
}

/*
// 直接求SUM的速度更快
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (accumulate(grid[i].begin(), grid[i].end(), 0) == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

*/