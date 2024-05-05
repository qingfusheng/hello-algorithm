#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill: bills){
            switch(bill){
                case  5:five++;break;
                case 10:five--;ten++;break;
                case 20:if(ten>0){ten--;five--;}else five-=3;break;
                default:break;
            }
            if(five < 0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> bills = {5,5,5,10,20};
    cout << s.lemonadeChange(bills) << endl;
    return 0;
}