#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(auto &op: operations){
            if(op == "+"){
                ans.push_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
            }else if(op == "C"){
                ans.erase(ans.end() - 1);
            }else if(op == "D"){
                ans.push_back(2*ans[ans.size() - 1]);
            }else{
                ans.push_back(stoi(op));
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};

int main(){
    Solution s;
    vector<string> operations = {"5","2","C","D","+"};
    cout << s.calPoints(operations) << endl;
}

//主打的就是一个模拟题，用一个vector来模拟一个栈，然后根据不同的操作来进行模拟即可。