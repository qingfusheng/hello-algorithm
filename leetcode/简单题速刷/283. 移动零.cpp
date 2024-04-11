#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// 双指针
    void moveZeroes(vector<int>& nums) {
        int i = 0 , j = 0;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        for(i=j;i<nums.size();i++)
            nums[i] = 0;
    }
};

int main(){

}

/*
// 最笨的办法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index1 = 0 , index2 = 0;
        while(index1 < nums.size()){
            while(index1 < nums.size() && nums[index1] != 0){index1 ++;};
            if(index1 >= nums.size())break;
            index2 = index1 + 1;
            if(index2 >= nums.size())break;
            while(index2 < nums.size() && nums[index2] == 0){index2 ++;}
            if(index2 >= nums.size())break;
            swap(nums[index1], nums[index2]);  // 并不需要swap，只需要单向赋值
            cout<<"swap:"<<index1<<", "<<index2<<endl;
            index1++;
        }
    }
};
*/