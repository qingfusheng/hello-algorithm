#include<iostream>
#include<vector>
using namespace std;
struct Pair {
public:
	int key;
	string val;
	Pair(int key, string value) {
		this->key = key;
		this->val = value;
	}
};
/*基于数组简单实现的哈希表*/
class ArrayHashMap {
private:
	vector<Pair *> buckets;
	int capacity = 100;
public:
	ArrayHashMap() {
		buckets = vector<Pair*>(capacity);
	}
	~ArrayHashMap() {
		buckets.clear();
		buckets.shrink_to_fit();
	}
	int hashfunc(int key) {
		int index = key % capacity;
		return index;
	}
	// 添加
	void put(int key, string value) {
		Pair* pair = new Pair(key, value);
		int index = hashfunc(key);
		buckets[index] = pair;
		return;
	}
	// 删除
	void remove(int key) {
		int index = hashfunc(key);
		delete buckets[index];
		buckets[index] = nullptr;
	}
	// 查询
	string get(int key) {
		int index = hashfunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr)
			return nullptr;
		return pair->val;
	}
	// 获取所有的键值对
	vector<Pair *> pairSet() {
		vector<Pair*> pairSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr)
				pairSet.push_back(pair);
		}
		return pairSet;
	}
	// 获取所有的键
	vector<int> keySet() {
		vector<int> keySet;
		for (Pair* pair : buckets) {
			if (pair != nullptr)
				keySet.push_back(pair->key);
		}
		return keySet;
	}
	// 获取所有的值
	vector<string> valueSet() {
		vector<string> valueSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr)
				valueSet.push_back(pair->val);
		}
		return valueSet;
	}
	// print hashmap
	void print() {
		cout << "<<<预览哈希表开始***\n";
		for (Pair* pair : pairSet()) {
			cout << pair->key << "->" << pair->val << endl;
		}
		cout << "***预览哈希表结束>>>\n";
	}
};
int main() {
	ArrayHashMap *map = new ArrayHashMap();
	map->put(0, "username0");
	map->put(1, "username1");
	map->put(2, "username2");
	map->put(3, "username3");
	map->print();
	string name = map->get(2);
	cout << "学号为2的姓名为：" << name << endl;
	map->remove(1);
	map->print();
	cout << "该hashmap的keys为: ";
	vector<int> keys = map->keySet();
	for (int val : keys) {
		cout << val << " ";
	}
	cout << endl;
	// 2->username2整个被覆盖了
	cout<<"这里出现了哈希冲突："<<endl;
	map->put(102, "username102");
	map->print();
}