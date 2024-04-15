#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = nums[0], count = nums[0];
        int pre = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == 1){
                if(pre == 1){
                    count++;
                }else{
                    count = 1;
                }
            }else{
                count = 0;
                
            }
            pre = nums[i];
            max_count = max(max_count, count);
        }
        max_count = max(max_count, count);
        return max_count;
    }
};

int main(){
    
}



/*
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/max-consecutive-ones/solutions/603700/zui-da-lian-xu-1de-ge-shu-by-leetcode-so-252a/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/