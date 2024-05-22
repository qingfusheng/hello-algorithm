#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> Vec1(n+1);
        vector<int> Vec2(n+1);
        for(auto& each: trust){
            Vec1[each[0]] += 1;
            Vec2[each[1]] += 1;
        }

        for(int i=1;i<=n;i++){
            if(Vec1[i] == 0 && Vec2[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> trust = {{1,3},{2,3}};
    cout << s.findJudge(3, trust) << endl;
    return 0;
}