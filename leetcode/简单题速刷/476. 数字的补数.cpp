#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int temp = num;
        while(temp > 0){
            count += 1;
            temp >>= 1;
        }
        cout<<"cout:"<<count<<endl;
        return ~((0xFFFFFFFF >> count << count) | num);
        
    }
};

int main(){
    Solution s;
    cout << s.findComplement(5);
}

/*前导0改成1，然后取反*/