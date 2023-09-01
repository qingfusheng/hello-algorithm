// 链表的构造和使用
#include<iostream>
#include<vector>
using namespace std;
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int value) :val(value), next(nullptr) {};
};
class LinkList {
private:
	ListNode* head = nullptr;
	int length = 0;
public:
	LinkList() :head(new ListNode(0)), length(0) {};
	LinkList(int a[], int list_length) {
		head = new ListNode(0);
		ListNode* temp = head;
		for (int i = 0; i < list_length; i++) {
			temp->next = new ListNode(a[i]);
			temp = temp->next;
			length += 1;
		}
	}
	LinkList(vector <int>& v) {
		head = new ListNode(0);
		ListNode* temp = head;
		for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
			temp->next = new ListNode(*it);
			temp = temp->next;
			length += 1;
		}
	}
	~LinkList() {
		ListNode* current = head;
		while (current != nullptr) {
			ListNode* temp = current;
			current = current->next;
			delete temp;
		}
	}
	void insert(ListNode* node, ListNode* p) {
		ListNode* temp = node->next;
		node->next = p;
		p->next = temp;
		length++;
		return;
	}

	void remove(ListNode* node) {
		// 这里删除节点是指删除node的next结点而不是node本身。
		if (node->next == nullptr)
			return;
		// node -> temp -> temp2
		ListNode* temp = node->next;
		node->next = temp->next;
		delete temp;
		length--;
		return;
	}
	ListNode* at(int index) {
		if (index < 0 or index >= length) {
			return nullptr;
		}
		ListNode* temp = head->next;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}

	ListNode* find(int value) {
		int index = 0;
		ListNode* temp = head->next;
		while (temp != nullptr) {
			if (temp->val == value) {
				return temp;
			}
			index++;
			temp = temp->next;
		}
		return nullptr;
	}
	void view() {
		ListNode* temp = head->next;
		cout << "链表长度为：" << length << endl;
		cout << "链表为：[";
		while (temp != nullptr) {
			cout << temp->val << ", ";
			temp = temp->next;
		}
		cout << "]\n";
		
	}

};
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);

	LinkList* lst = new LinkList(v);
	lst->view();

	ListNode* n0 = lst->at(0);
	ListNode* n1 = new ListNode(121);
	lst->insert(n0, n1);
	lst->view();
	// 这里是移出刚刚添加的那个值，由于function的实现逻辑是移除node的下一个元素，因此这里移除的是n1.
	lst->remove(n0);
	lst->view();
	ListNode* temp = lst->at(0);
	if (temp == nullptr)
		cout << "索引值超过链表长度！" << endl;
	else
		cout << temp->val << ", ";
	cout << endl;

	ListNode* result = lst->find(4);
	if (result)
		cout << result->val << endl;
	else
		cout << "未检索到相关值" << endl;
}