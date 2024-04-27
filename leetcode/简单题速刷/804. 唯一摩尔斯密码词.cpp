#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> MorsCode{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> MySet;
        for(auto &word: words){
            string temp;
            for(auto &ch: word){
                temp += MorsCode[ch - 'a'];
            }
            MySet.insert(temp);
        }
        return MySet.size();
    }
};
int main(){
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << s.uniqueMorseRepresentations(words) << endl;
    return 0;
}