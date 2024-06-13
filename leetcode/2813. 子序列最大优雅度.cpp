// 困难
// 贪心，但是反悔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        long long tot = 0;
        unordered_set<int> vis;
        stack<int> dup;
        for (int i = 0; i < k; ++i) {
            int p = items[i][0], c = items[i][1];
            tot += p;
            if (vis.count(c)) {
                dup.push(p);
            } else {
                vis.insert(c);
            }
        }
        int n = items.size();
        long long ans = tot + 1LL * vis.size() * vis.size();
        for (int i = k; i < n; ++i) {
            int p = items[i][0], c = items[i][1];
            if (vis.count(c) || dup.empty()) {
                continue;
            }
            vis.insert(c);
            tot += p - dup.top();
            dup.pop();
            ans = max(ans, tot + (long long) (1LL * vis.size() * vis.size()));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> items = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    cout << s.findMaximumElegance(items, 3) << endl;
    return 0;
}

// 附上一份尝试中的错误代码
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] > b[0];
	}
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int result = 0;
        unordered_set<int> s;
        vector<int> v1, v2;
        sort(items.begin(), items.end(), cmp);
        for (auto& item : items) {
            if (s.find(item[1]) != s.end()) {
                v2.push_back(item[0]);
			}
            else {
                s.insert(item[1]);
                v1.push_back(item[0]);
			}
		}
        cout << "v1:";
        for (int i = 0; i < v1.size(); i++) {
			cout << v1[i] << " ";
		}
        cout << endl << "v2:";
        for (int i = 0; i < v2.size(); i++) {
            cout << v2[i] << " ";
        }
        cout << endl ;
        if (v1.size() >= k) {
            for (int i = 0; i < k; i++) {
                result+= v1[i];
            }
            result += k * k;
        }
        else {
            for (int i = 0; i < v1.size(); i++) {
				result += v1[i];
			}
            for (int i = 0; i < k - v1.size(); i++) {
                result += v2[i];
            }
            result += v1.size() * v1.size();
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> items = { {2,2},{8,3},{8,3} };
    //vector<vector<int>> items = { {3,2},{5,1},{10,1} };
	int k = 2;
	cout << s.findMaximumElegance(items, k) << endl;
	return 0;
}
*/