#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.size() < 1 || grid[0].size() < 1) return 0;
        //统计所有的立方体数量
        int blocks = 0;
        //统计有多少个面被其他面盖住，那么就在所有的立方体的表面积上减去被盖住的面数×2（因为盖住一个面需要另一个面来盖，所以会损失2个面）；
        int cover = 0;
        for(int i = 0;i < grid.size();++i) {
            for(int j = 0; j < grid[0].size();++j) {
                blocks += grid[i][j];
               //这个是统计当前格子中因为堆叠而盖住了几个面
                cover += grid[i][j] > 1 ? grid[i][j] -1 : 0;
                if(i > 0) {
                    //看看上一行同一列盖住了多少个面
                    cover += min(grid[i-1][j],grid[i][j]);
                }
                if(j > 0) {
                    //看看同一行前一列盖住了几个面
                    cover += min(grid[i][j-1],grid[i][j]);
                }
            }
        }
        return blocks * 6 - cover * 2;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2},{3,4}};
    cout << s.surfaceArea(grid) << endl;
    return 0;
}