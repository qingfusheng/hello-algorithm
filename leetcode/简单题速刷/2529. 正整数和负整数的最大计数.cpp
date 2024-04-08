// 注意二分法的使用
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
// 获取第一个大于0的位置和第一个大于1的位置
    int lowerBound(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (nums[m] >= val) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    int maximumCount(vector<int>& nums) {
        int pos1 = lowerBound(nums, 0);
        int pos2 = lowerBound(nums, 1);
        return max(pos1, (int) nums.size() - pos2);
    }
};

int main(){
    Solution s;
    vector<int> nums{-2,-1,-1,1,2,3};
    cout << s.maximumCount(nums);
}

/*
// 蠢办法
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int fuCount = 0;
        int zeroCount = 0;
        int index = 0;
        while(index<nums.size()){
            if(nums[index]< 0)
                fuCount ++;
            else if(nums[index] == 0)
                zeroCount ++;
            else
                break;
            index += 1;
        }
        return max(fuCount, (int)nums.size() - fuCount - zeroCount);
    }
};

*/