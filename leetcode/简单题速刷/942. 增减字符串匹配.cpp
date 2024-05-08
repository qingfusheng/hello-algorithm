#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> res(n+1);
        int low = 0, high = n;
        int index = 0;
        for(char &ch: s){
            if(ch == 'I'){
                res[index++] = low++;
            }else{
                res[index++] = high--;
            }
        }
        res[n] = low;
        return res;
    }
};

int main(){
    Solution s;
    string str = "IDID";
    vector<int> res = s.diStringMatch(str);
    for(int &i: res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
    不要用 增幅趋势 来判断下一个元素，而是判断这个元素应该是什么。
*/