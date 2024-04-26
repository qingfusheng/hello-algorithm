#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //<元素，出现的次数>
        unordered_map<char,int> licHashTable; //将licensePlate映射成哈希表
        unordered_map<char,int> wordHashTable; //将words映射成哈希表
        
        for(char l: licensePlate){ //将licensePlate的有效字符串映射成哈希表
            if(isalpha(l)){//isalpha(l)判断l是否为字母，isdigit(l)判断l是否是数字
                licHashTable[tolower(l)]++;
            }
        }

        string result; 
        bool flag = true; //标志words的元素是否能包含有效的licensePlate
        for(auto word : words){ 
            //注意：因为要遍历words的元素，所以每次均应该将标志值与记录word哈希表重置
            flag = true; wordHashTable.clear();

            //将words映射成哈希表
            for(auto w : word){ wordHashTable[w]++; }

            //若word哈希表中某字符个数小于licHashTable，则标志该word不能包括licensePlate
            for(auto l: licHashTable){
                if(wordHashTable[l.first] < l.second){
                    flag = false; break;
                }
            } 

            //若word不能包括有效的licensePlate，则跳过本次循环
            if(flag == false){continue;}
            //若word可以包括有效的licensePlate，则更新最短补全词
            if(result.empty() || result.size() > word.size()){
                result = word;
            } 
        }
        return result;
    }
};


int main(){
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    cout << s.shortestCompletingWord(licensePlate, words) << endl;
}