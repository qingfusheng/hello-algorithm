#include<iostream>
#include<vector>
using namespace std;
class MaxHeap {
private:
	vector<int> value;
public:
	MaxHeap(vector<int>nums) {
		value = nums;
		for (int i = parent(size() - 1); i >= 0; i--)
			siftDown(i);
	}
	int left(int num) {
		return 2 * num + 1;
	}
	int right(int num) {
		return 2 * num + 2;
	}
	int parent(int num) {
		return (num - 1) / 2;
	}
	int peek() {
		return value[0];
	}
	int size() {
		return value.size();
	}
	bool empty() {
		if (value.size() == 0)
			return true;
		else
			return false;
	}
	void push(int val) {
		value.push_back(val);
		siftUp(size() - 1); // 顶堆化操作元素为最后插入的那个元素。
	}
	void siftUp(int i) {
		while (true) {
			int p = parent(i);
			if (p < 0 || value[i] <= value[p])
				break;
			else {
				// else无作用，因为接受if条件后会跳出循环
				swap(value[i], value[p]);
				i = p;  // 一直检查父节点直到根节点。
			}
		}
	}
	void siftDown(int i) {
		while (true) {
			int l = left(i), r = right(i), max_index = i;
			if (l<size() - 1 && value[l] > value[max_index])
				max_index = l;
			if (r<size() - 1 && value[r] > value[max_index])
				max_index = r;
			if (max_index == i) {
				// 为什么这里是break，不应该整体检索一遍吗，他这里是默认底下的已经是correct order了吗
				// 0901解答，因为前面交换了首尾元素并pop了尾部元素，所以其他的位置其实是没有变化的
				break;
			}
			swap(value[i], value[max_index]);
			i = max_index;
		}
	}
	void pop() {
		if (empty()) {
			throw out_of_range("堆已空");
		}
		swap(value[0], value[size() - 1]);
		value.pop_back();
		siftDown(0);
	}
};
int main() {
    return 0;
}