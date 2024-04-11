#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};

int main(){

}

/*博弈论*/
/*
 * 这里是通过列举的方式。
 n = 1, true, false
 n = 2, true, false
 n = 3, true, false
 n = 4, false, true
 n = 5, true, false
 n = 6, true, false
 n = 7, true, false
 n = 8, false, true

 当n = 8时，你拿走1-3个石头，剩下了5-7个石头，很明显在这三种情况下先手都会赢得比赛。
*/