#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int cow(int n,int m){
        if(m > n/2) m = n-m;  
        long long res = 1;
        for (int i = 1; i <= m; ++i){
            res = res * (n - m + i) / i;        // 先乘后除
        }
        return res;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int j=0;j<=rowIndex;j++){
            result.push_back(cow(rowIndex, j));
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> result = s.getRow(5);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}