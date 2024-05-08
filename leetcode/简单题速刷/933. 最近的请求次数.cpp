#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    queue<int> pq;
public:
    RecentCounter() {
        pq = queue<int>();
    }
    
    int ping(int t) {
        pq.push(t);
        while(!pq.empty() && pq.front() < t - 3000 || pq.front() > t){
            pq.pop();
        }
        return pq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(){
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;
    cout << obj->ping(100) << endl;
    cout << obj->ping(3001) << endl;
    cout << obj->ping(3002) << endl;
    return 0;
}