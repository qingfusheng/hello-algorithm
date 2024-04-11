#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        cout<<"size:"<<result.size()<<endl;
        for(int i=1;i<=n;i++){
            // 类似于DP的做法
            result[i] = (i&1==1) ? result[i>>1] + 1 : result[i>>1];
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> result = s.countBits(5);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}

/*
// 暴力解法，O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++){
            int temp = i, count = 0;
            while(temp!=0){
                count += temp & 1;
                temp = temp >> 1;
            }
            result.push_back(count);
        }
        return result;
    }
};
*/


// 判断一个数是不是2的幂：y & (y − 1) == 0