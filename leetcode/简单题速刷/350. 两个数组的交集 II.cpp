#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> MyMap1, MyMap2;
        for(auto num: nums1){
            if(MyMap1.find(num) == MyMap1.end()){
                MyMap1[num] = 1;
            }else{
                MyMap1[num] += 1;
            }
        }
        for(auto num: nums2){
            if(MyMap2.find(num) == MyMap2.end()){
                MyMap2[num] = 1;
            }else{
                MyMap2[num] += 1;
            }
        }
        vector<int> result;
        for(auto kv: MyMap1){
            if(MyMap2.find(kv.first) != MyMap2.end()){
                int count = min(kv.second, MyMap2[kv.first]);
                while(count-- > 0){
                    result.push_back(kv.first);
                }
            }
        }
        return result;

    }
};
int main(){}

/*
哈希表在面临多元素时花费时间较少，不过占用空间较多。
*/

/*
// 事实上，排序双指针的方法更快，且占用空间更少。
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1 = 0, index2 = 0;
        vector<int> result;
        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] == nums2[index2]){
                result.push_back(nums1[index1]);
                index1++, index2++;
            }else if(nums1[index1] > nums2[index2]){
                index2++;
            }else{
                index1++;
            }
        }
        return result;
    }
};
*/