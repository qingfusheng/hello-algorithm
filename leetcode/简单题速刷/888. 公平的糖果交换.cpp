#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        unordered_set<int> MySet;
        for(int i = 0; i < bobSizes.size();i++){
            MySet.insert(bobSizes[i]);
        }
        for(int i=0;i<aliceSizes.size();i++){
            if(MySet.find(aliceSizes[i] - (sum1 - sum2) / 2) != MySet.end()){
                return vector<int>{aliceSizes[i], aliceSizes[i] - (sum1 - sum2) / 2};
            }
        }   
        return vector<int>{};
    }
};

int main(){
    Solution s;
    vector<int> aliceSizes = {1,1};
    vector<int> bobSizes = {2,2};
    vector<int> ans = s.fairCandySwap(aliceSizes, bobSizes);
    for(int i = 0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
    sum1 - x + y = sum2 - y + x
    x - y = (sum1 - sum2) / 2
    y = x - (sum1 - sum2) / 2
*/