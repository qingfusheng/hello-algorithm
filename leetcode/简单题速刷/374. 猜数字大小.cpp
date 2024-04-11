#include <bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(guess(mid) ==  0){
                return mid;
            }
            else if(guess(mid) == 1){
                left = mid + 1;
            }else if(guess(mid) == -1) {
                right = mid;
            }
        }
        return left;
    }
};

int main(){
    Solution s;
    cout << s.guessNumber(10) << endl;
}


/*
关于二分法的细节：
1. left < right (right = mid) 还是 left <= right (right = mid - 1)
2. mid = left + (right - left) / 2 而不是 mid = (left + right) / 2
*/