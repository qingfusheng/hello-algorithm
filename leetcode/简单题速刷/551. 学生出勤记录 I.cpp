#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int Absent = 0;
        int Late = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'L'){
                Late += 1;
                if(Late >= 3){
                    return false;
                }
            }else{
                Late = 0;
                if(s[i] == 'A'){
                    Absent += 1;
                    if(Absent >= 2){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    return 0;
}

/*
// 统计 A 的个数和连续 L 的个数即可。
*/