#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)
            return false;
        
        int sum = 1;
        for(int i=2;i * i < num;i++){
            if(num % i == 0){
                sum += i + num / i;
            }
        }
        return sum == num;
    }
};
int main(){
    Solution s;
    cout << s.checkPerfectNumber(28) << endl;
    return 0;
}

/*
枚举法，时间复杂度O(sqrt(n))  （在原本的思路中，时间复杂度是O(n)）
*/