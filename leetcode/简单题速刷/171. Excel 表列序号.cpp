#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int a[7] = {1, 26, 676, 17576, 456976, 11881376, 308915776};  // 将这些值提前算出来，可以减少程序中的运算量
        int res = 0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            res += a[columnTitle.length() - i - 1] * (columnTitle[i]-'A'+1);
        }
        return res;
    }
};

/*
// 
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(char ch: columnTitle){
            int temp = ch - 'A' + 1;
            res = 26 * res + temp;
        }
        return res;
    }
};
*/