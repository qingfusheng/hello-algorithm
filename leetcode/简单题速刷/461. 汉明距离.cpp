#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int count = 0;
        while(temp > 0){
            count += temp & 1;
            temp = temp >> 1;
        }
        return count;
    }
};
int main(){
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
}

/*
1 ^ 5 = 4 (异或，相同为0，不同为1)
*/