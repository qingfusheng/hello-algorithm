#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26];
        memset(a, 0, 26);
        for(char ch: magazine){
            a[ch-'a'] += 1;
        }
        for(char ch: ransomNote){
            a[ch-'a'] -= 1;
            if(a[ch-'a'] < 0)return false;
        }
        return true;
    }
};
int main(){}
/*如果使用sort然后双指针的方法应该不需要这么大的空间占用，但是数组存储消耗的时间少*/