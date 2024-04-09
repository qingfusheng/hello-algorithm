#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        unordered_set<ListNode*>MySet;
        ListNode* cur = headA;
        while(cur){
            MySet.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while(cur){
            if(MySet.count(cur) > 0){
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }
};

int main(){

}

/*
* // 让2个指针走一样的距离，消除步行差，那就一定可以一起走到相交点。
* pA走过的路径为A链+B链,pB走过的路径为B链+A链，
* pA和pB走过的长度都相同，都是A链和B链的长度之和，相当于将两条链从尾端对齐，如果相交，则会提前在相交点相遇，如果没有相交点，则会在最后相遇。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pa = headA, *pb = headB;
        while(pa!=pb){
            if(pa == nullptr){
                pa = headB;
            }else{
                pa = pa->next;
            }
            if(pb == nullptr){
                pb = headA;
            }else{
                pb = pb->next;
            }
        }
        return pa;
    }
};
*/