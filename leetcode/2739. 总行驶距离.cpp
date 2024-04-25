// 简单题，纯模拟
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int count = 0;
        int temp = 0;
        while(mainTank > 0){
            mainTank -= 1;
            count ++;
            temp ++;
            if(temp == 5){
                if(additionalTank >= 1){
                    additionalTank -= 1;
                    mainTank += 1;
                }
                temp = 0;
            }
        }
        return count * 10;
    }
};
int main(){
    Solution s;
    cout << s.distanceTraveled(10, 2) << endl;
    return 0;
}

/*
官方题解1：
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            ans += 50;
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        return ans + mainTank * 10;
    }
};
官方题解2：(换水问题，6个空包换一包？)

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return 10 * (mainTank + min((mainTank - 1) / 4, additionalTank));
    }
};

*/