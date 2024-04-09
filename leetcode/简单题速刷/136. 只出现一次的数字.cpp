#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(auto num: nums)
            n = n^num;
        return n;
    }
};
int main(){
    
}