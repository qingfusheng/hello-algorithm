#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i, j;
        int count = 0;
        for(i=0;i<board.size();i++){
            for(j=0;j<board[0].size();j++){
                if(board[i][j] == 'R'){
                    for(int index = i - 1; index >= 0;index--){
                        if(board[index][j] == '.')continue;
                        if(board[index][j] == 'B')break;
                        if(board[index][j] == 'p'){
                            count ++;break;
                        }
                    }
                    for(int index = i + 1; index < board.size();index++){
                        if(board[index][j] == '.')continue;
                        if(board[index][j] == 'B')break;
                        if(board[index][j] == 'p'){
                            count ++;break;
                        }
                    }
                    for(int index = j - 1; index >= 0; index--){
                        if(board[i][index] == '.')continue;
                        if(board[i][index] == 'B')break;
                        if(board[i][index] == 'p'){
                            count ++;break;
                        }
                    }
                    for(int index = j + 1; index < board[0].size(); index++){
                        if(board[i][index] == '.')continue;
                        if(board[i][index] == 'B')break;
                        if(board[i][index] == 'p'){
                            count ++;break;
                        }
                    }
                    return count;
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','p','.','.','.','.'},
                                  {'.','.','.','R','.','.','.','p'},
                                  {'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','p','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.'},
                                  {'.','.','.','.','.','.','.','.'}};
    cout << s.numRookCaptures(board) << endl;
    return 0;
}