// 没有技巧，全是暴力
// 题解中有前缀法，但是并没有找到C++的前缀，回头再参悟一下
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count(string::iterator begin, string::iterator end, char c) {
		int temp = 0;
        for (auto& it = begin; it != end; it++) {
            if (*it == c) {
				temp++;
			}
		}
		return temp;
	}
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int tempM = count(garbage[0].begin(), garbage[0].end(), 'M');
        int tempP = count(garbage[0].begin(), garbage[0].end(), 'P');
        int tempG = count(garbage[0].begin(), garbage[0].end(), 'G');
        bool setted1 = false, setted2 = false, setted3 = false;
        for (int i = garbage.size() - 1; i >= 1; i--) {
            string each = garbage[i];
            if (count(each.begin(), each.end(), 'M') > 0) {
                setted1 = true;
                tempM += count(each.begin(), each.end(), 'M');
            }
            if (count(each.begin(), each.end(), 'P') > 0) {
                setted2 = true;
                tempP += count(each.begin(), each.end(), 'P');

            }
            if (count(each.begin(), each.end(), 'G') > 0) {
                setted3 = true;
                tempG += count(each.begin(), each.end(), 'G');
            }
            if (setted1) {
                tempM += travel[i - 1];
            }
            if (setted2) {
                tempP += travel[i - 1];

            }
            if (setted3) {
                tempG += travel[i - 1];
            }
        }
        return tempG+tempM+tempP;
    }
};

int main(){
    Solution s;
    vector<string> garbage = {"MPPM", "PPPP", "PPPP", "PPPP"};
    vector<int> travel = {1, 2, 3};
    cout << s.garbageCollection(garbage, travel) << endl;
    return 0;
}

/*
class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int length = garbage.length;
        int[] totalTravelMinutes = new int[length];
        for (int i = 0; i < length - 1; i++) {
            totalTravelMinutes[i + 1] = totalTravelMinutes[i] + travel[i];
        }
        int totalMinutes = 0;
        int[] maxIndices = new int[3];
        for (int i = 0; i < length; i++) {
            totalMinutes += garbage[i].length();
            int strLength = garbage[i].length();
            for (int j = 0; j < strLength; j++) {
                char type = garbage[i].charAt(j);
                int index = getIndex(type);
                maxIndices[index] = i;
            }
        }
        for (int i = 0; i < 3; i++) {
            totalMinutes += totalTravelMinutes[maxIndices[i]];
        }
        return totalMinutes;
    }

    public int getIndex(char type) {
        switch (type) {
        case 'M':
            return 0;
        case 'P':
            return 1;
        case 'G':
            return 2;
        default:
            return -1;
        }
    }
}

作者：Storm
链接：https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/solutions/2577143/2391-shou-ji-la-ji-de-zui-shao-zong-shi-7mo7r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/