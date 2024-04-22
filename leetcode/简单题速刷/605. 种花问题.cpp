#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// 模拟的做法
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i] == 1)continue;
            bool set = true;
            if(i > 0)
                if(flowerbed[i-1] == 1){
                    set = false;
                }
            if(i < flowerbed.size() - 1)
                if(flowerbed[i+1] == 1){
                    set = false;
                }
            if(set){
                flowerbed[i] = 1;
                ans += 1;
                if(ans >= n)
                    return true;// 优化以后消耗时间降低
            }
        }
        return ans >= n;
    }
};

int main(){
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;
    Solution so = Solution();
    cout<<so.canPlaceFlowers(flowerbed, n)<<endl;
    return 0;
}