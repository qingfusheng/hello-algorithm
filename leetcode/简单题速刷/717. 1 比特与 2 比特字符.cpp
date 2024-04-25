#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        bool flag = false;
        while(index < bits.size()){
            if(bits[index] == 0){
                index += 1;
                flag = true;
            }else{
                index += 2;
                flag = false;
            }
        }
        return flag;
    }
};
int main(){
    Solution s;
    vector<int> bits = {1, 0, 0};
    cout << s.isOneBitCharacter(bits) << endl;
    return 0;
}

/*
官方题解：（不过效率差不多
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        while(index < bits.size() - 1){
            index += bits[index] + 1;
        }
        return index == bits.size() - 1;
    }
};
*/