// 第一次见这么简单的每日一题
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(auto &hour: hours){
            if(hour >= target)count++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> hours = {0,1,2,3,4};
    int target = 2;
    cout << s.numberOfEmployeesWhoMetTarget(hours, target) << endl;
    return 0;
}