#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> MySet(nums1.begin(), nums1.end());
        unordered_set<int> MySet2(nums2.begin(), nums2.end());
        vector<int> result;
        for(const auto &element : MySet){
            if(MySet2.find(element) != MySet2.end())
                result.push_back(element);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums1{1, 2, 2, 1}, nums2{2, 2};
    vector<int> result = s.intersection(nums1, nums2);
    for(const auto &element : result)
        cout << element << " ";
    cout << endl;
    return 0;
}
/*
也可以排序+双指针
*/