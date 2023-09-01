#include<iostream>
using namespace std;
int logarithemic(int n){
	float temp_n = (float)n;
	int count = 0;
	while (n>1){
		n/=2;
		count+=1;
	}
	return count;
}


int logarithemic2(int n){
	float temp_n = n;
	if (n<=1){
		return 0;
	}
	return logarithemic(temp_n/2)+1;
}

int main(){
	int n = 100;
	int result = logarithemic2(n);
	cout<<result<<endl;
}
