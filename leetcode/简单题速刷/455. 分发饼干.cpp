#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 贪心,可是看起来效果一般（15%， 74%）
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index1 = 0, index2 = 0;
        int count = 0;
        while(index1 < g.size() && index2 < s.size()){
            if(g[index1] <= s[index2]){
                index1++, index2++;
                count+=1;
            }else{
                index2++;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << s.findContentChildren(g, s) << endl;
}