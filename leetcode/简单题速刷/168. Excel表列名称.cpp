// 备注：0真的是一个很伟大的发明
#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int columnNumber) {
    string s;
    while (columnNumber > 0) {
        // 很绕
        int temp = (columnNumber - 1) % 26 + 1;
        s.push_back(('A' + temp - 1));
        columnNumber = (columnNumber - temp) / 26;
    }
    reverse(s.begin(), s.end());
    return s;
}

/*
* A-> 0 , Z->25
1->A
26->Z
27->AA
55->BC
701->ZY = Z*26 + Y = 26*26 + 25
52->AZ
25 -> 26*0 + 25
51 -> 26*1 + 25
*/

int main() {
    cout << convertToTitle(701) << endl;
	return 0;
}