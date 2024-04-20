#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isCap(char ch){
        return ch >= 'A' && ch <= 'Z';
    }
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1){
            return true;
        }
        bool Cap1 = isCap(word[0]);
        bool Cap2 = isCap(word[1]);
        if(Cap1 == false){
            for(int i=1;i<word.length();i++){
                if(isCap(word[i]) == false){
                    continue;
                }else{
                    return false;
                }
            }
        }
        else{
            if(Cap2 == true){
                for(int i=2;i<word.length();i++){
                    if(isCap(word[i]) == true){
                        continue;
                    }else{
                        return false;
                    }
                }
            }else{
                for(int i=2;i<word.length();i++){
                    if(isCap(word[i]) == false){
                        continue;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){

}

/*

// 无论第 111 个字母是否大写，其他字母必须与第 2 个字母的大小写相同；
// 若第 111 个字母为小写，则需额外判断第 2 个字母是否为小写。

class Solution {
public:
    bool detectCapitalUse(string word) {
        // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }
        
        // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
        for (int i = 2; i < word.size(); ++i) {
            if (islower(word[i]) ^ islower(word[1])) {
                return false;
            }
        }
        return true;
    }
};

*/