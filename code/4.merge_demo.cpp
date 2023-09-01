// Focus on the merge of two orderd array
#include<iostream>
using namespace std;
void view_array(int arr[], int length) {
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int num[8] = { 1,3,5,7,2,4,6,8 };
	int result[8] = { 0 };
	int leftBegin = 0;
	int leftEnd = 3;
	int rightBegin = 4;
	int rightEnd = 7;
	int index = 0;
	while (index <=7) {
		if (leftBegin > leftEnd && rightBegin > rightEnd) {
            // 不会有这种情况，因为index<=7
			break;
		}
		if (leftBegin > leftEnd && rightBegin <= rightEnd) {
            result[index] = num[rightBegin++];
		}
		if (rightBegin > rightEnd && leftBegin <= leftEnd) {
			result[index] = num[leftBegin++];
		}
		if (leftBegin <= leftEnd && rightBegin <= rightEnd) {
			if (num[leftBegin] < num[rightBegin]) {
				result[index] = num[leftBegin++];
			}
			else {
				result[index] = num[rightBegin++];
			}
		}
		index += 1;
	}
	view_array(result, 8);
}