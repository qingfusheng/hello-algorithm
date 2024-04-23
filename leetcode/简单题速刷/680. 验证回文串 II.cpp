#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPart(string s, int l,int r){
        while(l<=r){
            if(s[l]==s[r]){
                ++l;
                --r;
            }
            else
                return false;
        }  
        return true; 
    }


    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                ++i;
                --j;
            }
            else
                return validPart(s,i+1,j)||validPart(s,i,j-1);
        
        }
        return true;
    }

};

int main(){
    Solution sol;
    string s = "abca";
    cout << sol.validPalindrome(s) << endl;
    return 0;
}

/*
// 错误解法：你只看了一个，但是说不定那一个只是在迷惑你（即s[left] == s[right - 1]和s[left + 1] == s[right]都满足的情况

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        bool removed = false;
        while(left < right){
            if(s[left] == s[right]){
                left++, right--;
                continue;
            }else{
                if(!removed){
                    if(s[left + 1] == s[right]){
                        left += 1;
                        removed = true;
                        continue;   
                    }
                    else if(s[left] == s[right - 1]){
                        right -= 1;
                        removed = true;
                        continue;
                    } else {
                        return false;
                        }
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
*/