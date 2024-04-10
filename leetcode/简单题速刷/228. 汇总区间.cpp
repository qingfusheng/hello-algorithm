#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res = {};
        if(nums.size() == 0){
            return res;
        }
        int cur = nums[0];
        vector<vector<int>> result;
        vector<int> temp {cur};
        for(int i=1;i<nums.size();i++){
            if(nums[i] > 0 && cur < 0){
                result.push_back(temp);
                temp.clear();
                temp.push_back(nums[i]);
                cur = nums[i];
                continue;
            }
            if(nums[i] - cur == 1){
                if(temp.size() <= 1){
                    temp.push_back(nums[i]);
                }else{
                    temp[1] = nums[i];
                }
            }else{
                result.push_back(temp);
                temp.clear();
                temp.push_back(nums[i]);
            }
            cur = nums[i];
        }
        if(temp.size()!=0)
            result.push_back(temp);
        
        // for(auto each: result){
        //     for(auto num: each){
        //         cout<<num<<", ";
        //     }
        //     cout<<endl;
        // }

        for(auto each: result){
            if(each.size() == 1){
                res.push_back(to_string(each[0]));
            }else if(each.size() == 2){
                res.push_back(to_string(each[0]) + "->" + to_string(each[1]));
            }
        }
        return res;
    }
};

int main(){
    
}