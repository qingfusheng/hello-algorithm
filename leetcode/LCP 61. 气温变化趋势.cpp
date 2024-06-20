// 数组
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getTrend(int x, int y){
        if(x==y)return 0;
        return x > y ? 1 : -1;
    }
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int n = temperatureA.size();
        int res = 0;
        int tmp = 0;
        for(int i=1;i<n;i++){
            int JudgeA = getTrend(temperatureA[i], temperatureA[i-1]);
            int JudgeB = getTrend(temperatureB[i], temperatureB[i-1]);
            if(JudgeA == JudgeB){
                tmp++;
                res = max(res, tmp);
            }else{
                tmp = 0;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> temperatureA = {1,2,3,2,3,4,3,4,5};
    vector<int> temperatureB = {2,3,2,3,4,3,4,5,6};
    cout << s.temperatureTrend(temperatureA, temperatureB) << endl;
    return 0;
}