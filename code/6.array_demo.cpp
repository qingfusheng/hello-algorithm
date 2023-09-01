/*
静态存储区：一块固定内存区域，在整个程序生命周期内都存在，直到程序结束。
- 全局变量
- 静态变量（static，包括静态全局变量和静态局部变量）
- 常量（const，包括字符串常量）
*/

/*
栈区（Stack）：栈区是一种自动分配和管理内存的区域，栈区的大小有限，通常较小。
变量在函数被调用时在栈上分配内存，在函数返回时自动释放内存。
用途：适用于存储相对较小的局部变量和函数调用的返回地址等。
*/

/*
堆区（Heap）：堆区是用于动态分配内存的区域。它的大小比栈区大得多，也不受限制。
变量在堆上分配内存，并且在不再需要时必须显式释放（否则可能导致内存泄漏）。
用途：适用于需要在程序运行时动态分配内存的情况，例如动态数组和复杂数据结构。
*/

#include<iostream>
#include<vector>
using namespace std;
// 全局数据区（静态存储区）,在程序开始时进行静态初始化
int a[10];

void view_array2(int arr[], int length) {
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	// main 函数中声明的局部变量，它存储在栈区。它的初始化是在运行时进行
	int b[10] = { 0 };
	view_array2(b, 10);
	//delete b;  // b本来就不是动态分配的，并不需要删除。
	
	int n = 10;
	// 指针 c 存储在栈区，而它所指向的动态分配数组存储在堆区。
	int* c = new int[10] {0};
	view_array2(c, 10);
	delete[]c;

	// 创建一个n*n的二维数组
	int** f = new int* [n];
	for (int i = 0; i < n; i++)
		f[i] = new int[n] {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << f[i][j] << ", ";
		cout << endl;
	}
	
}