// 题目名称：225. 用队列实现栈
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/implement-stack-using-queues/description
// 题目思路：一个用于存储，另一个用于辅助

#include<iostream>
#include<algorithm>
#include<string>
#include<climits>
#include<queue>
using namespace std;
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
    }

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
        while (!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}
    }

    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


int main() {
    MyStack* obj = new MyStack();
    obj->push(2);
    obj->push(3);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

}