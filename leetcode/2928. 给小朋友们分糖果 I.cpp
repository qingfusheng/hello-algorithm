#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for(int i=0;i <= limit;i++){
            for(int j=0;j <= limit;j++){
                if(i +j > n)break;
                if(n - i -  j <= limit){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    cout << s.distributeCandies(7, 4) << endl;
    return 0;
}

/*
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for(int i=0;i <= min(limit, n);i++){
            if(n - i > 2 * limit)continue;
            count += min(n-i, limit) - max(0, n-i-limit) + 1;
        }

        return count;
    }
};
*/