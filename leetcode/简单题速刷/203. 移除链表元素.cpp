#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)return nullptr;
        while(head!= nullptr && head->val == val)
            head = head->next;
        if(head == nullptr)return nullptr;
        ListNode *cur = head->next;
        ListNode *pre = head;
        while(cur != nullptr){
            // cout<<"val:"<<cur->val<<endl;
            if(cur->val == val){
                pre->next = cur->next;
                cur = pre->next;
            }else{
                pre = cur;
                cur = cur->next;  
            }
        }
        return head;
    }
};

int main(){

}

/*
// 官方题解(简洁，但效率没我的好)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
*/