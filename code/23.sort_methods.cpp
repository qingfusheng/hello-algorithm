#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#define leftChild(i) 2 * i + 1
#define rightChild(i) 2 * i + 2
#define parent(i) (i - 1)/2
using namespace std;
void view_vector(vector<int>& demo) {
	for (int value: demo) {
		cout << value << " ";
	}
	cout << endl;
	return;
}
void choose_sort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		int k = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[k])
				k = j;
		}
		swap(nums[k], nums[i]);
	}
	return;
}
void BubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i; j < nums.size(); j++) {
			if (nums[i] > nums[j])
				swap(nums[i], nums[j]);
			else
				continue;
		}
	}
	return;
}
void InsertSort(vector<int>& nums) {
	// （从小到大）插入排序的含义是：将第i+1个元素插入到前i个元素集合中，将待插入元素设为基准base值，从第i个元素开始依次往前，与base比较，若遇到
	// 大值则continue往前，遇到小值（index为j）则退出，则插入位置为j+1，且插入位置到末端的值集体后移。
	for (int i = 1; i < nums.size(); i++) {
		int base = nums[i], j = i - 1;
		while (j >= 0 && nums[j] > base) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = base;
	}
}

// 快速排序（标准基准值）
int partition_stand(vector<int> &nums, int left, int right) {
	// 以nums[left]作为基准数
	int i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] >= nums[left])
			j--;
		while (i < j && nums[i] <= nums[left])
			i++;
		swap(nums[i], nums[j]);
	}
	swap(nums[i], nums[left]);
	return i;
}
void QuickSort_Stand(vector<int>& nums, int left, int right) {
	cout << "left:" << left << ",right:" << right << endl;
	cout << "QuickSort:";
	view_vector(nums);
	if (left >= right)
		return;
	int pivot = partition_stand(nums, left, right);
	QuickSort_Stand(nums, left, pivot - 1);
	QuickSort_Stand(nums, pivot + 1, right);
}
// 快速排序（基准数优化）
int medianThree(vector<int>& nums, int left, int mid, int right) {
	
	/*if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
		return left;
	else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
		return mid;
	else
		return right;*/
	if (nums[left] <= nums[mid] && nums[left] <= nums[right])
		return left;
	else if (nums[mid] <= nums[left] && nums[mid] <= nums[right])
		return mid;
	else
		return right;
}
int partition_median(vector<int>& nums, int left, int right) {
	// 基准值为medianThree
	int mid = medianThree(nums, left, (left + right) / 2, right);
	swap(nums[mid], nums[left]);
	int i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] >= nums[left])
			j--;
		while (i < j && nums[i] <= nums[left])
			i++;
		swap(nums[i], nums[j]);
	}
	swap(nums[left], nums[i]);
	return i;
}
void QuickSort_Three(vector<int>& nums, int left, int right) {
	cout << "left:" << left << ",right:" << right << endl;
	cout << "QuickSort:";
	view_vector(nums);
	if (left >= right)
		return;
	int pivot = partition_median(nums, left, right);
	QuickSort_Three(nums, left, pivot - 1);
	QuickSort_Three(nums, pivot + 1, right);
}
void QuickSort_TailRecure(vector<int>& nums, int left, int right) {
	// 子数组长度为 1 时终止
	while (left < right) {
		// 哨兵划分操作
		int pivot = partition_stand(nums, left, right);
		// 对两个子数组中较短的那个执行快排
		if (pivot - left < right - pivot) {
			QuickSort_TailRecure(nums, left, pivot - 1); // 递归排序左子数组
			left = pivot + 1;                 // 剩余未排序区间为 [pivot + 1, right]
		}
		else {
			QuickSort_TailRecure(nums, pivot + 1, right); // 递归排序右子数组
			right = pivot - 1;                 // 剩余未排序区间为 [left, pivot - 1]
		}
	}
}
// Attention：左闭右闭
void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int> tmp(nums.begin() + left, nums.begin() + right + 1);
	int leftBegin = left - left, leftEnd = mid - left;
	int rightBegin = mid - left + 1, rightEnd = right - left;
	int i = leftBegin, j = rightBegin;
	for (int k = left; k <= right; k++) {
		if (i > leftEnd && j <= rightEnd) {
			nums[k] = tmp[j++];
		}
		else if (i <= leftEnd && j > rightEnd)
			nums[k] = tmp[i++];
		else if (i <= leftEnd && j <= rightEnd)
			if (tmp[i] <= tmp[j])
				nums[k] = tmp[i++];
			else
				nums[k] = tmp[j++];
	}
	return;
}
void MergeSort(vector<int>& nums, int left, int right) {
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}
void siftDown(vector<int>& nums, int n, int i) {
	//heap的特征是parent>child
	// 从顶至底堆化，从i
	while (true) {
		int l = leftChild(i), r = rightChild(i), ma = i;
		if (l < n && nums[l] > nums[ma])
			ma = l;
		if (r < n && nums[r] > nums[ma])
			ma = r;
		if (ma == i)
			break;
		swap(nums[i], nums[ma]);
		i = ma;
	}
	return;
}
void HeapSort(vector<int>& nums) {
	for (int i = parent(nums.size() - 1); i >= 0; i--) {
		siftDown(nums, nums.size(), i);
	}
	for (int i = nums.size() - 1; i > 0; --i) {
		// 交换根节点与最右叶节点（即交换首元素与尾元素）
		swap(nums[0], nums[i]);
		// 以根节点为起点，从顶至底进行堆化
		siftDown(nums, i, 0);
	}
}
/* 桶排序 */
// 这里的桶排序针对的是[0,1)的浮点数
void bucketSort(vector<float>& nums) {
	// 初始化 k = n/2 个桶，预期向每个桶分配 2 个元素
	int k = nums.size() / 2;
	vector<vector<float>> buckets(k);
	// 1. 将数组元素分配到各个桶中
	for (float num : nums) {
		// 输入数据范围 [0, 1)，使用 num * k 映射到索引范围 [0, k-1]
		int i = num * k;
		// 将 num 添加进桶 bucket_idx
		buckets[i].push_back(num);
	}
	// 2. 对各个桶执行排序
	for (vector<float>& bucket : buckets) {
		// 使用内置排序函数，也可以替换成其他排序算法
		sort(bucket.begin(), bucket.end());
	}
	// 3. 遍历桶合并结果
	int i = 0;
	for (vector<float>& bucket : buckets) {
		for (float num : bucket) {
			nums[i++] = num;
		}
	}
}
// 计数排序，也是用空间换时间的排序方法，适用于数据量大且数据范围小的情况（正整数
void countingSortNaive(vector<int> &nums) {
	int m = 0;
	for (int num : nums)
		m = max(m, num);
	vector<int> count_list(m + 1, 0);
	for (int num : nums)
		count_list[num]++;
	int index = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j < count_list[i]; j++)
			nums[index++] = i;
	}
}
/* 计数排序 */
// 完整实现，可排序对象，并且是稳定排序
// 这个排序相比于Naive的区别是，本排序从首先使用前缀和的方式构建counter，然后对nums从后到前进行遍历（以保持其稳定性），
// 通过counter就可以确定每个数字对应在res中的位置
void countingSort(vector<int>& nums) {
	// 1. 统计数组最大元素 m
	int m = 0;
	for (int num : nums) {
		m = max(m, num);
	}
	// 2. 统计各数字的出现次数
	// counter[num] 代表 num 的出现次数
	vector<int> counter(m + 1, 0);
	for (int num : nums) {
		counter[num]++;
	}
	// 3. 求 counter 的前缀和，将“出现次数”转换为“尾索引”
	// 即 counter[num]-1 是 num 在 res 中最后一次出现的索引
	for (int i = 0; i < m; i++) {
		counter[i + 1] += counter[i];
	}
	cout << "Counter:" << endl;
	view_vector(counter);
	// 4. 倒序遍历 nums ，将各元素填入结果数组 res
	// 初始化数组 res 用于记录结果
	int n = nums.size();
	vector<int> res(n);
	for (int i = n - 1; i >= 0; i--) {
		int num = nums[i];
		res[counter[num] - 1] = num; // 将 num 放置到对应索引处
		counter[num]--;              // 令前缀和自减 1 ，得到下次放置 num 的索引
	}
	// 使用结果数组 res 覆盖原数组 nums
	nums = res;
}


int main() {
	vector<int> nums = { 5,4,7,1,9,2,8,3,6,2,1,9,4 };
	//view_vector(nums);
	//choose_sort(nums);
	//BubbleSort(nums);
	//QuickSort_Stand(nums, 0, nums.size() - 1);
	//QuickSort_Three(nums, 0, nums.size() - 1);
	//QuickSort_TailRecure(nums, 0, nums.size() - 1);
	//MergeSort(nums, 0, nums.size() - 1);
	//HeapSort(nums);
	countingSort(nums);
	view_vector(nums);
}