#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/* 基于链表实现的队列 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int num) :val(num), next(nullptr) {};
};
class LinkedListQueue {
private:
    ListNode* front, * rear; // 头节点 front ，尾节点 rear
    int queSize;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }

    ~LinkedListQueue() {
        // 遍历链表删除节点，释放内存
        while (front) {
            ListNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    /* 获取队列的长度 */
    int size() {
        return queSize;
    }

    /* 判断队列是否为空 */
    bool empty() {
        return queSize == 0;
    }

    /* 入队 */
    void push(int num) {
        // 尾节点后添加 num
        ListNode* node = new ListNode(num);
        // 如果队列为空，则令头、尾节点都指向该节点
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        // 如果队列不为空，则将该节点添加到尾节点后
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    /* 出队 */
    void pop() {
        int num = peek();
        // 删除头节点
        ListNode* tmp = front;
        front = front->next;
        // 释放内存
        delete tmp;
        queSize--;
    }

    /* 访问队首元素 */
    int peek() {
        if (size() == 0)
            throw out_of_range("队列为空");
        return front->val;
    }

    /* 将链表转化为 Vector 并返回 */
    vector<int> toVector() {
        ListNode* node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
/* 基于环形数组实现的队列 */
class ArrayQueue {
private:
    int* nums;       // 用于存储队列元素的数组
    int front;       // 队首指针，指向队首元素
    int queSize;     // 队列长度
    int queCapacity; // 队列容量

public:
    ArrayQueue(int capacity) {
        // 初始化数组
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }

    ~ArrayQueue() {
        delete[] nums;
    }

    /* 获取队列的容量 */
    int capacity() {
        return queCapacity;
    }

    /* 获取队列的长度 */
    int size() {
        return queSize;
    }

    /* 判断队列是否为空 */
    bool empty() {
        return size() == 0;
    }

    /* 入队 */
    void push(int num) {
        if (queSize == queCapacity) {
            cout << "队列已满" << endl;
            return;
        }
        // 计算队尾指针，指向队尾索引 + 1
        // 通过取余操作，实现 rear 越过数组尾部后回到头部
        int rear = (front + queSize) % queCapacity;
        // 将 num 添加至队尾
        nums[rear] = num;
        queSize++;
    }

    /* 出队 */
    void pop() {
        int num = peek();
        // 队首指针向后移动一位，若越过尾部则返回到数组头部
        front = (front + 1) % queCapacity;
        queSize--;
    }

    /* 访问队首元素 */
    int peek() {
        if (empty())
            throw out_of_range("队列为空");
        return nums[front];
    }

    /* 将数组转化为 Vector 并返回 */
    vector<int> toVector() {
        // 仅转换有效长度范围内的列表元素
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++) {
            arr[i] = nums[j % queCapacity];
        }
        return arr;
    }
};

int main() {
	queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << "front:" << queue.front() << endl;  // 队列头部
	cout << "back:" << queue.back() << endl;    // 队列尾部
	queue.pop();
	// 尾部进头部出，先进先出，在front位置出
	cout << "front:" << queue.front() << endl;  // 队列头部
	int size = queue.size();
	bool empty = queue.empty();  // 判断是否为空，而不是置空
	// 使用 emplace() 时，你只需传递构造函数所需的参数，而不需要手动创建对象。
	// push() 用于将已经构造好的元素添加到队列末尾。
}