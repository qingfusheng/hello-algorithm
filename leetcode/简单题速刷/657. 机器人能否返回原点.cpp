#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        // 优化操作
        if (moves.length() == 0) return true;
        if ((moves.length() & 1) == 1) return false;
        int UD = 0;
        int LR = 0;
        for(char ch:moves){
            if(ch == 'L')LR-=1;
            else if(ch == 'R') LR+=1;
            else if(ch == 'U') UD+=1;
            else UD-=1;
        }
        return UD ==0 && LR==0;
    }
};
int main(){
    Solution sol;
    string moves = "UD";
    cout << sol.judgeCircle(moves) << endl;
    return 0;
}