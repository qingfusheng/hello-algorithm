#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int pre = s[0];
        vector<int> counter;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == pre) {
                count += 1;
            }
            else {
                counter.push_back(count);
                count = 1;
                pre = s[i];
            }
        }
        counter.push_back(count);
        int ans = 0;
        for (int i = 1; i < counter.size(); i++) {
            ans += min(counter[i-1], counter[i]);
        }
        return ans; 
    }
};
int main() {
    Solution s;
	cout << s.countBinarySubstrings("000110011") << endl;
	return 0;
}