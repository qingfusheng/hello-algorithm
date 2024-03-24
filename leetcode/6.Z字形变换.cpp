#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string convert(string s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	int it_num = (numRows - 1) * 2;
	int length = s.length();
	string t = "";
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j * it_num <= (length - 1 - i); j++) {
			// 这里如果写成 j<=(length-1-i)/it_num的话会有一个奇怪的bug，即类似于 (-1/2)=0这种问题
			if (i == 0 || i == numRows - 1) {
				t += s[it_num*j + i];
			}
			else {
				t += s[it_num * j + i];
				cout << it_num * j + i << ", ";
				if (it_num * j + i + (numRows - 1 - i) * 2 < length) {
					cout<< it_num * j + i + (numRows - 1 - i) * 2 << endl;
					t += s[it_num * j + i + (numRows - 1 - i) * 2];
				}
			}
		}
	}
	return t;
}
int main() {
	string s = "A";
	int num = 2;
	string result = convert(s, num);
	cout << "|" << result << "|" << endl;
	return 0;
}