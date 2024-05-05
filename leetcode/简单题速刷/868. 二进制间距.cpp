#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        if((n & (n - 1)) == 0)return 0;
        int max_length = 0;
        int length = 0;
        int temp = n;
        bool begin = false;
        while(temp > 0){
            if(temp & 1 == 1){
                if(!begin){
                    begin = true;
                }else{
                    max_length = max(max_length, length);
                }
                length = 1;
            }
            if((temp & 1) == 0 && begin){
                length += 1;
            }
            temp >>= 1;
        }
        return max_length;
    }
};

int main(){
    Solution s;
    cout << s.binaryGap(22) << endl;
    cout << s.binaryGap(5) << endl;
    cout << s.binaryGap(6) << endl;
    cout << s.binaryGap(8) << endl;
    return 0;
}

/*
    注意经常犯错的点： & 的优先级， temp & 1 == 0 与 (temp & 1) == 0 不同
*/