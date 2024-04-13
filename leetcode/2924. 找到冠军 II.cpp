#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> MyList(n, 0);
        for(auto edge: edges){
            MyList[edge[1]] += 1;
        }
        for(int i=0;i<n;i++)
            cout<<MyList[i]<<", ";
        cout<<endl;
        int CpIndex = -1;
        for(int i=0;i<n;i++){
            if(MyList[i] == 0){
                if(CpIndex == -1){
                    CpIndex = i;
                }else{
                    return -1;
                }
            }
        }
        return CpIndex;
    }
};
int main(){}

/*

*/