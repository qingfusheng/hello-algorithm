// 快慢指针，快指针每次走两步，慢指针每次走一步，当快指针走到终点时，慢指针刚好走到中点
#include <bits/stdc++.h>
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    ListNode* res = s.middleNode(head);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}


/*
// 用长度来做
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *cur = head;
        int length = 0;
        while(cur != nullptr){
            length++;
            cur = cur->next;
        }
        for(int i = 0; i<length/2;i++){
            head = head->next;
        }
        return head;
    }
};
*/