/*
Question:给定一个n*m的二维网格 grid ，网格中的每个单元格包含一个非负整数，表示该单元格的代价。机器人以左上角单元格为起始点，每次只能向下或者向右移动一步，直至到达右下角单元格。请返回从左上角到右下角的最小路径和。
return: 最小路径和
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
using namespace std;
int minPathSumDP(vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for(int i=1;i<n;i++)
        dp[i][0] = dp[i-1][0]+grid[i][0];
    for(int i=1;i<m;i++)
        dp[0][i] = dp[0][i-1]+grid[0][i];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j];
        }
    }
    return dp[n-1][m-1];
}
int minPathSumDP2(vector<vector<int>>& grid){
    int n = grid.size(), m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)
                dp[i][j] = grid[i][j];
            else if(i>0&&j==0)
                dp[i][j] = grid[i][j]+dp[i-1][j];
            else if(i==0&&j>0)
                dp[i][j] = grid[i][j]+dp[i][j-1];
            else
                dp[i][j] = grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m)); 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();
    int result1 = minPathSumDP(grid);
    end = std::chrono::system_clock::now();
    cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;
    start = std::chrono::system_clock::now();
    int result2 = minPathSumDP(grid);
    end = std::chrono::system_clock::now();
    cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;
    cout<<"result1:"<<result1<<",result2:"<<result2<<endl;
}