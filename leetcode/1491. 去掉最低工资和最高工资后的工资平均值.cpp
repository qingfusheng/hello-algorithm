#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        return accumulate(salary.begin() + 1, salary.end() - 1, 0) / 1.0 / (salary.size() - 2);
    }
};

int main(){
    Solution s; 
    vector<int> salary = {4000, 3000, 1000, 2000}; 
    cout << s.average(salary) << endl; 
    return 0;
}