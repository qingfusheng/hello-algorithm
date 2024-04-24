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