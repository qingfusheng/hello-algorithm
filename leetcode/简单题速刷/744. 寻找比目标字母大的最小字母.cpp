#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto &ch: letters){
            if(ch > target)
                return ch;
        }
        return letters[0];
    }
};

int main(){

}

/*
二分（时间空间都不占优势）：
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        if(letters[left] > target || letters[right] <= target)
            return letters[left];
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(letters[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return letters[left];
    }
};
*/