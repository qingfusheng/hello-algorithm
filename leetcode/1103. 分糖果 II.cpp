#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int cur = 1;
        int index = 0;
        while(candies > 0){
            if(candies < cur){
                res[index] += candies;
                break;
            }
            res[index] += cur;
            candies -= cur;
            cur++;
            index = (index+1) % num_people;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> res = s.distributeCandies(7, 4);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
优雅：
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int index = 0;
        while(candies > 0){
            res[index % num_people] += min(index + 1, candies);
            candies -= min(index + 1, candies);
            index++;
        }
        return res;
    }
};
*/