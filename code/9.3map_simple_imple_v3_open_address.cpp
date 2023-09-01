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
class HashMapOpenAddress {
private:
	int size;
	int capacity;
	double loadThres;
	int extendRatio;
	vector<Pair *> buckets;
	Pair* removed;
public:
	HashMapOpenAddress():size(0),capacity(4),loadThres(2.0/3.0),extendRatio(2) {
		buckets = vector<Pair*>(capacity, nullptr);
		removed = new Pair(-1, "-1");
	}
	~HashMapOpenAddress() {
		buckets.clear();
		buckets.shrink_to_fit();
	}
	int hashfunc(int key) {
		return key % capacity;
	}
	// 负载因子
	double loadFactor() {
		// return static_cast<double>(size)/capacity;
		return (double)size / (double)capacity;
	}
	// 添加
	void put(int key, string value) {
		if (loadFactor() > loadThres) {
			extend();
		}
		int index = hashfunc(key);
		for (int i = 0; i < capacity; i++) {
			int j = (index + i) % capacity;
			if (buckets[j] == nullptr || buckets[j] == removed) {
				buckets[j] = new Pair(key, value);
				size++;
				return;
			}
			if (buckets[j]->key == key) {
				buckets[j]->val = value;
				return;
			}
		}
	}
	// 删除
	void remove(int key) {
		int index = hashfunc(key);
		for (int i = 0; i < capacity; i++) {
			int j = (i + index) % capacity;
			if (buckets[j]->key == key) {
				delete buckets[j];
				buckets[j] = removed;
				size--;
				return;
			}
			// 遇到空桶直接返回
			if (buckets[j] == nullptr)
				return;
		}
	}
	// 查询
	string get(int key) {
		int index = hashfunc(key);
		for (int i = 0; i < capacity; i++) {
			int j = (i + index) % capacity;
			if (buckets[j]->key == key)
				return buckets[j]->val;
			if (buckets[j] == nullptr)
				return nullptr;
		}
		return nullptr;
	}
	// 获取所有的键值对
	vector<Pair *> pairSet() {
		vector<Pair*> pairSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr && pair != removed) {
				pairSet.push_back(pair);
			}
		}
		return pairSet;
	}
	// 获取所有的键
	vector<int> keySet() {
		vector<int> keySet;
		for (Pair* pair : buckets) {
			if (pair != nullptr && pair != removed) {
				keySet.push_back(pair->key);
			}
		}
		return keySet;
	}
	// 获取所有的值
	vector<string> valueSet() {
		vector<string> valueSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr && pair != removed) {
				valueSet.push_back(pair->val);
			}
		}
		return valueSet;
	}

	void extend() {
		cout << "对当前hashmap进行extend\n";
		vector<Pair*> bucketsTmp = buckets;
		capacity *= extendRatio;
		buckets.clear();
		buckets.resize(capacity);
		size = 0;
		for (Pair* pair : bucketsTmp) {
			if (pair != nullptr && pair != removed) {
				// 在这里不需要插入nullptr和removed
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
	HashMapOpenAddress*map = new HashMapOpenAddress();
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