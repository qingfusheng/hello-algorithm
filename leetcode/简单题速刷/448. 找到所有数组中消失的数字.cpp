#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// 又慢又蠢
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> MyMap;
        for(int i=1;i<=nums.size();i++)
            MyMap[i] = 1;
        for(int i = 0;i<nums.size();i++)
            if(MyMap.find(nums[i]) != MyMap.end())
                if(MyMap[nums[i]] == 1)
                    MyMap[nums[i]]-=1;
        vector<int> result;
        for(auto &kv: MyMap){
            if(kv.second == 1)result.push_back(kv.first);
        }
        return result;
        
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = s.findDisappearedNumbers(nums);
    for(auto &i: result)
        cout<<i<<", ";
    cout<<endl;
}

/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int index1 = 0, index2 = 1;
        while(index2 <= nums.size()){
            if(index1 >= nums.size()){
                result.push_back(index2);
                index2++;
            }else{
                if(nums[index1] < index2){
                    index1++;
                }else if(nums[index1] == index2){
                    index1++,index2++;
                }else{
                    result.push_back(index2);
                    index2++;
                }
            }
        }
        return result;
    }
};
*/