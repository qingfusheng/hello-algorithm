#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int D = 10;     // 使用的二进制位数，0-9共十位
        int res = 1;
        int n = s.size();
        vector<int> flag2Index(1 << 10, n);  // flag2Index[i]表示首次出现flag为i的位置。十位二进制共有2^10个flag, 初始为n，保证通过min更新时能够将最小索引更新上去
        flag2Index[0] = -1;     // 表示flag=0首次出现在-1的位置，用于计算的正确性
        int flag = 0;           // flag的每一位d表示数字d在s[0, j]出现的奇偶次数，0为偶数次，1为奇数次
        for(int j = 0; j < n; j++){
            flag ^= (1 << (s[j] - '0'));    // 将s[j]的数字更新到对应位上
            for(int d = 0; d < D; d++){
                res = max(res, j - flag2Index[flag ^ (1 << d)]);    // 找到奇数长度的最长回文串
            }
            res = max(res, j - flag2Index[flag]);   // 找到偶数长度的最长回文串
            flag2Index[flag] = min(flag2Index[flag], j);     // 如果flag2Index[flag]为n，j即为首个出现flag的位置，更新上；否则flag出现过，j一定更大不会被更新上去
        }
        return res;
    }
};
int main(){
    Solution s;
    string str = "3242415";
    cout << s.longestAwesome(str) << endl;
    return 0;

}
/*
作者：画图小匠
链接：https://leetcode.cn/problems/find-longest-awesome-substring/solutions/2783874/javapython3cqian-zhui-yi-huo-he-ha-xi-bi-wbvp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/