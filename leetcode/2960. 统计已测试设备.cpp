#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int level = 0;
        int count = 0;
        for(auto &num: batteryPercentages){
            if(num > level){
                count ++;
                level ++;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> batteryPercentages = {1, 3, 2, 2, 2, 1, 4, 5};
    cout << s.countTestedDevices(batteryPercentages) << endl;
    return 0;
}