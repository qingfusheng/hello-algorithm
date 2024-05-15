#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int n = num.size();
        vector<int> temp;
        while (k > 0) {
            temp.push_back(k % 10);
            k /= 10;
        }
        if(temp.size() == 0)
            temp.push_back(0);
        int m = temp.size();
        vector<int> result(max(n, m), 0);
        bool carry = false;
        for (int index = 0; index < max(n, m); index++) {
            int x = index < n ? num[index] : 0;
            int y = index < m ? temp[index] : 0;
            result[index] = (x + y + carry) % 10;
            carry = (x + y + carry) >= 10;
        }
        if (carry)result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    vector<int> num = {1,2,0,0};
    int k = 34;
    vector<int> result = s.addToArrayForm(num, k);
    for(auto& i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}