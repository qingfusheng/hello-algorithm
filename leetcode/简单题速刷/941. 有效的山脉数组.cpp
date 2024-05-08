#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)return false;
        bool up = true;
        bool upped = false;
        for(int i=1;i<arr.size();i++){
            if(up){
                if(arr[i] > arr[i-1]){
                    upped = true;
                    continue;
                }
                else if(arr[i] == arr[i-1]){
                    return false;
                }else{
                    up = false;
                }
            }else{
                if(arr[i] < arr[i-1]){
                    continue;
                }else if(arr[i] == arr[i-1]){
                    return false;
                }else{
                    return false;
                }
            } 
        }
        if(up || !upped)return false;
        else return true;
    }
};

int main(){
    Solution s;
    vector<int> arr = {0,3,2,1};
    cout << s.validMountainArray(arr) << endl;
    return 0;
}