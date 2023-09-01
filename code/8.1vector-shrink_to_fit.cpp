#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	vector<int> v(10);
 
	for (int i = 0; i < 10; i++)
		v[i] = i;
 
	cout << "Vector size initially: " << v.size();
 
	cout << "\nVector elements are: ";
	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";
 
	v.resize(5);//size置为5,capacity不变
 
	cout << "\n\nVector size after resize(5): "
		<< v.size();
 
	cout << "\nVector elements after resize(5) are: ";
	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";    //输出后五个数是之前初始化过的数
 
	v.shrink_to_fit();//capacity置为size大小5
 
	cout << "\n\nVector size after shrink_to_fit(): "
		<< v.size();
 
	cout << "\nVector elements after shrink_to_fit() are: ";
	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";
	v.clear();
	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";
	v.shrink_to_fit();
	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";
	return 0;
}