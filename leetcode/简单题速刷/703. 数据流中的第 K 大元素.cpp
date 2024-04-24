// 优先队列，topK
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto &elem: nums){
            add(elem);
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k){
            q.pop();
        }
        return q.top();
    }
};

int main() {
    	vector<int> nums = { 4, 5, 8, 2 };
	KthLargest* obj = new KthLargest(3, nums);
	cout << obj->add(3) << endl;
	cout << obj->add(5) << endl;
	cout << obj->add(10) << endl;
	cout << obj->add(9) << endl;
	cout << obj->add(4) << endl;
	return 0;
}

/*
正常流程：
class KthLargest {
private:
    int k;
    vector<int> TopKNum;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        TopKNum = vector<int>(k, INT_MIN);
        for (int i = 0; i < nums.size(); i++) {
			add(nums[i]);
		}
    }

    int add(int val) {
        if (val <= TopKNum[k - 1]) {
			return TopKNum[k - 1];
		}
		int i = 0;
        while (i < k && val <= TopKNum[i]) {
			i++;
		}
        for (int j = k - 1; j > i; j--) {
            // 将后面的元素依次往后移动，然后抛弃最后一个元素
			TopKNum[j] = TopKNum[j - 1];
		}
		TopKNum[i] = val;
		return TopKNum[k - 1];
    }
};
*/