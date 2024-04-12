#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result;
        int length = max(num1.length(), num2.length());
        bool jw = false;
        for(int i=0;i<length;i++){
            int temp1 = 0, temp2 = 0;
            if(i<num1.length())temp1 = num1[i] - '0';
            if(i<num2.length())temp2 = num2[i] - '0';
            cout<<temp1<<", "<<temp2<<endl;
            int temp = temp1 + temp2;
            if(jw) temp += 1;
            if(temp >= 10)
                jw = true;
            else
                jw = false;
            result.push_back((temp % 10) + '0');
        }
        if(jw)result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    cout << s.addStrings("123", "456") << endl;
}

/*老老实实的做法，不过多加了一个reverse可能有点超时*/