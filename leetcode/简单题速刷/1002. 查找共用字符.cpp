#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minWord(26, 0);
        vector<int> curWord(26);
        for(char& ch: words[0]){
            minWord[ch-'a'] += 1;
        }
        for(string& word: words){
            fill(curWord.begin(), curWord.end(), 0);
            for(char& ch: word){
                curWord[ch-'a'] += 1;
            }
            for(int i=0;i<26;i++){
                minWord[i] = min(minWord[i], curWord[i]);
            }
        }
        vector<string> result;
        for(int i=0;i<26;i++){
            for(int j = 0; j < minWord[i];j++){
                string s = "";
                s += 'a' + i;
                result.push_back(s);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> words = {"bella","label","roller"};
    vector<string> result = s.commonChars(words);
    for(string& s: result){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}