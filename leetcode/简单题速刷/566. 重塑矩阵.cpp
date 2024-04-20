#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row_num = mat.size();
        int col_num = mat[0].size();
        vector<vector<int>> result;
        if(row_num * col_num != r * c){
            result = vector<vector<int>> (mat.begin(), mat.end());
            return result;
        }
        vector<int> temp;
        int index = 0;
        for(int i=0;i<row_num;i++){
            for(int j=0;j<col_num;j++){
                temp.push_back(mat[i][j]);
                if(temp.size() == c){
                    result.push_back(temp);
                    temp.clear();
                }
            }
        }
        return result;
    }
};
int main(){
    vector<vector<int>> mat = {{1,2},{3,4}};
    int r = 1;
    int c = 4;
    Solution so = Solution();
    vector<vector<int>> result = so.matrixReshape(mat, r, c);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}