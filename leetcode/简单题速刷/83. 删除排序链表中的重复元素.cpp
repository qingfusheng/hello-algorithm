/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head;
        while(cur->next != nullptr){
            if(cur->next->val == cur->val){
                // 此时并没有cur = cur->next，因为可能有多个重复的
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }

};