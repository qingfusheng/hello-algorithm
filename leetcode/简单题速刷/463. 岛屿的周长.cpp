#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        int NearEdge = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    count += 1;
                    if(i + 1 < n && grid[i+1][j] == 1){
                        NearEdge += 1;
                    }
                    if(j + 1 < m && grid[i][j+1] == 1){
                        NearEdge += 1;
                    }
                }
            }
        }
        return 4 * count - 2 * NearEdge;
    }
};

int main(){}
/*
 - 所有边的个数 - 相邻边的个数 * 2
 - 本来想的是，方块的个数跟边存在关系（2n+2），但是当有多个方块相邻时不符合
*/
