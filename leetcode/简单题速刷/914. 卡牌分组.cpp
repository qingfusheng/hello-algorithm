#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> count(10000);
        for (int c: deck) {
            count[c]++;
        }

        int g = -1;
        for (int i = 0; i < 10000; ++i) {
            if (count[i] > 0) {
                if (g == -1) {
                    g = count[i];
                } else {
                    g = gcd(g, count[i]);
                }
            }
        }
        return g >= 2;
    }

    public:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};

int main(){
    Solution s;
    vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
    cout << s.hasGroupsSizeX(deck) << endl;
}