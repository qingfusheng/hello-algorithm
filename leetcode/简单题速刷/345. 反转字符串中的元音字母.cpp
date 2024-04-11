#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> MySet{'a', 'A', 'i', 'I', 'o', 'O', 'e', 'E', 'u', 'U'};
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(MySet.find(s[left]) == MySet.end()){
                left ++;
                continue;
            }
            if(MySet.find(s[right]) == MySet.end()){
                right --;
                continue;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main(){
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    return 0;
}

