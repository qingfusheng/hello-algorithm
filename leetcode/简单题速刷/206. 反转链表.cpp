#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 反转链表，还是需要对链表的基本操作熟练，这里用了三个指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next; // Temporarily store the next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev one step forward
            curr = next; // Move curr one step forward
        }
        return prev; // At the end of the loop, prev will be the new head
    }
};
int main(){

}