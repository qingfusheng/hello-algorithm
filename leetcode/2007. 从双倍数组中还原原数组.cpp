#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int counts[100001]{};
        for(int x:changed) ++counts[x];
        if(counts[0]&1) return {};
        vector<int> ans(counts[0]>>1,0);
        for(int i=1;i<100001;++i){
            if(counts[i]<0){
                return {};
            }else if(counts[i]>0){
                if(2*i>100000) return {};
                counts[2*i]-=counts[i];
                while(counts[i]--){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> changed = {1,3,4,2,6,8};
    vector<int> ans = s.findOriginalArray(changed);
    for(int x:ans) cout << x << " ";
    cout << endl;
    return 0;
}

/*
// 有几个demo会超时
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end(), less<int>());
        vector<int>result = vector<int>();
        vector<int> visited(changed.size(), 0);
        for (int i = 0; i < changed.size(); i++) {
            if (visited[i] == 1)
                continue;
            int found = 0;
            for (int j = i + 1; j < changed.size(); j++) {
                if (visited[j] == 1)
                	continue;
                if (changed[j] == 2 * changed[i]) {
                    result.push_back(changed[i]);
                    visited[j] = 1;
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                return vector<int>();
        }
        return result;

    }
};
*/