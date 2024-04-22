#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<string, int> MyMap;
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if(list1.size() > list2.size()){
            swap(list1, list2);
        }
        for(int i=0;i<list1.size();i++)
            MyMap[list1[i]] = i;
        int min_sum = INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(MyMap.find(list2[i]) == MyMap.end()){
                continue;
            }else{
                min_sum = min(min_sum, MyMap[list2[i]]+i);
            }
        }
        // 遍历了两次，没想到效率还能接受
        vector<string> result;
        for(int i=0;i<list2.size();i++){
            if(MyMap.find(list2[i]) == MyMap.end()){
                continue;
            }else{
                if(MyMap[list2[i]]+i == min_sum){
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};

int main(){
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    Solution so = Solution();
    vector<string> result = so.findRestaurant(list1, list2);
    for(auto &res: result){
        cout<<res<<endl;
    }
    return 0;
}

/*

*/