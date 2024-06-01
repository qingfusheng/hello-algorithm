#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> MySet;
        for(int& num: candyType){
            MySet.insert(num);
        }
        return min(candyType.size() / 2, MySet.size());
    }
};

int main(){
    Solution s;
    vector<int> candyType = {1,1,2,2,3,3};
    cout << s.distributeCandies(candyType) << endl;
    return 0;
}