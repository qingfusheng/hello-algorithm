#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1) return false;
        unordered_map<int, int>MyMap;
        for (int i = 0; i < nums.size(); i++) {
            if (MyMap.find(nums[i]) == MyMap.end()) {
                MyMap[nums[i]] =i;
            } else {
                if(i - MyMap[nums[i]] <= k){
                    return true;
                }
                MyMap[nums[i]] =i;
            }
        }
        return false;
    }
};

int main(){
    
}

/*
事实上并不需要存pair，只需要存一个int就行了，因为index是有序的
*/