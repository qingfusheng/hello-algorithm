#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(auto &ch: s){
            ch = tolower(ch);
        }
        return s;
    }
};

// 我的问题是：string类型不是不能直接修改其值吗？
// 答：string类型是可以修改的，但是不能直接修改其值，只能通过引用的方式修改