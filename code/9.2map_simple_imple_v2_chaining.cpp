/*
 链式地址机制，将key不同而index相同的pair存到vector中而不是覆盖
*/
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
	int size;
	int capacity;
	double loadThres;
	int extendRatio;
	vector<vector<Pair *>> buckets;
public:
	ArrayHashMap():size(0),capacity(4),loadThres(2.0/3),extendRatio(2) {
		//buckets = vector<Pair*>(capacity);
		buckets.resize(capacity);
	}
	~ArrayHashMap() {
		buckets.clear();
		buckets.shrink_to_fit();
	}
	int hashfunc(int key) {
		return key % capacity;
	}
	// 负载因子
	double loadFactor() {
		return (double)size / (double)capacity;
	}
	// 添加
	void put(int key, string value) {
		if (loadFactor() > loadThres) {
			extend();
		}
		int index = hashfunc(key);
		for (Pair* pair : buckets[index]) {
			if (pair->key == key) {
				pair->val = value;
				return;
			}
		}
		buckets[index].push_back(new Pair(key, value));
		size++;
	}
	// 删除
	void remove(int key) {
		int index = hashfunc(key);
		// 先删除索引，再释放内存
		for (int i = 0; i < buckets[index].size(); i++) {
			Pair* pair = buckets[index][i];
			if (pair->key == key) {
				buckets[index].erase(buckets[index].begin() + i);
				delete pair;
				size--;
				return;
			}
		}
	}
	// 查询
	string get(int key) {
		int index = hashfunc(key);
		for (Pair* pair : buckets[index]) {
			if (pair->key == key)
				return pair->val;
		}
		return nullptr;
	}
	// 获取所有的键值对
	vector<Pair *> pairSet() {
		vector<Pair*> pairSet;
		for (vector<Pair*> bucket : buckets) {
			for (Pair* pair : bucket) {
				pairSet.push_back(pair);
			}
		}
		return pairSet;
	}
	// 获取所有的键
	vector<int> keySet() {
		vector<int> keySet;
		for (vector<Pair*> bucket : buckets) {
			for (Pair* pair : bucket) {
				keySet.push_back(pair->key);
			}
		}
		return keySet;
	}
	// 获取所有的值
	vector<string> valueSet() {
		vector<string> valueSet;
		for (vector<Pair*> bucket : buckets) {
			for (Pair* pair : bucket) {
				valueSet.push_back(pair->val);
			}
		}
		return valueSet;
	}

	void extend() {
		cout << "对当前hashmap进行extend\n";
		vector<vector<Pair*>> bucketsTmp = buckets;
		capacity *= extendRatio;
		buckets.clear();
		buckets.resize(capacity);
		size = 0;
		for (vector<Pair*> bucket : bucketsTmp) {
			for (Pair* pair : bucket) {
				put(pair->key, pair->val);
			}
		}
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
	cout << "Puting username3" << endl;
	map->put(3, "username3");
	cout << "Puting Done" << endl;
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
	map->put(102, "username102");
	map->print();
}