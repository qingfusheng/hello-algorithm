/*需要注意的是，如果使用链表实现stack，则链表头结点为栈顶，如果使用vector实现stack，则最后一个非空元素为栈顶*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/* 基于链表实现的栈 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int num):val(num), next(nullptr) {};
};
class LinkedListStack {
private:
    ListNode* stackTop; // 将头节点作为栈顶
    int stkSize;        // 栈的长度

public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
        while (stackTop) {
            ListNode* temp = stackTop;
            stackTop = stackTop->next;
            delete temp;
        }
    }
    int size() {
        return stkSize;
    }
    bool empty() {
        return size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }
    void pop() {
        int num = top();
        ListNode* tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stkSize--;
    }
    int top() {
        if (size() == 0)
            throw out_of_range("栈为空");
        return stackTop->val;
    }
    vector<int> toVector() {
        ListNode* node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

/* 基于数组实现的栈 */
class ArrayStack {
private:
    vector<int> stack;
public:
    int size() {
        return stack.size();
    }
    bool empty() {
        return stack.empty();
    }
    void push(int num) {
        stack.push_back(num);
    }
    void pop() {
        int oldTop = top();
        stack.pop_back();
    }
    int top() {
        if (empty())
            throw out_of_range("栈为空");
        return stack.back();
    }
    vector<int> toVector() {
        return stack;
    }
};

int main() {
    LinkedListStack *stack = new LinkedListStack();
    ArrayStack* stack1 = new ArrayStack();
    std::stack<int> std_stack;
    (*stack).push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    /* 访问栈顶元素 */
    int top = stack->top();
    cout << "栈顶元素为：" << top << endl;
    /* 元素出栈 */
    stack->pop(); // 无返回值
    top = stack->top();
    cout << "栈顶元素为：" << top << endl;
    /* 获取栈的长度 */
    int size = stack->size();
    cout << "栈长度为：" << size << endl;
    /* 判断是否为空 */
    string empty = stack->empty() ? "True" : "False";
    cout << "栈是否为空：" << empty << endl;
    return 0;
}