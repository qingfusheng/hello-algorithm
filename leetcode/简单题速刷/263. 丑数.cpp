#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0 || n % 2 == 0 ||n % 5 == 0){
            if(n%2==0){n/=2;continue;}
            if(n % 3 == 0){n/=3;continue;}
            if(n%5 == 0){n/=5;continue;}
        }
        return n==1;
    }
};
int main(){
    Solution s;
    cout << s.isUgly(6);
      
}