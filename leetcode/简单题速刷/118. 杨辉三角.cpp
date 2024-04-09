#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int cow(int n,int m){
        if(m > n/2) m = n-m;  
        int res = 1;
        for (int i = 1; i <= m; ++i){
            res = res * (n - m + i) / i;        // 先乘后除
        }
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result {};
        for(int i=0;i<numRows;i++){
            vector<int> temp{};
            for(int j=0;j<=i;j++){
                temp.push_back(cow(i, j));
            }
            result.push_back(temp);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> result = s.generate(5);
    for(auto i:result){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}