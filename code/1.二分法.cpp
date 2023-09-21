#include<iostream>
using namespace std;
int a[7] = {1,2,3,4,5,6,7};
int erfen(int left, int right, int value) {
	while (left<=right) {
		// int mid = (left+right+1)/2; 
		int mid = left+(right-left)/2;
		if (a[mid] == value) {
			return mid;
			break;
		} else if(a[mid]<value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}
int main() {
	for (int i=0; i<=8; i++) {
		cout<<erfen(0, 6, i);
		if (i<8) {
			cout<<endl;
		}
	}
	return 0;
}
