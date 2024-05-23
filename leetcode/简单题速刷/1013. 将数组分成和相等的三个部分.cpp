#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total % 3 != 0)return false;
        int count = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum == total / 3){
                count += 1;
                sum = 0;
            }
        }
        return count >= 3;
    }
};

int main(){
    Solution s;
    vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
    cout << s.canThreePartsEqualSum(arr) << endl;
    return 0;
}

/*
    比较简单的是：这三部分是连续的
*/