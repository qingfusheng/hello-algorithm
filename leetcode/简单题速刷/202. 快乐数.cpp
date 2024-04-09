#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mySet;
        while( n != 1){
            int temp = 0;
            while(n > 0){
                int bit = n % 10;
                temp += bit * bit;
                n /= 10;
            }
            if(mySet.count(temp) > 0){
                return false;
            }
            mySet.insert(temp);
            n = temp;
        }

        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isHappy(19)<<endl;
    return 0;
}

/*
// 快慢指针，没想到比common解法快那么多？这是为什么呢？
class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
};
*/