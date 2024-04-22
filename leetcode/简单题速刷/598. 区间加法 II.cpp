#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_row = INT_MAX;
        int min_col = INT_MAX;
        for(auto &op: ops){
            min_row = min(min_row, op[0]);
            min_col = min(min_col, op[1]);
        }
        if(min_row == INT_MAX && min_col == INT_MAX)
            return m * n;
        else
            return min_row * min_col;
    }
    
};
int main(){
    vector<vector<int>> ops = {{2,2},{3,3}};
    Solution so = Solution();
    cout<<so.maxCount(3,3,ops)<<endl;
    return 0;

}
/*
需要注意的是，它的区间是0-op[0]和0-op[1]，所以0,0处的值是最大的
*/

/*
超内存：
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        int max_val = 0;
        for(auto& op: ops){
            for(int i=0;i<op[0];i++){
                for(int j=0;j<op[1];j++){
                    mat[i][j] += 1;
                    max_val = max(max_val, mat[i][j]);
                }
            }
        }
        int count = 0;
        for(auto &row: mat){
            for(auto & col: row){
                if(col == max_val)
                    count++;
            }
        }
        return count;
    }
};
*/