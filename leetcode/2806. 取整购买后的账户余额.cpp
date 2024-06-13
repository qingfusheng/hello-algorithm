// 题目写的莫名其妙的
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - (purchaseAmount + 5) / 10 * 10;
    }
}; 

int main(){
    Solution s;
    cout << s.accountBalanceAfterPurchase(9) << endl;
    return 0;
}