// 题目名称：419. 甲板上的战舰
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/battleships-in-a-board/description
// 题目思路：模拟，应该也算贪心。题目具有误导性，看了半天，大概就是，横着或者竖着连着的X算一个战舰，问有多少个战舰。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X' && (i - 1 < 0 ? true : board[i-1][j] == '.') && (j - 1 < 0 ?true: board[i][j-1] == '.')){
                    result++;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    cout << s.countBattleships(board) << endl;
    return 0;
}