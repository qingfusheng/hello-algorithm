// 题目名称：2671. 频率跟踪器
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/frequency-tracker/description
// 题目思路：首先想到的是map，但是map会超时，因此需要一个额外的map来记录频率，因为在1e5的范围内，所以可以用数组来记录
// 备注：hashmap麻烦的是，总是需要判断是否存在，而数组不需要

#include <bits/stdc++.h>
using namespace std;

class FrequencyTracker {
private:
    int Count[100001];
    int Freq[100001];
public:
    FrequencyTracker() {
        memset(Count, 0, 10001);
        memset(Freq, 0, 10001);
    }
    
    void add(int number) {
        Freq[Count[number]] -= 1;
        Count[number] += 1;
        Freq[Count[number]] += 1;
    }
    
    void deleteOne(int number) {
        if (Count[number] <= 0)
            return;
        Freq[Count[number]] -= 1;
        Count[number] -= 1;
        if(Count[number] > 0)
            Freq[Count[number]] += 1;

    }
    
    bool hasFrequency(int frequency) {
        return Freq[frequency] > 0;
    }
};
int main(){
}
