// 题目名称：1017. 负二进制转换
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/convert-to-base-2/description/
// 题目思路：奇怪的是，明明它是-2进制，但是它的余数是0和1.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if(n== 0 || n == 1) return to_string(n);
		string res = "";
		while (n != 0) {
			int remainder = n & 1;  // 这里与取余不同的是，取余可能得到负数，但我们的余数只能是0或1
			res.push_back('0' + remainder);
			n -= remainder;  // 注意这里是先减去余数，再除以-2
			n /= -2;	
		}
		reverse(res.begin(), res.end());
		return res;
    }
};

int main() {
    Solution s;
    /*cout << (-1 & 1) << endl;
    	
	cout << s.baseNeg2(2) << endl;
	cout << s.baseNeg2(3) << endl;
	cout << s.baseNeg2(4) << endl;
	cout << s.baseNeg2(5) << endl;
	cout << s.baseNeg2(6) << endl;
	cout << s.baseNeg2(7) << endl;*/
	cout << s.baseNeg2(8) << endl;
	//cout << s.baseNeg2(9) << endl;
}

/*
官方题解的三种思路：模拟进位，进制转换，数学规律
https://leetcode.cn/problems/convert-to-base-2/solutions/2209807/fu-er-jin-zhi-zhuan-huan-by-leetcode-sol-9qlh/?envType=daily-question&envId=2024-04-28
*/