#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> result;
        for(int i=1;i<mountain.size() - 1;i++){
            if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]){
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> mountain = {0, 1, 0};
    vector<int> result = s.findPeaks(mountain);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}