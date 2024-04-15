#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        for(int i=0;i<timeSeries.size();i++){
            int temp = timeSeries[i] + duration;
            if(i < timeSeries.size() - 1){
                temp = min(temp, timeSeries[i + 1]);
            }
            result += temp - timeSeries[i];
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> timeSeries = {1, 4};
    int duration = 2;
    cout << s.findPoisonedDuration(timeSeries, duration) << endl;
}