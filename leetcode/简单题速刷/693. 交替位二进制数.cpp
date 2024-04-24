#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// 普通的位运算（模拟
    bool hasAlternatingBits(int n) {
        int temp = n;
        bool pre = temp & 1;
        temp = temp >> 1;
        while(temp > 0){
            if((temp & 1) != pre){
                pre = temp & 1;;
                temp = temp >> 1;
            }else{
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout << s.hasAlternatingBits(5) << endl;
}


/*
// 精彩的位运算：
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};

*/