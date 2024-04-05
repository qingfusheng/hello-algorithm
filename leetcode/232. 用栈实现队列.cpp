// 题目名称：232. 用栈实现队列
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/implement-queue-using-stacks/description/
// 题目思路：一个用于存储，另一个用于辅助，注意辅助栈用于pop和peek操作（peek能不能再优化一下？）

#include<iostream>
#include<algorithm>
#include<string>
#include<climits>
#include<stack>
using namespace std;
class MyQueue {
private:
    stack<int> s1, s2;
    void view_stack(stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << "->";
            s.pop();
        }
    }
public:
    MyQueue() {

    }
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s1.top();
        s1.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    int peek() {
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s1.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    bool empty() {
        return s1.empty();
    }
};


int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int a = obj->pop();
    int b = obj->pop();
    int c = obj->pop();
    cout << obj->empty() << endl;
    cout << a << ", " << b << ", " << c << endl;

}