
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        int index1 = m - 1, index2 = n - 1;
        int index = m + n - 1;
        while (index >= 0) {
            if (index1 >= 0 && index2 >= 0) {
                if (nums1[index1] > nums2[index2]) {
					nums1[index--] = nums1[index1--];
				}
                else {
					nums1[index--] = nums2[index2--];
				}
            }
            else if (index1 >= 0 && index2 < 0) {
                nums1[index--] = nums1[index1--];
            }
            else if (index1 < 0 && index2 >= 0) {
                nums1[index--] = nums2[index2--];
            }
            else {
                cout << "error" << endl;
            }
        }
    }
};


int main() {
    Solution so = Solution();
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    int m = 3, n = 3;
    so.merge(nums1,m, nums2,n);
    // view nums1
    cout << '[';
    for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << ", ";
	}
    cout << "]";
    return 0;
}
