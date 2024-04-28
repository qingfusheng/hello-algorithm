#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int left = 0;
        int right;
        vector<vector<int>> result;
        if(s.length() <= 2) return result;
        while (left >= 0 && left < (int)s.length() - 2) {
            int count = 1;
            right = left + 1;
            while (s[right] == s[left] && right < s.length()) { right++; count++; }
            if (count >= 3) {
                result.push_back(vector<int>{left, left + count - 1});
            }
            left = right;
        }
        return result;
    }
};
int main() {
    Solution s;
	vector<vector<int>> result = s.largeGroupPositions("a");
    for (int i = 0; i < result.size(); i++) {
		cout << result[i][0] << " " << result[i][1] << endl;
	}
	return 0;
}


// 注意，s.length() 得到的是unsigned int, 因此 1-2就会变成18446744073709551615，
// 即0b1111111111111111111111111111111111111111111111111111111111111111，而不是我们需要的-1
