#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        string rowIdx = "12210111011122000010020202";
        for(string word: words){
            bool isValid = true;
            int pre = rowIdx[tolower(word[0]) - 'a'];
            for(char ch: word){
                if(rowIdx[tolower(ch) - 'a'] == pre){
                    continue;
                }else{
                    isValid = false;
                    break;
                }
            }
            if(isValid)
                result.push_back(word);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = s.findWords(words);
    for(string str: result){
        cout << str << endl;
    }
    return 0;
}